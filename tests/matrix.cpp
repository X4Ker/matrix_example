#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t matrix;
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
    matrix_t matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}

TEST_CASE("add matrix")
{
	std::string stroka1{
		"3, 4\n"
		"1.1 1 4 5\n"
		"2 1.2 2 6\n"
		"9 3 3.3 7" };
	std::string stroka2{
		"3, 4\n"
		"7.1 2 2 7\n"
		"1 5.2 2 6\n"
		"2 2 8.3 5" };
	std::string strokar{
		"3, 4\n"
		"8.2 3 6 12\n"
		"3 6.4 4 12\n"
		"11 5 11.6 12" };

	matrix_t<float> matrix1;
	matrix_t<float> matrix2;
	matrix_t<float> result;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	result = matrix1 + matrix2;

	std::ostringstream ostream;
	result.write(ostream);

	REQUIRE(strokar == ostream.str());
}

TEST_CASE("sub matrix")
{
	std::string stroka1{
		"3, 4\n"
		"8.3 3.3 6.3 12.3\n"
		"3.3 6.3 4.3 12.3\n"
		"11.3 5.3 11.3 12.3" };
	std::string stroka2{
		"3, 4\n"
		"1.2 1.2 4.2 5.2\n"
		"2.2 1.2 2.2 6.2\n"
		"9.2 3.2 3.2 7.2" };
	std::string strokar{
		"3, 4\n"
		"7.1 2.1 2.1 7.1\n"
		"1.1 5.1 2.1 6.1\n"
		"2.1 2.1 8.1 5.1" };

	matrix_t<double> matrix1, matrix2, result;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	result = matrix1 - matrix2;

	std::ostringstream ostream;
	result.write(ostream);

	REQUIRE(strokar == ostream.str());
}

TEST_CASE("mul matrix")
{
	std::string stroka1{
		"3, 4\n"
		"1 1 4 5\n"
		"2 1 2 6\n"
		"9 3 3 7" };
	std::string stroka2{
		"4, 3\n"
		"7 2 2 \n"
		"1 5 2 \n"
		"2 2 8 \n"
		"1 1 1" };
	std::string strokar{
		"3, 3\n"
		"21 20 41\n"
		"25 19 28\n"
		"79 46 55" };

	matrix_t<int> matrix1, matrix2, result;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	result = matrix1 * matrix2;

	std::ostringstream ostream;
	result.write(ostream);

	REQUIRE(strokar == ostream.str());
}

TEST_CASE("selfsub matrix")
{
	std::string stroka1{
		"3, 4\n"
		"8.1 3.1 6.1 12.1\n"
		"3.1 6.1 4.1 12.1\n"
		"11.1 5.1 11.1 12.1" };
	std::string stroka2{
		"3, 4\n"
		"1.1 1.1 4.1 5.1\n"
		"2.1 1.1 2.1 6.1\n"
		"9.1 3.1 3.1 7.1" };
	std::string strokar{
		"3, 4\n"
		"7 2 2 7\n"
		"1 5 2 6\n"
		"2 2 8 5" };

	matrix_t<float> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	matrix1 -= matrix2;

	std::ostringstream ostream;
	matrix1.write(ostream);

	REQUIRE(strokar == ostream.str());
}

TEST_CASE("selfadd matrix")
{
	std::string stroka1{
		"3, 4\n"
		"1 1 4 5\n"
		"2 1 2 6\n"
		"9 3 3 7" };
	std::string stroka2{
		"3, 4\n"
		"7 2 2 7\n"
		"1 5 2 6\n"
		"2 2 8 5" };
	std::string strokar{
		"3, 4\n"
		"8 3 6 12\n"
		"3 6 4 12\n"
		"11 5 11 12" };

	matrix_t<int> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	matrix1 += matrix2;

	std::ostringstream ostream;
	matrix1.write(ostream);

	REQUIRE(strokar == ostream.str());
}

TEST_CASE("selfmul matrix")
{
	std::string stroka1{
		"3, 4\n"
		"1.1 1.1 4.1 5.1\n"
		"2.1 1.1 2.1 6.1\n"
		"9.1 3.1 3.1 7.1" };
	std::string stroka2{
		"4, 3\n"
		"7.2 2.2 2.2\n"
		"1.2 5.2 2.2\n"
		"2.2 2.2 8.2\n"
		"1.2 1.2 1.2" };
	std::string strokar{
		"3, 3\n"
		"24.38 23.28 44.58\n"
		"28.38 22.28 31.58\n"
		"84.58 51.48 60.78" };

	matrix_t<float> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	matrix1 *= matrix2;

	std::ostringstream ostream;
	matrix1.write(ostream);

	REQUIRE(strokar == ostream.str());
}

TEST_CASE("add error_matrix")
{
	std::string stroka1{
		"3, 4\n"
		"1.1 1 4 5\n"
		"2 1.2 2 6\n"
		"9 3 3.3 7" };
	std::string stroka2{
		"2, 4\n"
		"7.1 2 2 7\n"
		"2 2 8.3 5" };

	matrix_t<float> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	REQUIRE_THROWS_AS(matrix1 + matrix2, std::invalid_argument);
}

TEST_CASE("selfsub error_matrix")
{
	std::string stroka1{
		"2, 4\n"
		"8.1 3.1 6.1 12.1\n"
		"11.1 5.1 11.1 12.1" };
	std::string stroka2{
		"3, 4\n"
		"1.1 1.1 4.1 5.1\n"
		"2.1 1.1 2.1 6.1\n"
		"9.1 3.1 3.1 7.1" };

	matrix_t<float> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	REQUIRE_THROWS_AS(matrix1 -= matrix2, std::invalid_argument);
}

TEST_CASE("selfadd error_matrix")
{
	std::string stroka1{
		"3, 4\n"
		"1 1 4 5\n"
		"2 1 2 6\n"
		"9 3 3 7" };
	std::string stroka2{
		"3, 2\n"
		"7 2\n"
		"1 5\n"
		"2 2" };

	matrix_t<int> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	REQUIRE_THROWS_AS(matrix1 += matrix2, std::invalid_argument);
}

TEST_CASE("mul error_matrix")
{
	std::string stroka1{
		"3, 3\n"
		"1 1 4\n"
		"2 1 2\n"
		"9 3 3 " };
	std::string stroka2{
		"4, 3\n"
		"7 2 2 \n"
		"1 5 2 \n"
		"2 2 8 \n"
		"1 1 1" };

	matrix_t<int> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	REQUIRE_THROWS_AS(matrix1 * matrix2, std::invalid_argument);
}

TEST_CASE("selfmul error_matrix")
{
	std::string stroka1{
		"3, 4\n"
		"1.1 1.1 4.1 5.1\n"
		"2.1 1.1 2.1 6.1\n"
		"9.1 3.1 3.1 7.1" };
	std::string stroka2{
		"3, 3\n"
		"7.2 2.2 2.2\n"
		"1.2 5.2 2.2\n"
		"1.2 1.2 1.2" };

	matrix_t<float> matrix1, matrix2;
	std::istringstream istream1{ stroka1 };
	std::istringstream istream2{ stroka2 };

	matrix1.read(istream1);
	matrix2.read(istream2);

	REQUIRE_THROWS_AS(matrix1 *= matrix2, std::invalid_argument);
}