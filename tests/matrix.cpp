#include <catch.hpp>
#include <sstream>
#include <string>
#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t<int> matrix;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    matrix_t<int> matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}

TEST_CASE("Matrix Add")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
     std::string output{
        "3, 3\n"
        "3 3 3\n"
        "3 3 3\n"
        "3 3 3" };
    matrix_t<int> matrix1 ; matrix_t<int> matrix2; matrix_t<int> result;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;
    
    result= matrix1 + matrix2 ;
        
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( output == ostream.str() );
}

TEST_CASE("Matrix Add 2")
{
    std::string input1{
        "3, 3\n"
        "1.5 1.5 1.5\n"
        "1.5 1.5 1.5\n"
        "1.5 1.5 1.5" };
     std::string input2{
        "3, 3\n"
        "2.6 2.6 2.6\n"
        "2.6 2.6 2.6\n"
        "2.6 2.6 2.6" };
     std::string output{
        "3, 3\n"
        "4.1 4.1 4.1\n"
        "4.1 4.1 4.1\n"
        "4.1 4.1 4.1" };
    matrix_t<float> matrix1 ;  matrix_t<float> matrix2;  matrix_t<float> result;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;
    
    result= matrix1 + matrix2 ;
        
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( output == ostream.str() );
}

TEST_CASE("Matrix Sub")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "3, 3\n"
        "5 5 5\n"
        "5 5 5\n"
        "5 5 5" };
     std::string output{
        "3, 3\n"
        "4 4 4\n"
        "4 4 4\n"
        "4 4 4" };
    matrix_t<int> matrix1 ;matrix_t<int> matrix2 ;matrix_t<int> result;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;
  
    result= matrix2 - matrix1 ;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( output == ostream.str() );
}

TEST_CASE("Matrix Sub 2")
{
    std::string input1{
        "3, 3\n"
        "1.5 1.5 1.5\n"
        "1.5 1.5 1.5\n"
        "1.5 1.5 1.5" };
     std::string input2{
        "3, 3\n"
        "2.6 2.6 2.6\n"
        "2.6 2.6 2.6\n"
        "2.6 2.6 2.6" };
     std::string output{
        "3, 3\n"
        "1.1 1.1 1.1\n"
        "1.1 1.1 1.1\n"
        "1.1 1.1 1.1" };
    matrix_t<float> matrix1 ;  matrix_t<float> matrix2;  matrix_t<float> result;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;
    
    result= matrix2 - matrix1 ;
        
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( output == ostream.str() );
}
TEST_CASE("Matrix Mul")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
     std::string output{
        "3, 3\n"
        "6 6 6\n"
        "6 6 6\n"
        "6 6 6" };
    matrix_t<int> matrix1 ; matrix_t<int> matrix2 ;matrix_t<int> result;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;

    result = matrix1 * matrix2 ;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( output == ostream.str() );
}
TEST_CASE("Matrix SelfAdd")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
     std::string output{
        "3, 3\n"
        "3 3 3\n"
        "3 3 3\n"
        "3 3 3" };
    matrix_t<int> matrix1 ;
    matrix_t<int> matrix2 ;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;

    matrix1 += matrix2 ;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( output == ostream.str() );
}
TEST_CASE("Matrix SelfSub")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "3, 3\n"
        "5 5 5\n"
        "5 5 5\n"
        "5 5 5" };
     std::string output{
        "3, 3\n"
        "4 4 4\n"
        "4 4 4\n"
        "4 4 4" };
    matrix_t<int> matrix1 ;
    matrix_t<int> matrix2;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;
  
    matrix2 -= matrix1;
    
    std::ostringstream ostream;
    matrix2.write( ostream );
    
    REQUIRE( output == ostream.str() );
}
TEST_CASE("Matrix SelfMul")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
     std::string output{
        "3, 3\n"
        "6 6 6\n"
        "6 6 6\n"
        "6 6 6" };
    matrix_t<int> matrix1 ;
    matrix_t<int> matrix2 ;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;

    matrix1 *= matrix2 ;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( output == ostream.str() );
}

TEST_CASE("All is OK")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    matrix_t<int> matrix1 ;
    matrix_t<int> matrix2 ;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;

    char op = '+';
    bool good = verification (matrix1 , op , matrix2 ) ;
    bool success = true ;
    REQUIRE(good == success);
}

TEST_CASE("All is Not OK")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
     std::string input2{
        "2, 2\n"
        "2 2\n"
        "2 2" };
    matrix_t<int> matrix1 ;
    matrix_t<int> matrix2 ;
    
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    
    matrix1.read( istream1 ) ;
    matrix2.read( istream2 ) ;
    
    char op = '+';
    bool bad = verification (matrix1 , op , matrix2 ) ;
    bool success = false ;
    REQUIRE(bad == success);
}
