#include <iostream>
#include <cstring>

using namespace std ;

const int maxn = 210 ;

char str[maxn][maxn] ;
char node[maxn] ;
int rcount ;
int ncount ;
void init() {
    rcount = 0 ;
    ncount = 0 ;
    memset( str , 0 , sizeof( str ) ) ;
    memset( node , 0 , sizeof( node ) ) ;
}
bool islable( char c ) {
    if( c == ' ' || c  == '|' || c == '#' || c == '-' || c == '/n' )
        return false ;
    return true ;
}
void dfs( char s[][maxn] , int b , int e , int r ) {
    node[ncount++] = '(' ;
    for( int i = b ; i <= e && i < strlen( s[r] ) ; i++ )
        if( islable( s[r][i] ) )  {
            if( s[r+1][i] == '|' )  {
                node[ncount++] = s[r][i] ;
                int nb = -1 ;
                int ne = strlen( s[r+2] ) - 1 ;
                for( int j = i ; j >= 0 ; j-- )  {
                    if( s[r+2][j] != '-' ){
                        nb = j ;
                        break ;
                    }
                }
                for( int j = i ; j < strlen( s[r+2] ) ; j++ ) {
                    if (s[r + 2][j] != '-') {
                        ne = j;
                        break;
                    }
                }
                if( nb == -1 )
                    nb = 0 ;
                dfs( s , nb , ne , r + 3 ) ;
        }
        else if( islable( s[r][i] ) ) {
            node[ncount++] = str[r][i] ;
            node[ncount++] = '(' ; node[ncount++] = ')' ;
        }

}
node[ncount++] = ')' ;
return ;
}

int main() {
    int ncase ;
    cin >> ncase ;
    getchar() ;
    while( ncase-- )  {
        init() ;
        while( 1  ){
            gets( str[rcount] ) ;
            if( str[rcount++][0] == '#' ) break ;
        }
        dfs( str , 0 , strlen( str[0] ) - 1 ,0 ) ;
        cout << node << endl ;
    }
    return 0 ;
}