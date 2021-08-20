/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) make sure it compiles & runs without errors.
 
 7) use your knowledge of casting to remove any conversion warnings. 

 8) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 9) click the [run] button.  Clear up any errors or warnings as best you can.

 */

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^4 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
good to go!




*/
struct A {};
struct HeapA
{
    HeapA() : myA(new A) { }
    ~HeapA(){ delete myA;  } 
    A* myA = nullptr;
};


#include <iostream>

struct FloatType;
struct DoubleType;
struct IntType;

struct FloatType
{
    float* value = nullptr;

    FloatType(float _value) : value(new float(_value))
    {
    }
    ~FloatType()
    {
        delete value;
    }

    FloatType& add( float operand )
    {
        if (value != nullptr)    
            *value += operand;

        return *this;
    }

    FloatType& add(const FloatType& ft);
    FloatType& add(const DoubleType& ft);
    FloatType& add(const IntType& ft);

    FloatType& subtract( float operand )
    {
        if (value != nullptr)   
            *value -= operand;

        return *this;
    }

    FloatType& subtract(const FloatType& ft);
    FloatType& subtract(const DoubleType& ft);
    FloatType& subtract(const IntType& ft);

    FloatType& multiply( float operand )
    {
        if (value != nullptr) 
            *value *= operand;

        return *this;
    }

    FloatType& multiply(const FloatType& ft);
    FloatType& multiply(const DoubleType& ft);
    FloatType& multiply(const IntType& ft);

    FloatType& divide( float operand )
    {
        if (operand == 0.f)
            std::cout << "warning: floating point division by zero!" << std::endl; 

        if (value != nullptr)
            *value /= operand;

        return *this;
    }

    FloatType& divide(const FloatType& ft);
    FloatType& divide(const DoubleType& ft);
    FloatType& divide(const IntType& ft);
};

struct DoubleType
{
    double* value = nullptr;

    DoubleType(double _value) : value(new double(_value))
    {
        
    }
    ~DoubleType()
    {
        delete value;
    }

    DoubleType& add( double operand )
    {
        if (value != nullptr)    
            *value += operand;

        return *this;
    }

    DoubleType& add(const FloatType& ft);
    DoubleType& add(const DoubleType& ft);
    DoubleType& add(const IntType& ft);

    DoubleType& subtract( double operand )
    {
        if (value != nullptr)   
            *value -= operand;

        return *this;
    }

    DoubleType& subtract(const FloatType& ft);
    DoubleType& subtract(const DoubleType& ft);
    DoubleType& subtract(const IntType& ft);

    DoubleType& multiply( double operand )
    {
        if (value != nullptr) 
            *value *= operand;

        return *this;
    }

    DoubleType& multiply(const FloatType& ft);
    DoubleType& multiply(const DoubleType& ft);
    DoubleType& multiply(const IntType& ft);
    

    DoubleType& divide( double operand )
    {
        if (operand == 0.0)
            std::cout << "warning: floating point division by zero!" << std::endl;

        if (value != nullptr)
            *value /= operand;

        return *this;
    }

    DoubleType& divide(const FloatType& ft);
    DoubleType& divide(const DoubleType& ft);
    DoubleType& divide(const IntType& ft);
};

struct IntType
{
    int* value = nullptr;

    IntType(int _value) : value(new int(_value))
    {
    
    }
    ~IntType()
    {
        delete value;
    }

    IntType& add( int operand )
    {
        if (value != nullptr)    
            *value += operand;

        return *this;
    }

    IntType& add(const FloatType& ft);
    IntType& add(const DoubleType& ft);
    IntType& add(const IntType& ft);

    IntType& subtract( int operand )
    {
        if (value != nullptr)   
            *value -= operand;

        return *this;
    }

    IntType& subtract(const FloatType& ft);
    IntType& subtract(const DoubleType& ft);
    IntType& subtract(const IntType& ft);

    IntType& multiply( int operand )
    {
        if (value != nullptr) 
            *value *= operand;

        return *this;
    }

    IntType& multiply(const FloatType& ft);
    IntType& multiply(const DoubleType& ft);
    IntType& multiply(const IntType& ft);
    
    IntType& divide( int operand )
    {
        if (operand != 0)
        {
            *value /= operand;    
        }
        else
        {
            std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl ;
        }
        return *this;
    }

    IntType& divide(const FloatType& ft);
    IntType& divide(const DoubleType& ft);
    IntType& divide(const IntType& ft);
};

FloatType& FloatType::add(const FloatType& ft)
{
    return add(*ft.value);
}

FloatType& FloatType::add(const DoubleType& ft)
{
    return add(*ft.value);
}

FloatType& FloatType::add(const IntType& ft)
{
    return add(*ft.value);
}

