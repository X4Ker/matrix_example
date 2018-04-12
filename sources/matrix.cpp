#include "matrix.hpp"

template<typename T>
matrix_t::matrix_t() : elements_{ nullptr }, rows_{ 0 }, collumns_{ 0 }
{
}

template<typename T>
matrix_t::matrix_t( matrix_t<T> const & other )
{
	rows = matrix.rows;
	columns = matrix.columns;

	data = T *[rows];
	for (std::size_t i = 0; i < rows; ++i) {
		data[i] = new T[columns];
		for (std::size_t j = 0; j < columns; ++j) {
			data[i][j] = matrix.data[i][j];
		}
	}
}

template<typename T>
matrix_t & matrix_t::operator =( matrix_t const & other )
{
	if (this != &matrix) {
		for (std::size_t i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;

		rows = matrix.rows;
		columns = matrix.columns;
		data = new T *[rows];
		for (std::size_t i = 0; i < rows; ++i) {
			data[i] = new T[columns];
		}
		for (std::size_t i = 0; i < rows; ++i) {
			for (std::size_t j = 0; j < columns; ++j) {
				data[i][j] = matrix.data[i][j];
			}
		}
	}
	return *this;
}

template<typename T>
matrix_t::~matrix_t()
{
	for (std::size_t i = 0; i < rows; ++i) {
		delete[] data[i];
	}
	delete[] data;
}

template<typename T>
std::size_t matrix_t::rows() const
{
    return rows_;
}

template<typename T>
std::size_t matrix_t::collumns() const
{
    return collumns_;
}

template<typename T>
matrix_t matrix_t::operator +( matrix_t const & other ) const
{
	assert((columns == other.columns) && (rows == other.rows));

	matrix_t result;
	result.columns = columns;
	result.rows = rows;
	result.data = new T *[rows];
	for (std::size_t i = 0; i < rows; i++) {
		result.data[i] = new T[columns];
		for (std::size_t j = 0; j < columns; j++) {
			result.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return result;
}

template<typename T>
matrix_t matrix_t::operator -( matrix_t const & other ) const
{
	assert((columns == other.columns) && (rows == other.rows));

	matrix_t result;
	result.columns = columns;
	result.rows = rows;
	result.data = new T *[rows];
	for (std::size_t i = 0; i < rows; i++) {
		result.data[i] = new float[columns];
		for (std::size_t j = 0; j < columns; j++) {
			result.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return result;
}

template<typename T>
matrix_t matrix_t::operator *( matrix_t const & other ) const
{
	assert((columns == other.columns) && (rows == other.rows));

	matrix_t result;
	result.columns = columns;
	result.rows = rows;
	result.data = new T *[rows];
	for (std::size_t i = 0; i < rows; i++) {
		result.data[i] = new T[columns];
		for (std::size_t j = 0; j < columns; j++) {
			result.data[i][j] = 0.0f;
			for (std::size_t r = 0; r < columns; r++) {
				result.data[i][j] += data[i][r] * other.data[r][j];
			}
		}
	}
	return result;
}

template<typename T>
matrix_t & matrix_t::operator -=( matrix_t const & other )
{
	assert((columns == other.columns) && (rows == other.rows));

	for (std::size_t i = 0; i < rows; i++) {
		for (std::size_t j = 0; j < columns; j++) {
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}

template<typename T>
matrix_t & matrix_t::operator +=( matrix_t const & other )
{
	assert((columns == other.columns) && (rows == other.rows));

	for (std::size_t i = 0; i < rows; i++) {
		for (std::size_t j = 0; j < columns; j++) {
			data[i][j] += other.data[i][j];
		}
	}
	return *this;
}

template<typename T>
matrix_t & matrix_t::operator *=( matrix_t const & other )
{
	assert((columns == other.rows) && (rows == other.columns));

	result.data = new T *[rows];
	for (std::size_t i = 0; i<rows; i++) {
		result.data[i] = new T[other.columns];
	}

	for (std::size_t i = 0; i < rows; i++) {
		result.data[i] = new T[other.columns];
		for (std::size_t j = 0; j < columns; j++) {
			result.data[i][j] = 0;
			for (std::size_t r = 0; r < columns; r++) {
				result.data[i][j] += data[i][r] * other.data[r][j];
			}
		}
	}
	return *this = result;
}

template<typename T>
std::istream & matrix_t::read( std::istream & stream )
{
    std::size_t rows;
    std::size_t collumns;
    char symbol;
    
    bool success = true;
    if( stream >> rows && stream >> symbol && symbol == ',' && stream >> collumns ) {
        T ** elements = new T *[ rows ];
        for( std::size_t i = 0; success && i < rows; ++i ) {
            elements[ i ] = new T[ collumns ];
            for( std::size_t j = 0; j < collumns; ++j ) {
                if( !( stream >> elements[ i ][ j ] ) ) {
                    success = false;
                    break;
                }
            }
        }
        
        if( success ) {
            for( std::size_t i = 0; i < rows_; ++i ) {
                delete [] elements_[ i ];
            }
            delete [] elements_;
            
            rows_ = rows;
            collumns_ = collumns;
            elements_ = elements;
        }
        else {
            for( std::size_t i = 0; i < rows; ++i ) {
                delete [] elements[ i ];
            }
            delete [] elements;
        }
    }
    else {
        success = false;
    }
    
    if( !success ) {
        stream.setstate( std::ios_base::failbit );
    }
    
	return stream;
}

template<typename T>
std::ostream & matrix_t::write( std::ostream & stream ) const
{
    stream << rows_ << ", " << collumns_;
    for( std::size_t i = 0; i < rows_; ++i ) {
        stream << '\n';
        for( std::size_t j = 0; j < collumns_; ++j ) {
            stream << elements_[ i ][ j ];
            if( j != rows_ - 1 ) {
                stream << ' ';
            }
        }
    }
    
	return stream;
}
