// # ifndef VECTOR_
// # define VECTOR_
# include <exception>
# include "iterator.hpp"

namespace ft {

	template<class Tx, class Ax>
	class vector_val {
		protected:
			vector_val (Ax a1 = Ax()) : Alval(a1) {}
			typedef typename Ax::template rebind<Tx>::other Alty;
			Alty Alval;
	};

	template < class T, class A = std::allocator<T> >
	class vector {

		public:
			typedef				vector < T, A >		MyVector;
			typedef 			vector_val < T, A > MyBase;
			typedef typename 	MyBase::Alty 		Ax;
			typedef 			A					allocator_type; // синоним для шаблонного параметра А
			typedef typename	Ax::size_type		size_type;
			typedef typename	Ax::difference_type	difference_type;
			typedef typename	Ax::pointer			Tptr;
			typedef typename	Ax::const_pointer	Ctptr;
			typedef				Tptr				pointer;
			typedef				Ctptr				const_pointer;
			typedef typename	Ax::reference		reference;
			typedef typename	Ax::const_reference	const_reference;
			typedef typename	Ax::value_type		value_type;
	
			typedef PtrIt<value_type, difference_type, Tptr, reference, Tptr, reference>	iterator;
			typedef PtrIt<value_type, difference_type, Ctptr, const_reference, Tptr, reference> const_iterator;
			typedef std::reverse_iterator<iterator> reverse_iterator;
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

			// explicit vector(const A& a1) : MyBase(a1) { Buy(0); }
			
			// vector() : MyBase() { Buy(0); }
			// vector(size_type n) : MyBase() {
			// 	if (Buy(n))
			// 		Last = Ufill(First, n, T());
			// }
			// vector(size_type n, const T& x) : MyBase() {
			// 	if (Buy(n))
			// 		Last = Ufill(First, n, x);
			// }
			// vector(size_type n, const T& x, const Ax& a1) : MyBase(a1) {
			// 	if (Buy(n))
			// 		Last = Ufill(First, n, x);
			// }
			// vector(const vector& x) : MyBase(x.Alval) {
			// 	if (Buy(x.size()))
			// 		Last = Ucopy(x.begin(), x.end(), First);
			// }

			// Constructors by Iterators∂
			// template < class It >
			// vector(It F, It L) : MyBase() { Construct( F, L, Iter_cat(F) ); }
			// template < class It >
			// vector (It F, It L, const A& a1) : MyBase(a1) { Construct( F, L, Iter_cat(F) ); }
			// vector& operator= (const vector& x) {
			// 	if (this == &x)
			// 		;
			// 	else if (x.size() == 0)
			// 		Clear();
			// 	else if (x.size() <= size()) {
			// 		pointer Q = copy(x.begin(), x.end(), First);
			// 		Destroy(Q, Last);
			// 		Last = First + x.size();
			// 	}
			// 	else if (x.size() <= capacity()) {
			// 		const_iterator S = x.begin() + size();
			// 		copy(x.begin(), S, First);
			// 		Last = Ucopy(S, x.end(), Last);
			// 	}
			// 	else {
			// 		Destroy(First, Last);
			// 		MyBase::Alval.dealocate(First, End - First);
			// 		if (Buy(x.size()))
			// 			Last = Ucopy(x.begin(), x.end(), First);
			// 	}
			// 	return *this;
			// }
			// ~vector() { Clear(); }
			// template <class It>
			// void Construct( It F, It L, input_iterator_tag ) {
			// 	size_type N = (size_type)F;
			// 	if (Buy(N))
			// 		Last = Ufill(First, N,(T)L);
			// }
			// template <class It>
			// void Construct( It F, It L, std::input_iterator_tag ) { Buy(0); insert(begin(), F, L); }