FloatType& FloatType::subtract(const FloatType& ft)
{
    return subtract(*ft.value);
}

FloatType& FloatType::subtract(const DoubleType& ft)
{
    return subtract(*ft.value);
}

FloatType& FloatType::subtract(const IntType& ft)
{
    return subtract(*ft.value);
}

FloatType& FloatType::multiply(const FloatType& ft)
{
    return multiply(*ft.value);
}

FloatType& FloatType::multiply(const DoubleType& ft)
{
    return multiply(*ft.value);
}

FloatType& FloatType::multiply(const IntType& ft)
{
    return multiply(*ft.value);
}

FloatType& FloatType::divide(const FloatType& ft)
{
    return divide(*ft.value);
}

FloatType& FloatType::divide(const DoubleType& ft)
{
    return divide(*ft.value);
}

FloatType& FloatType::divide(const IntType& ft)
{
    return divide(*ft.value);
}

DoubleType& DoubleType::add(const FloatType& ft)
{
    return add(*ft.value);
}

DoubleType& DoubleType::add(const DoubleType& ft)
{
    return add(*ft.value);
}

DoubleType& DoubleType::add(const IntType& ft)
{
    return add(*ft.value);
}

DoubleType& DoubleType::subtract(const FloatType& ft)
{
    return subtract(*ft.value);
}

DoubleType& DoubleType::subtract(const DoubleType& ft)
{
    return subtract(*ft.value);
}

DoubleType& DoubleType::subtract(const IntType& ft)
{
    return subtract(*ft.value);
}

DoubleType& DoubleType::multiply(const FloatType& ft)
{
    return multiply(*ft.value);
}

DoubleType& DoubleType::multiply(const DoubleType& ft)
{
    return multiply(*ft.value);
}

DoubleType& DoubleType::multiply(const IntType& ft)
{
    return multiply(*ft.value);
}

DoubleType& DoubleType::divide(const FloatType& ft)
{
    return divide(*ft.value);
}

DoubleType& DoubleType::divide(const DoubleType& ft)
{
    return divide(*ft.value);
}

DoubleType& DoubleType::divide(const IntType& ft)
{
    return divide(*ft.value);
}

IntType& IntType::add(const FloatType& ft)
{
    return add(*ft.value);
}

IntType& IntType::add(const DoubleType& ft)
{
    return add(*ft.value);
}

IntType& IntType::add(const IntType& ft)
{
    return add(*ft.value);
}

IntType& IntType::subtract(const FloatType& ft)
{
    return subtract(*ft.value);
}

IntType& IntType::subtract(const DoubleType& ft)
{
    return subtract(*ft.value);
}

IntType& IntType::subtract(const IntType& ft)
{
    return subtract(*ft.value);
}

IntType& IntType::multiply(const FloatType& ft)
{
    return multiply(*ft.value);
}

IntType& IntType::multiply(const DoubleType& ft)
{
    return multiply(*ft.value);
}

IntType& IntType::multiply(const IntType& ft)
{
    return multiply(*ft.value);
}

IntType& IntType::divide(const FloatType& ft)
{
    return divide(*ft.value);
}

IntType& IntType::divide(const DoubleType& ft)
{
    return divide(*ft.value);
}

IntType& IntType::divide(const IntType& ft)
{
    return divide(*ft.value);
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *(ft.add( 2.0f ).value) << std::endl;
    std::cout << "FloatType subtract result=" << *(ft.subtract( 2.0f ).value) << std::endl;
    std::cout << "FloatType multiply result=" << *(ft.multiply( 2.0f ).value) << std::endl;
    std::cout << "FloatType divide result=" << *(ft.divide( 16.0f).value) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *(dt.add(2.0).value) << std::endl;
    std::cout << "DoubleType subtract result=" << *(dt.subtract(2.0).value) << std::endl;
    std::cout << "DoubleType multiply result=" << *(dt.multiply(2.0).value) << std::endl;
    std::cout << "DoubleType divide result=" << *(dt.divide(5.f).value) << std::endl << std::endl;

    std::cout << "IntType add result=" << *(it.add(2).value) << std::endl;
    std::cout << "IntType subtract result=" << *(it.subtract(2).value) << std::endl;
    std::cout << "IntType multiply result=" << *(it.multiply(2).value) << std::endl;
    std::cout << "IntType divide result=" << *(it.divide(3).value) << std::endl << std::endl;
    std::cout << "Chain calculation = " << *((it.multiply(1000).divide(2).subtract(10).add(100)).value) << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *(ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value) << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *(dt.value) << std::endl;
    std::cout << "Initial value of it: " << *(it.value) << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *(dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *(it.divide(0).value) << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *(ft.divide(0).value) << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *(dt.divide(0).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}







