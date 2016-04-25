#include "fixed_point.h"

#include <iostream>
#include <cassert>
#include <cmath>

// -----------------------------------------------------------------------------
// advanced assert
// -----------------------------------------------------------------------------

#define EXPECT_EQ( X , Y )                            \
{                                                     \
    auto x = X;                                       \
    auto y = Y;                                       \
    if ( !(x == y) ) {                                \
        std::cerr << std::boolalpha                   \
        << "! assertion failed in line " << __LINE__  \
        << ": expected " << x                         \
        << ", got " << y << std::endl;                \
    }                                                 \
}                                                     \

#define EXPECT_CLOSE( X , Y , D )                     \
{                                                     \
    auto x = X;                                       \
    auto y = Y;                                       \
    auto d = D;                                       \
    if ( abs(x-y) >= d   ) {                          \
        std::cerr << std::boolalpha                   \
        << "! assertion failed in line " << __LINE__  \
        << ": expected " << (x-y)                     \
        << " to be less than " << d << std::endl;     \
    }                                                 \
}                                                     \


/*auto operator<< ( std::ostream& os , fixed_point const & f ) -> std::ostream&
{
    os << float(f);
    return os;
}*/



int main()
{
    const fixed_point fp1( 6.375f );
    const fixed_point fp2( -4.0f );

    // -------------------------------------------------------------------------
    EXPECT_EQ(  6 , int(fp1) );
    EXPECT_EQ( -4 , int(fp2) );

    //TODO abs() needs to be implemented!
    //EXPECT_EQ(  fp1 , abs(fp1) );
    //EXPECT_EQ( -fp2 , abs(fp2) );

    // -------------------------------------------------------------------------
    // comparison and ordering
    assert( fp1 == fixed_point(6.375) );
    assert( -fp1 == fixed_point(-6.375));
    assert( fp2 != fp1 );
    assert( fp2 <  fp1  );
    assert( fp1 >  fp2  );
    assert( fp2 <= fp1 );
    assert( fp1 >= fp2 );
#if 0


    // -------------------------------------------------------------------------
    // arithmetics
    EXPECT_EQ( fixed_point( 2.375f  ) , fp1 + fp2 );
    EXPECT_EQ( fixed_point( 10.375f ) , fp1 - fp2 );
    EXPECT_EQ( fixed_point(-25.5f   ) , fp1 * fp2 );
    EXPECT_EQ( fixed_point(-1.59375f) , fp1 / fp2 );

    // -------------------------------------------------------------------------
    // arithmetics assignment
    fixed_point
    fp3 = fp1;  fp3 += fp2;     EXPECT_EQ( fixed_point( 2.375f  ) , fp3 );
    fp3 = fp1;  fp3 -= fp2;     EXPECT_EQ( fixed_point( 10.375f ) , fp3 );
    fp3 = fp1;  fp3 *= fp2;     EXPECT_EQ( fixed_point(-25.5f   ) , fp3 );
    fp3 = fp1;  fp3 /= fp2;     EXPECT_EQ( fixed_point(-1.59375f) , fp3 );

    // -------------------------------------------------------------------------
    // pre/post - increment/decrement
    fp3 = fp1;  EXPECT_EQ( fixed_point(7.375f) , ++fp3 );
    fp3 = fp1;  EXPECT_EQ( fixed_point(5.375f) , --fp3 );
    fp3 = fp1;  EXPECT_EQ( fixed_point(6.375f) , fp3++ );  EXPECT_EQ( fixed_point(7.375f) , fp3 );
    fp3 = fp1;  EXPECT_EQ( fixed_point(6.375f) , fp3-- );  EXPECT_EQ( fixed_point(5.375f) , fp3 );

    // -------------------------------------------------------------------------
    // trigonometric functions
    EXPECT_CLOSE( fixed_point(std::sin(0.5f)) , sin(fixed_point(0.5f)) , fixed_point(0.01) );
    EXPECT_CLOSE( fixed_point(std::cos(0.5f)) , cos(fixed_point(0.5f)) , fixed_point(0.01) );
#endif
}