			// iterator begin() { return (iterator(First)); }
			// const_iterator begin() const { return (const_iterator(First)); }
			// iterator end() { return (iterator(Last)); }
			// const_iterator end() const { return (const_iterator(Last)); }
			// reverse_iterator rbegin() { return (reverse_iterator(end())); } 
			// const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
			// reverse_iterator rend() { return (reverse_iterator(begin())); } 
			// const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); } 
			iterator erase(iterator it) { // возвращает итератор, указывающий на элемент, следующий за удаленным / удаление n элементов вызывает n деструкторов
				copy(it + 1, end(), it);
				Destroy(Last - 1, Last);
				--Last;
				return(it);
			}
			iterator erase(iterator F, iterator L) { // возвращает итератор, указывающий на элемент, следующий за удаленным / не вызывает exception
				if (F != L) {
					pointer ptr = copy(L, end(), F.base());
					Destroy(ptr, Last);
					Last = ptr;
				}
				return(F);
			}

			iterator insert(iterator it, const T& x) { // вставляет значение перед элементом it
				size_type off = size() == 0 ? 0 : it - begin();
				insert(it, (size_type)1, x);
				return (begin() + off);
			}
			void insert(iterator It, size_type M, const T& x) {
				T Tx = x;
				size_type N = capacity();
				if (M == 0)
					;
				else if (max_size() - size() < M) {	Xlen(); }
				else if (N < size() + M) {
					N = max_size() - N / 2 < N ? 0 : N + N / 2;
					if (N < size() + M)
						N = size() + M;
					pointer S = MyBase::Alval.allocate(N, (void*)0);
					pointer Q;
					try {
						Q = Ucopy(begin(), It, S);
						Q = Ufill(Q, M, Tx);
						Ucopy(It, end(), Q);
					}
					catch(const std::exception& e) {
						std::cerr << e.what() << std::endl;
						Destroy(S, Q);
						MyBase::Alval.deallocate(S, N);
						throw;
					}
					if (First != 0) {
						Destroy(First, Last);
						MyBase::Alval.deallocate(First, End - First);
					}
					End = S + N;
					Last = S + size() + M;
					First = S;
				}
				else if ((size_type) (end() - It) < M) {
					Ucopy(It, end(), It.base() + M);
					try { Ufill(Last, M - (end() - It), Tx); }
					catch(const std::exception& e) {
						std::cerr << e.what() << std::endl;
						Destroy(It.base() + M, Last + M);
						throw;
					}
					Last += M;
					fill(It, end() - M, Tx);
				}
				else {
					iterator OEnd = end();
					Last = Ucopy(OEnd - M, OEnd, Last);
					copy_backward(It, OEnd - M, OEnd);
					fill(It, It + M, Tx);
				}
			}
			template < class It >
			void insert(iterator pos, It F, It L, input_iterator_tag) { insert(pos, F, L, Iter_cat(F)); }

			template < class It >
			void insert(iterator pos, It F, It L, std::input_iterator_tag) {
				for ( ; F != L; ++F, ++pos) {
					pos = insert(pos, *F); }
			}

			template < class It >
			void insert(iterator pos, It F, It L, std::forward_iterator_tag) {
				size_type m = 0;
				Distance(F, L, m);
				size_type n = capacity();
				if (m == 0)
					;
				else if (max_size() - size() < m)
					Xlen();
				else if(n < size() + m) {
					n = max_size() - n / 2 < n ? 0 : n + n / 2;
					if (n < size() + m)
						n = size() + m;
					pointer S = MyBase::Alval.allocate(n, (void*)0);
					pointer Q;
					try {
						Q = Ucopy(begin(), pos, S);
						Q = Ucopy(F, L, Q);
						Ucopy(pos, end(), Q);
					}
					catch(const std::exception& e) {
						std::cerr << e.what() << std::endl;
						Destroy(S, Q);
						MyBase::Alval.deallocate(S, n);
						throw;
					}
					if (First != 0) {
						Destroy(First, Last);
						MyBase::Alval.deallocate(First, End - First); }
					End = S + n;
					Last = S + size() + m;
					First = S;
					}
				else if ((size_type)(end() - pos) < m) {
					Ucopy(pos, end(), pos.base() + m);
					It Mid = F;
					advance(Mid, end() - pos);
					try {
						Ucopy(Mid, L, Last);
					}
					catch(const std::exception& e) {
						std::cerr << e.what() << std::endl;
						Destroy(pos.base() + m, Last + m);
						throw;
					}
					Last += m;
					copy(F, Mid, pos);
				}
				else if (0 < m) {
					iterator Oend = end();
					Last = Ucopy(Oend - m, Oend, Last);
					copy_backward(pos, Oend - m, Oend);
					copy(F, L, pos);
				}
			}

