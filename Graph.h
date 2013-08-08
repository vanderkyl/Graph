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
        friend pair<edge_descriptor, bool> add_edge (vertex_descriptor vdA, vertex_descriptor vdB, Graph& g) {
            edge_descriptor ed = make_pair(vdA, vdB);
            bool b = false;
            // If the edge does not exist, add the new edge
            if (find(g._edges.begin(), g._edges.end(), ed) == g._edges.end()) { 
                unsigned int s = g._vertices.size();
                if (vdA >= s || vdB >= s) {
                    vertex_descriptor v_size = (max(vdA, vdB) + 1) - s;
                    while (v_size != 0) {
                        add_vertex(g);
                        --v_size;
                    }
                }
                b = true;
                g._graph[vdA].push_back(vdB);
                g._edges.push_back(ed);
            }
            return make_pair(ed, b);}

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
            vertex_descriptor vd = g._vertices.size();
            g._vertices.push_back(vd);
            // Push a newly constructed vertex onto g
            g._graph.push_back(vector<vertex_descriptor>());
            return vd;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param vd a vertex_descriptor
         * @return a pair
         * Returns a pair of iterators that belong to the vertices adjacent to the given vd
         */
        friend pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd, const Graph& g) {
            return make_pair(g._graph[vd].begin(), g._graph[vd].end());}

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
        friend pair<edge_descriptor, bool> edge (vertex_descriptor vdA, vertex_descriptor vdB, const Graph& g) {
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
        friend pair<edge_iterator, edge_iterator> edges (const Graph& g) {
            return make_pair(g._edges.begin(), g._edges.end());}

        // ---------
        // num_edges
        // ---------

        /**
         * @param g a read-only Graph reference
         * @return a edges_size_type
         * Return the number of edges
         */
        friend edges_size_type num_edges (const Graph& g) {
            return g._edges.size();}

        // ------------
        // num_vertices
        // ------------

        /**
         * @param g a read-only Graph reference
         * @return a vertices_size_type
         * Return the number of vertices
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            return g._vertices.size();}

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
            return make_pair(g._vertices.begin(), g._vertices.end());}

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
 * @param g a read-only G reference
 * @param b an adjacency_iterator
 * @param e an adjacency_iterator
 * @param c a C reference 
 * @return a bool
 * Recursive function to go through each possible edge pathway
 */
template <typename G, typename C>
bool help_cycle (const G& g, typename G:: adjacency_iterator b, typename G:: adjacency_iterator e, C& c) {
    typedef typename C::iterator           v_iterator;
    typedef typename G::adjacency_iterator a_iterator;
    while (b != e) {
        v_iterator vb = c.begin();
        v_iterator ve = c.end();
        if(find(vb, ve, *b) != ve)
            return true;
        c.push_back(*b);
        pair<a_iterator, a_iterator> ai = adjacent_vertices(*b, g);
        if(help_cycle(g, ai.first, ai.second, c))
            return true;
        c.pop_back();
        ++b;
    }
    return false;
}

/**
 * depth-first traversal
 * three colors
 * @param g a read-only typename G reference
 * @return a bool
 * Return true if g contains a cycle, false if not
 */
template <typename G>
bool has_cycle (const G& g) {
    typedef typename G::vertex_descriptor  v_descriptor;
    typedef typename G::vertex_iterator    v_iterator;
    typedef typename G::adjacency_iterator a_iterator;
    pair<v_iterator, v_iterator> vi = vertices(g);
    v_iterator b = vi.first;
    v_iterator e = vi.second;
    // A vector that contains the vertices already looked at for faster search
    vector<v_descriptor> cache;
    while (b != e) {
        cache.push_back(*b);
        pair<a_iterator, a_iterator> ai = adjacent_vertices(*b, g);
        if(help_cycle(g, ai.first, ai.second, cache))
            return true;
        cache.pop_back();
        ++b;
    }
    return false;}

// ----------------
// topological_sort
// ----------------

/*
 * @param g a const G reference
 * @param t a vector<int> reference -> targets 
 * @param s a vector<vertex_descriptor> -> sources
 * Sort vertices into targets and sources
 */
template <typename G>
void target_source_sort (const G& g, vector<int>& t, vector<typename G::vertex_descriptor>& s) {
    typedef typename G::edge_iterator e_iterator;
    pair<e_iterator, e_iterator> ei = edges(g);
    e_iterator eb = ei.first;
    e_iterator ee = ei.second;
    // Signify which vertices are targets
    while (eb != ee) {
        ++t[target(*eb, g)];
        ++eb;
    }
    // Signify which are sources and push onto source vector
    for (unsigned int i = 0; i < t.size(); ++i) {
        if (t[i] == 0) {
            --t[i];
            s.push_back(i);
        }
    }
}

/*
 * @param g a const G reference
 * @param t a vector<int> reference -> targets 
 * @param s a vector<vertex_descriptor> -> sources
 * @return vector<vertex_descriptor> containing output
 * Sort and push onto output vector
 */
template <typename G>
vector<typename G::vertex_descriptor> help_sort (const G& g, vector<int>& t, vector<typename G::vertex_descriptor>& s) {
    typedef typename G::adjacency_iterator a_iterator;
    typedef typename G::vertex_descriptor  v_descriptor;
    vector<v_descriptor> output;
    while (s.size() != 0) {
        v_descriptor vd = s.back();
        output.push_back(vd);
        s.pop_back();

        pair<a_iterator, a_iterator> ai = adjacent_vertices(vd, g);
        a_iterator ab = ai.first;
        a_iterator ae = ai.second;
        while (ab != ae) {
            --t[*ab];
            if (t[*ab] == 0) {
                --t[*ab];
                s.push_back(*ab);
            }
            ++ab;
        }
    }
    return output;
}
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
    typedef typename G::vertices_size_type v_size;
    typedef typename G::vertex_descriptor  v_descriptor;
    if (has_cycle(g))
        throw boost::not_a_dag();
    v_size size = num_vertices(g);
    assert(size != 0);
    // Create vectors for the target vertices and source vertices
    vector<int> targets(size);
    vector<v_descriptor> sources;
    target_source_sort(g, targets, sources);
    // Topologically sort the vertices
    vector<v_descriptor> output = help_sort(g, targets, sources);
    // Copy the sorted vertices into the output iterator
    while(output.size() != 0) {
        *x = output.back();
        output.pop_back();
        ++x;
    }
}

#endif // Graph_h
