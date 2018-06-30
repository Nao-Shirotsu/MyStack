// ---Fixed-length stack with template---
// Covers user-defined type
// Instantiating as following:
// Stack<TYPENAME> VARIABLENAME(SIZE);

namespace Shi62{

template <class T>
class Stack{ 
public:
    // Constructor, which is given maximum size
    Stack( size_t max_size ){
        size = max_size;
        bottom = top = new T[size + 1];
    }

    // Check whether data are being stacked or empty
    bool IsEmpty(){ 
        return top == bottom;
    }

    // Check whether data are full or not
    bool IsFull(){
        return top == bottom + size;
    }

    // Returns size
    size_t GetSize(){
        return size;
    }
    // Returns number of stacked data
    size_t GetNumOfData(){
        size_t num = 0;
        for( auto itr = bottom; itr <= top; ++itr ){
            ++num;
        }
        return num;
    }

    // Add a T-type element to the top of stack
    void Push( T x ){
        if( IsFull() ){
            std::cerr << "Stack Overflow! the pushed data was dumped\n";
        }else{
            ++top;
            *top = x;
        }
    }

    // Take an element out from the top of stack
    T Pop(){
        if( IsEmpty() ){
            std::cerr << "Stack Underflow!\n";
        }else{
            --top;
        }
        return *(top + 1);
    }

    // Print NumOfElems and all elements out from top to base
    void Print(){
        if( !IsEmpty() ){
            std::cout << "[Stuck]\n" << *top << "  <- top\n";
            for( auto itr = top - 1; itr >= bottom; --itr ){
                std::cout << *itr ;
                std::cout << "\n";
            }
            std::cout << std::endl;
        }else{
            std::cout << "Stuck: Empty" << "\n\n";
        }
    }

private:
    T* top;
    T* bottom;
    size_t size;
};

}