			// если n > max_size(), то выводим std::length_error, в противном случае capacity() == n
			void reserve(size_type n) { 
				if (max_size() < n)
					Xlen();
				else if (capacity() < n) {
					pointer Q = MyBase::Alval.allocate(n, (void *)0);
					try {
						Ucopy(begin(), end(), Q);
					}
					catch(const std::exception& e) {
						std::cerr << e.what() << std::endl;
						MyBase::Alval.deallocate(Q, n);
						throw;
					}
					if (First != 0) {
						Destroy(First, Last);
						MyBase::Alval.deallocate(First, End - First);
					}
					End = Q + n;
					Last = Q + size();
					First = Q;
				}
			}
			size_type capacity() const { return (First == 0 ? 0 : End - First); } // возвращает размер памяти, которая выделена в настоящий момент для вектора, >= size
			
			void resize(size_type n) { resize(n, T()); } // далее size == n, добавляет элементы Т()
			void resize(size_type n, T x) { // добавляет элементы со значением х / чтобы укоротить, обе вызывают erase(begin() + n, end())
				if (size() < n)
					insert(end(), n - size(), x);
				else if (n < size())
					erase(begin() + n, end());
			}
			size_type max_size() const { return (MyBase::Alval.max_size()); } // возвращает размер самой длинной последовательности, которую может контролировать Объект
			size_type size() const { return (First == 0 ? 0 : Last - First); } // возвращает длину последовательности
			
			bool empty() const { return (size() == 0); } // возвращает true, если последовательность пуста
			void push_back(const T& x) { insert(end(), x); } // последовательност ьне должна быть пустой
			void pop_back() { erase(end() - 1); } // удаляет последний элемент, который не должен быть пустой, не вызывает exception / последовательност ьне должна быть пустой
			template < class It >
				void assign(It F, It L) { assign(F, L, Iter_cat(F)); }
			template < class It >
				void assign(It F, It L, input_iterator_tag) { assign((size_type)F, (T)L); }
			template < class It >
				void assign(It F, It L, std::input_iterator_tag) { erase(begin(), end()); insert(begin(), F, L); }
			
			void assign(size_type n, const T& x) { T Tx = x; erase(begin(), end()); insert(begin(), n, Tx); } // выделить память под n элементов и заполнить их x-значениями 
			void clear() { erase(begin(), end()); } // удаление элементов, но не уменьшение памяти / высвободить всю память: vector.swap(vector<T, A>());
			void swap( vector& x ) { // не вызывает exceptions, если не: get_allocator() == x.get_allocator(), то вызывается множество конструкторов
				if (MyBase::Alval == x.Alval) {
					std::swap(First, x.First);
					std::swap(Last, x.Last);
					std::swap(End, x.End);
				}
				else { vector Ts = *this; *this = x, x = Ts; }
			}

			Ax get_allocator() const { return (MyBase::Alval); } // возвращает копию хранящегося объекта-распределителя // get_allocator() == x.get_allocator()()?
			
			reference at(size_type pos) { // возвращает ссылку на аргумент, если вне диапазона -> exception
				if (size() <= pos)
					Xran();
				return ((*begin() + pos));
			}
			const_reference at(size_type pos) const {
				if (size() <= pos)
					Xran();
				return ((*begin() + pos));
			}
			
