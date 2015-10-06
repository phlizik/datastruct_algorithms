/**
 * Compute optimal ordering of matrix multiplication.
 * c contains the number of columns for each of the n matrices.
 * c[ 0 ] is the number of rows in matrix 1.
 * The minimum number of multiplications is left in m[ 1 ][ n ].
 * Actual ordering is computed via another procedure using lastChange.
 * m and lastChange are indexed starting at 1, instead of 0.
 * Note: Entries below main diagonals of m and lastChange
 * are meaningless and uninitialized.
 */
void optMatrix( const vector<int> & c,
                matrix<long> & m, matrix<int> & lastChange ) 
{
    int n = c.size( ) - 1;

    for( int left = 1; left <= n; left++ )
        m[ left ][ left ] = 0;
    for( int k = 1; k < n; k++ )   // k is right - left
        for( int left = 1; left <= n - k; left++ )
        {
            // For each position
            int right = left + k;
            m[ left ][ right ] = INFINITY;
            for( int i = left; i < right; i++ )
            {
                long thisCost = m[ left ][  i ] + m[ i + 1 ][ right ]
                        + c[ left - 1 ] * c[ i ] * c[ right ];
                if( thisCost < m[ left ][ right ] )  // Update min
                {
                    m[ left ][ right ] = thisCost;
                    lastChange[ left ][ right ] = i;
                }
            }
        }
}
