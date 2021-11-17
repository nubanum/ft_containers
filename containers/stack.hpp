#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include "vector.hpp"

namespace ft
{
    template<class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;

        public:
            explicit stack(const container_type &ctnr = container_type())
            : _container(ctnr) {}
    
            bool                empty() const { return _container.empty(); }
            size_type           size() const { return _container.size(); }
            value_type          &top() { return _container.back(); }
            const value_type    &top() const { return _container.back(); }
            void                push(const value_type &val) { return _container.push_back(val); }
            void                pop() { return _container.pop_back(); }

            template <class Tn, class ContainerN>
			friend bool operator== (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator!= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
			
			template <class Tn, class ContainerN>
			friend bool operator< (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator<= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator> (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator>= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

        protected:
            container_type      _container;
    };

    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._container == rhs._container);
    }

    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._container != rhs._container);
    }
	
    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._container < rhs._container);
    }

    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._container <= rhs._container);
    }

    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._container > rhs._container);
    }

    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._container >= rhs._container);
    }
}

#endif