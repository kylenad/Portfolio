#ifndef ASTAR_H
#define ASTAR_H

#include <list>
#include <algorithm>
#include <iostream>
#include "preDefined.h"
using namespace std;




class point {
private:
    

public:

    
    point( int a = 16, int b = 11 ) { x = a; y = b; }
    bool operator ==( const point& o ) { return o.x == x && o.y == y; }
    point operator +( const point& o ) { return point( o.x + x, o.y + y ); }
    int x, y;
};

class map {
public:
    //define map
    map() {
        const int NUM_ROWS2 = 31, NUM_COLS2 = 28;
        char t[NUM_ROWS2][NUM_COLS2] = {
            
            
            {'1','H','H','H','H','H','H','H','H','H','H','H','H','3','1','H','H','H','H','H','H','H','H','H','H','H','H','3'},  //   1
            
            {'V','h','a','a','a','a','c','a','a','a','a','a','j','V','V','h','a','a','a','a','a','c','a','a','a','a','g','V'},  //  2
            
            {'V','b','1','H','H','3','b','1','H','H','H','3','b','V','V','b','1','H','H','H','3','b','1','H','H','3','b','V'},  //       3
            
            {'V','b','V','I','I','V','b','V','I','I','I','V','b','V','V','b','V','I','I','I','V','b','V','I','I','V','b','V'},  //      4
            
            {'V','b','2','H','H','4','b','2','H','H','H','4','b','2','4','b','2','H','H','H','4','b','2','H','H','4','b','V'},  //       5
            
            {'V','e','a','a','a','a','l','a','a','c','a','a','d','a','a','d','a','a','c','a','a','l','a','a','a','a','f','V'},  //    6
            
            {'V','b','1','H','H','3','b','1','3','b','1','H','H','H','H','H','H','3','b','1','3','b','1','H','H','3','b','V'},  //        7
            
            {'V','b','2','H','H','4','b','V','V','b','2','H','H','3','1','H','H','4','b','V','V','b','2','H','H','4','b','V'},  //       8
            
            {'V','k','a','a','a','a','f','V','V','k','a','a','g','V','V','h','a','a','i','V','V','n','a','a','a','a','i','V'},  //  9
            
            {'2','H','H','H','H','3','b','V','2','H','H','3','b','V','V','b','1','H','H','4','V','b','1','H','H','H','H','4'},  //      10
            
            {'I','I','I','I','I','V','b','V','1','H','H','4','b','2','4','b','2','H','H','3','V','b','V','I','I','I','I','I'},  //      11
            
            {'I','I','I','I','I','V','b','V','V','h','a','a','d','a','a','d','a','a','j','V','V','b','V','I','I','I','I','I'},  // 12
            
            {'I','I','I','I','I','V','b','V','V','b','1','H','H','S','S','H','H','3','b','V','V','b','V','I','I','I','I','I'},  //      13 - S - k - i - S
            
            {'H','H','H','H','H','4','b','2','4','b','V','C','C','C','C','C','C','V','b','2','4','b','2','H','H','H','H','H'},  //       14
            
            {'<','a','a','a','a','a','l','a','a','m','V','C','C','C','C','C','C','V','n','a','a','l','a','a','a','a','a','>'},  // 15
            
            {'H','H','H','H','H','3','b','1','3','b','V','C','C','C','C','C','C','V','b','1','3','b','1','H','H','H','H','H'},  //       16
            
            {'I','I','I','I','I','V','b','V','V','b','2','H','H','H','H','H','H','4','b','V','V','b','V','I','I','I','I','I'},  //   17
            
            {'I','I','I','I','I','V','b','V','V','n','a','a','a','a','a','a','a','a','m','V','V','b','V','I','I','I','I','I'},  //        18
            
            {'I','I','I','I','I','V','b','V','V','b','1','H','H','H','H','H','H','3','b','V','V','b','V','I','I','I','I','I'},  //   19
            
            {'1','H','H','H','H','4','b','2','4','b','2','H','H','3','1','H','H','4','b','2','4','b','2','H','H','H','H','3'},  //       20
            
            {'V','h','a','a','a','a','l','a','a','d','a','a','j','V','V','h','a','a','d','a','a','l','a','a','a','a','j','V'},  //    21
            
            {'V','b','1','H','H','3','b','1','H','H','H','3','b','V','V','b','1','H','H','H','3','b','1','H','H','3','b','V'},  //       22
            
            {'V','b','2','H','3','V','b','2','H','H','H','4','b','2','4','b','2','H','H','H','4','b','V','1','H','4','b','V'},  //       23
            
            {'V','k','a','g','V','V','e','a','a','c','a','a','d','a','a','d','a','a','c','a','a','f','V','V','h','a','i','V'},  // 24 bottom dot
            
            {'2','H','3','b','V','V','b','1','3','b','1','H','H','H','H','H','H','3','b','1','3','b','V','V','b','1','H','4'},  // 25
            
            {'1','H','4','b','2','4','b','V','V','b','2','H','H','3','1','H','H','4','b','V','V','b','2','4','b','2','H','3'},  //  26
            
            {'V','h','a','d','a','a','i','V','V','k','a','a','g','V','V','h','a','a','i','V','V','k','a','a','d','a','g','V'},  // 27
            
            {'V','b','1','H','H','H','H','4','2','H','H','3','b','V','V','b','1','H','H','4','2','H','H','H','H','3','b','V'},  //      28
            
            {'V','b','2','H','H','H','H','H','H','H','H','4','b','2','4','b','2','H','H','H','H','H','H','H','H','4','b','V'},  //     29
            
            {'V','k','a','a','a','a','a','a','a','a','a','a','d','a','a','d','a','a','a','a','a','a','a','a','a','a','i','V'},  // 30
            
            {'2','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','4'},  //  31
            
            
            
            
            
            /*{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}*/
        };
        //define width and height of map
        w = 28;
        h = 31;
        for( int r = 0; r < h; r++ )
            for( int s = 0; s < w; s++ )
            m[s][r] = t[r][s];
    }
    int operator() ( int x, int y ) { return m[x][y]; }
    char m[28][31];
    int w, h;
};

