#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1) {
            if (!(*first1 == *first2)) 
                return false;
            ++first1; ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1){
            if (first2==last2 || *first2<*first1)
                return false;
            else if (*first1<*first2)
                return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template <class T1, class T2>
    struct pair
    {
        public:
            pair() : first(), second() {};
       
            pair(const T1 &a, T2 &b) : first(a), second(b) {};

            pair(const T1& a, const T2& b) : first(a), second(b) {};
            
            pair(const pair<T1, T2>& copy) : first(copy.first), second(copy.second) {};

            template <typename U, typename V>
            pair(const pair<U, V>& copy) : first(copy.first), second(copy.second) {};

            ~pair() {};
        
            pair& operator=(const pair& assign)
            {
                if (this != &assign)
                {
                    first = assign.first;
                    second = assign.second;
                }
                return (*this);
            }
            
            T1 first;
            T2 second;
            
    };

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return pair<T1, T2>(x, y);
    };

    template <class arg1, class arg2, class result>
	struct binary_function
	{
		typedef	arg1       first_argument_type;
		typedef	arg2       second_argument_type;
		typedef	result     result_type;
	};

    template <class T>
    struct less : binary_function <T ,T ,bool>
    {   
        bool operator() (const T &x, const T &y) const { return x < y; }    
    };
}

#endif