			reference operator[](size_type pos) { return (*(begin() + pos)); } // если pos находится вне границ, поведение не определено
			const_reference operator[](size_type pos) const { return (*(begin() + pos)); }
			
			reference front() { return (*begin()); } // возвращает ссылку на первый элемент, должен быть не пустой
			const_reference front() const { return (*begin()); } // возвращает const ссылку на первый элемент, должен быть не пустой
			
			reference back() { return (*(end() - 1)); } // возвращает ссылку на последний элемент, должен быть не пустой
			const_reference back() const { return (*(end() - 1)); } // возвращает const ссылку на последний элемент, должен быть не пустой

			bool Eq(const vector& x) const { return (size() == x.size() && equal(begin(), end(), x.begin())); }
			bool Lt(const vector& x) const { return (lexicographical_compare(begin(), end(), x.begin(), x.end())); }

		protected:
			
			bool Buy(size_type n) {
				First = 0, Last = 0, End = 0;
				if (n == 0)
					return false;
				else {
					First = MyBase::Alval.allocate(n, (void*)0);
					Last = First;
					End = First + n;
					return true;
				}
			}
			
			void Clear() {
				if (First != 0) {
					Destroy(First, Last);
					MyBase::Alval.deallocate(First, End - First);
				}
				First = 0, Last = 0, End = 0;
			}
			
			void Destroy (pointer F, pointer L) {
				for ( ; F != L; ++F) {
					MyBase::Alval.destroy(F);
				}
			}

			template < class It >
			pointer	Ucopy (It F, It L, pointer Q) {
				pointer Qs = Q;
				try {
					for ( ; F != L; ++Q, ++F) {
						MyBase::Alval.construct(Q, *F);
					}
				}
				catch(const std::exception& e) {
					std::cerr << e.what() << std::endl;
					Destroy(Qs, Q);
					throw;
				}
				return Q;
			}

			pointer Ufill(pointer Q, size_type N, const T& X) {
				pointer Qs = Q;
				try {
					for ( ; 0 < N; --N, ++Q) {
						MyBase::Alval.construct(Q, X);
					}
				}
				catch(const std::exception& e) {
					std::cerr << e.what() << std::endl;
					Destroy(Qs, Q);
					throw;
				}
				return Q;
			}

			void Xlen() const { throw std::length_error("vector<T> too long"); }
			void Xran() const { throw std::out_of_range("vector<T> subscript"); }
			pointer First, Last, End;
	};
	
	template < class It >
	bool lexicographical_compare (It first1, It last1, It first2, It last2) {
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1 ) { return false; }
			else if (*first1 < *first2) { return true; }
			++first1;
			++first2;
		}
	}

	// template < class Ty, class Ay >
	// bool operator==( const vector <Ty, Ay>& lhs, const vector <Ty, Ay>& rhs ) { return (lhs.Eq(rhs)); }
	// template < class Ty, class Ay >
	// bool operator!=( const vector <Ty, Ay>& lhs, const vector <Ty, Ay>& rhs ) { return !(lhs == rhs); }
	// template < class Ty, class Ay >
	// bool operator>=( const vector <Ty, Ay>& lhs, const vector <Ty, Ay>& rhs ) { return !(lhs < rhs); }
	// template < class Ty, class Ay > 
	// bool operator<=( const vector <Ty, Ay>& lhs, const vector <Ty, Ay>& rhs ) { return !(rhs < lhs); }
	// template < class Ty, class Ay >
	// bool operator>( const vector <Ty, Ay>& lhs, const vector <Ty, Ay>& rhs ) { return (rhs < lhs); }
	// template < class Ty, class Ay >
	// bool operator<( const vector <Ty, Ay>& lhs, const vector <Ty, Ay>& rhs ) { return (lhs.Lt(rhs)); }
	// template < class Ty, class Ay >
	// void swap( const vector <Ty, Ay>& lhs, const vector <Ty, Ay>& rhs ) { lhs.swap(rhs); }
}
// #endif