class node {
public:
    bool operator == (const node& o ) { return pos == o.pos; }
    bool operator == (const point& o ) { return pos == o; }
    bool operator < (const node& o ) { return dist + cost < o.dist + o.cost; }
    point pos, parent;
    int dist, cost;
};

class aStar {
public:
    aStar() {
        //define neightbors
        //neighbours[0] = point( -1, -1 ); neighbours[1] = point(  1, -1 );
    //    neighbours[2] = point( -1,  1 ); neighbours[3] = point(  1,  1 );
        neighbours[0] = point(  0, -1 ); neighbours[1] = point( -1,  0 );
        neighbours[2] = point(  0,  1 ); neighbours[3] = point(  1,  0 );
    }
    
    int calcDist( point& p ){
        // need a better heuristic
        int x = end.x - p.x, y = end.y - p.y;
        return( x * x + y * y );
    }
    
    bool isValid( point& p ) {
        return ( p.x >-1 && p.y > -1 && p.x < m.w && p.y < m.h );
    }
    
    bool existPoint( point& p, int cost ) {
        std::list<node>::iterator i;
        i = std::find( closed.begin(), closed.end(), p );
        if( i != closed.end() ) {
            if( ( *i ).cost + ( *i ).dist < cost ) return true;
            else { closed.erase( i ); return false; }
        }
        i = std::find( open.begin(), open.end(), p );
        if( i != open.end() ) {
            if( ( *i ).cost + ( *i ).dist < cost ) return true;
            else { open.erase( i ); return false; }
        }
        return false;
    }
    
    bool fillOpen( node& n ) {
        int stepCost, nc, dist;
        point neighbour;
        
        for( int x = 0; x < 4; x++ ) {
            // one can make diagonals have different cost
            stepCost = x < 4 ? 1 : 1;
            neighbour = n.pos + neighbours[x];
            if( neighbour == end ) return true;
            //define where the walls are and say it can go there
            if( isValid( neighbour ) && m( neighbour.x, neighbour.y ) != 'C' && m(neighbour.x, neighbour.y ) != 'H' && m(neighbour.x, neighbour.y ) != 'V' && m(neighbour.x, neighbour.y ) != '1' && m(neighbour.x, neighbour.y ) != '2' && m(neighbour.x, neighbour.y ) != '3' && m(neighbour.x, neighbour.y ) != '4') {
                
                nc = stepCost + n.cost;
                dist = calcDist( neighbour );
                if( !existPoint( neighbour, nc + dist ) ) {
                    node m;
                    m.cost = nc; m.dist = dist;
                    m.pos = neighbour;
                    m.parent = n.pos;
                    open.push_back( m );
                }
            }
        }
        return false;
    }
    
    
    
    
    
  
    
    
    
    
    
    
    
    
    bool search( point& s, point& e, map& mp ) {
        node n; end = e; start = s; m = mp;
        n.cost = 0; n.pos = s; n.parent = 0; n.dist = calcDist( s );
        open.push_back( n );
        while( !open.empty() ) {
            //open.sort();
            node n = open.front();
            open.pop_front();
            closed.push_back( n );
            if( fillOpen( n ) ) return true;
        }
        return false;
    }
    
    int path( std::list<point>& path ) {
        path.push_front( end );
        int cost = 1 + closed.back().cost;
        path.push_front( closed.back().pos );
        point parent = closed.back().parent;
        
        for( std::list<node>::reverse_iterator i = closed.rbegin(); i != closed.rend(); i++ ) {
            
            if( ( *i ).pos == parent && !( ( *i ).pos == start ) ) {
                path.push_front( ( *i ).pos );
                parent = ( *i ).parent;
            }
        }
        path.push_front( start );
        return cost;
    }
    
    map m; point end, start;
    point neighbours[4];
    std::list<node> open;
    std::list<node> closed;
};
#endif // ASTAR_H
