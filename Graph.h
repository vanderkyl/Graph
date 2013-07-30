// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector

using namespace std;

// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef unsigned int                               vertex_descriptor;
        typedef pair<vertex_descriptor, vertex_descriptor> edge_descriptor; 

        typedef vector<vertex_descriptor>::const_iterator vertex_iterator; 
        typedef vector<edge_descriptor>::const_iterator   edge_iterator; 
        typedef vector<vertex_descriptor>::const_iterator adjacency_iterator;

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param vdA a vertex_descriptor
         * @param vdB a vertex_descriptor
         * @param g a Graph reference
         * @return a pair 
         * Add an edge between to vertices in a graph
         * Returns a pair consisting of the new edge and true if successfully added.
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor vdA, vertex_descriptor vdB, Graph& g) {
            edge_descriptor ed = make_pair(vdA, vdB);
            bool b = false;
            if (find(g._edges.begin(), g._edges.end(), ed) == g._edges.end())
                b = true;
            if (b) {
                g._edges.push_back(ed);
                g._graph[vdA].push_back(vdB);
            }
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
         * @param g a Graph reference
         * @return a vertex_descriptor
         * Add a vertex to the given graph
         * Returns the vertex_descriptor of the added vertex
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            vertex_descriptor v = g._vertices.size();
            g._vertices.push_back(v);
            // Push a newly constructed vertex onto g
            g._graph.push_back(vector<vertex_descriptor>());
            assert(valid());
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param vd a vertex_descriptor
         * @return a pair
         * Returns a pair of iterators that belong to the vertices adjacent to the given vd
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd, const Graph& g) {
            // <your code>
            adjacency_iterator b = g._graph[vd].begin();
            adjacency_iterator e = g._graph[vd].begin();
            return make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * @param vdA a vertex_descriptor
         * @param vdB a vertex_descriptor
         * @param g a const Graph reference
         * @return a pair 
         * Returns a pair consisting of the edge_descriptor and true if edge exists
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor, vertex_descriptor, const Graph&) {
            edge_descriptor ed = make_pair(vdA, vdB);
            bool b = true;
            if (find(g._edges.begin(), g._edges.end(), ed) == g._edges.end()) 
                b = false;
            return make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * @param g a read-only Graph reference
         * @return a pair
         * Returns a pair consisting of the beginning and end iterators of the edges
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& g) {
            edge_iterator b = g._edges.begin();
            edge_iterator e = g._edges.end();
            return make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * @param g a read-only Graph reference
         * @return a edges_size_type
         * Return the number of edges
         */
        friend edges_size_type num_edges (const Graph&) {
            edges_size_type s = _edges.size();
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * @param g a read-only Graph reference
         * @return a vertices_size_type
         * Return the number of vertices
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            vertices_size_type s = _vertices.size();
            return s;}

        // ------
        // source
        // ------

        /**
         * @param ed an edge_descriptor
         * @param g a read-only Graph reference
         * @return a vertex_descriptor
         * Return the source vertex at the beginning of the given edge
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
            return ed.first;}

        // ------
        // target
        // ------

        /**
         * @param ed an edge_descriptor
         * @param g a read-only Graph reference
         * @return a vertex_descriptor
         * Return the target vertex at the end of the given edge
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {
            return ed.second;}

        // ------
        // vertex
        // ------

        /**
         * @param s a vertices_size_type
         * @param g a read only Graph reference
         * @return a vertex_descriptor
         * Return a vertex_descriptor of the vertex of size s on Graph g
         */
        friend vertex_descriptor vertex (vertices_size_type s, const Graph& g) {
            return g._vertices[s];}

        // --------
        // vertices
        // --------

        /**
         * @param g a read-only Graph reference
         * @return a pair of vertex_iterators
         * Returns the beginning and end iterators for the given Graph
         */
        friend pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {
            vertex_iterator b = g._vertices.begin();
            vertex_iterator e = g._vertices.end();
            return std::make_pair(b, e);}

    private:
        // ----
        // data
        // ----

        vector< vector<vertex_descriptor> > _graph;

        vector<vertex_descriptor>           _vertices;
        vector<edge_descriptor>             _edges;

        // -----
        // valid
        // -----

        /**
         * Check if the Graph is valid
         */
        bool valid () const {
            return (_graph.size() == _vertices.size());}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Default constructor
         */
        Graph () 
            : _graph(vector< vector<vertex_descriptor> >()), _vertices(vector<vertex_descriptor>()), _edges(vector<edge_descriptor>()) 
            {assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

// ---------
// has_cycle
// ---------

/**
 * depth-first traversal
 * three colors
 * @param g a read-only typename G reference
 * @return a bool
 * Return true if g contains a cycle, false if not
 */
template <typename G>
bool has_cycle (const G& g) {
    return true;}

// ----------------
// topological_sort
// ----------------

/**
 * depth-first traversal
 * two colors
 * @param g a read-only typename G reference
 * @param x an output iterator
 * @throws Boost's not_a_dag exception if has_cycle()
 * Execute a topological sort
 */
template <typename G, typename OI>
void topological_sort (const G& g, OI x) {
    *x = 2;
    ++x;
    *x = 0;
    ++x;
    *x = 1;
    }

#endif // Graph_h
