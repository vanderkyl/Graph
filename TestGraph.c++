#include <iostream>         // ostream
#include <algorithm>        // equal
#include <cstring> // strcmp
#include <sstream> // ostringstream
#include <stdexcept> // invalid_argument
#include <string> // ==#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream> // ostringstream
#include <utility> // pair

#include "boost/graph/adjacency_list.hpp" // adjacency_list
#include "boost/graph/topological_sort.hpp"// topological_sort
/*
 * This is the gtest header.
 * The usual installation is in /usr/include/
 *
 * It's already installed there on the CS machines,
 * but if you've installed it elsewhere on your own,
 * there's no need to change this line.
 *
 * You just need to make sure to include the folder where
 * you put the gtest folder when compiling.
 */
#include "Graph.h"
#include "gtest/gtest.h"

//g++ -pedantic -std=c++0x -Wall TestStuff.c++ -o TestStuff -lgtest -lgtest_main -pthread


class MyGraphTest: public testing::Test{
protected:
	typedef typename boost::adjacency_list<boost::setS, boost::vecS, boost::directedS> graph_type;
	typedef typename graph_type::vertex_descriptor  vertex_descriptor;
	typedef typename graph_type::edge_descriptor    edge_descriptor;

	typedef typename graph_type::vertex_iterator    vertex_iterator;
	typedef typename graph_type::edge_iterator      edge_iterator;
	typedef typename graph_type::adjacency_iterator adjacency_iterator;

	typedef typename graph_type::vertices_size_type vertices_size_type;
	typedef typename graph_type::edges_size_type    edges_size_type;
	
    graph_type gA;
	graph_type gB;
	graph_type gC;
	graph_type gD;
	graph_type gE;
	graph_type gF;
	
	/*--------gA---------*/
	vertex_descriptor vdAA;
	vertex_descriptor vdAB;
	vertex_descriptor vdAC;
	vertex_descriptor vdAD;
	vertex_descriptor vdAE;
	vertex_descriptor vdAF;
	vertex_descriptor vdAG;
	vertex_descriptor vdAH;
	edge_descriptor edAAB;
	edge_descriptor edAAC;
	edge_descriptor edAAE;
	edge_descriptor edABD;
	edge_descriptor edABE;
	edge_descriptor edACD;
	edge_descriptor edADE;
	edge_descriptor edADF;
	edge_descriptor edAFD;
	edge_descriptor edAFH;
	edge_descriptor edAGH;
	
	/*--------gB---------*/
	vertex_descriptor vdBA;
	vertex_descriptor vdBB;
	vertex_descriptor vdBC;
	vertex_descriptor vdBD;
	vertex_descriptor vdBE;
	vertex_descriptor vdBF;
	vertex_descriptor vdBG;
	vertex_descriptor vdBH;
	edge_descriptor edBAB;
	edge_descriptor edBAC;
	edge_descriptor edBAE;
	edge_descriptor edBBD;
	edge_descriptor edBBE;
	edge_descriptor edBCD;
	edge_descriptor edBDE;
	edge_descriptor edBDF;
    edge_descriptor edBFD;
    edge_descriptor edBFH;
    edge_descriptor edBGH;
	
	/*--------gC---------*/
	vertex_descriptor vdCA;
	vertex_descriptor vdCB;
	edge_descriptor edCAB;
	
	/*--------gD---------*/
	vertex_descriptor vdDA;
    vertex_descriptor vdDB;
    vertex_descriptor vdDC;
    vertex_descriptor vdDD;
    vertex_descriptor vdDE;
    vertex_descriptor vdDF;
    vertex_descriptor vdDG;
    vertex_descriptor vdDH;
	vertex_descriptor vdDI;
	vertex_descriptor vdDJ;
	vertex_descriptor vdDK;
	edge_descriptor edDJK;
	
	/*--------gE---------*/
	vertex_descriptor vdEA;
    vertex_descriptor vdEB;
    vertex_descriptor vdEC;
    vertex_descriptor vdED;
    vertex_descriptor vdEE;
    vertex_descriptor vdEF;
    vertex_descriptor vdEG;
    vertex_descriptor vdEH;
	edge_descriptor edEAB;
    edge_descriptor edEAC;
    edge_descriptor edEAE;
    edge_descriptor edEBD;
    edge_descriptor edEBE;
    edge_descriptor edECD;
    edge_descriptor edEDE;
    edge_descriptor edEDF;
    edge_descriptor edEFD;
    edge_descriptor edEFH;
	
    /*
	//std::deque<int> v3;
	//######################
	typedef Graph<int>	graph_type2;
	typedef typename graph_type2::vertex_descriptor  vertex_descriptor2;
	typedef typename graph_type2::edge_descriptor    edge_descriptor2;

	typedef typename graph_type2::vertex_iterator    vertex_iterator2;
	typedef typename graph_type2::edge_iterator      edge_iterator2;
	typedef typename graph_type2::adjacency_iterator adjacency_iterator2;

	typedef typename graph_type2::vertices_size_type vertices_size_type2;
	typedef typename graph_type2::edges_size_type    edges_size_type2;
	
    graph_type2 g12;
	graph_type2 g22;
	graph_type2 g32;
	graph_type2 g42;
	graph_type2 g52;
	graph_type2 g62;
	
	//g12
	vertex_descriptor2 vdA2;
	vertex_descriptor2 vdB2;
	vertex_descriptor2 vdC2;
	vertex_descriptor2 vdD2;
	vertex_descriptor2 vdE2;
	vertex_descriptor2 vdF2;
	vertex_descriptor2 vdG2;
	vertex_descriptor2 vdH2;
	edge_descriptor2 edAB2;
	edge_descriptor2 edAC2;
	edge_descriptor2 edAE2;
	edge_descriptor2 edBD2;
	edge_descriptor2 edBE2;
	edge_descriptor2 edCD2;
	edge_descriptor2 edDE2;
	edge_descriptor2 edDF2;
	edge_descriptor2 edFD2;
	edge_descriptor2 edFH2;
	edge_descriptor2 edGH2;
	
	//g32
	vertex_descriptor2 vdI2;
	vertex_descriptor2 vdJ2;
	vertex_descriptor2 vdK2;
	vertex_descriptor2 vdL2;
	vertex_descriptor2 vdM2;
	vertex_descriptor2 vdN2;
	vertex_descriptor2 vdO2;
	vertex_descriptor2 vdP2;
	edge_descriptor2 edIJ2;
	edge_descriptor2 edIK2;
	edge_descriptor2 edIM2;
	edge_descriptor2 edJL2;
	edge_descriptor2 edJM2;
	edge_descriptor2 edKL2;
	edge_descriptor2 edLM2;
	edge_descriptor2 edLN2;
	edge_descriptor2 edNL2;
	edge_descriptor2 edNP2;
	edge_descriptor2 edOP2;
	
	//g42
	vertex_descriptor2 vdQ2;
	vertex_descriptor2 vdR2;
	edge_descriptor2 edQR2;
	
	//g52
	vertex_descriptor2 vdS2;
	vertex_descriptor2 vdT2;
	vertex_descriptor2 vdU2;
	vertex_descriptor2 vdV2;
	vertex_descriptor2 vdW2;
	vertex_descriptor2 vdX2;
	vertex_descriptor2 vdY2;
	vertex_descriptor2 vdZ2;
	vertex_descriptor2 vdAA2;
	vertex_descriptor2 vdBB2;
	vertex_descriptor2 vdCC2;
	edge_descriptor2 edBBCC2;
	
	//g62
	vertex_descriptor2 vdAAA2;
	vertex_descriptor2 vdBBB2;
	vertex_descriptor2 vdCCC2;
	vertex_descriptor2 vdDDD2;
	vertex_descriptor2 vdEEE2;
	vertex_descriptor2 vdFFF2;
	vertex_descriptor2 vdGGG2;
	vertex_descriptor2 vdHHH2;
	edge_descriptor2 edAAABBB2;
	edge_descriptor2 edAAACCC2;
	edge_descriptor2 edAAAEEE2;
	edge_descriptor2 edBBBDDD2;
	edge_descriptor2 edBBBEEE2;
	edge_descriptor2 edCCCDDD2;
	edge_descriptor2 edDDDEEE2;
	edge_descriptor2 edDDDFFF2;
	edge_descriptor2 edFFFHHH2;
	edge_descriptor2 edGGGHHH2;
    */

	virtual void SetUp(){     
	    /*--------gA--------*/
	    vdAA = add_vertex(gA);
	    vdAB = add_vertex(gA);
	    vdAC = add_vertex(gA);
	    vdAD = add_vertex(gA);
	    vdAE = add_vertex(gA);
	    vdAF = add_vertex(gA);
	    vdAG = add_vertex(gA);
	    vdAH = add_vertex(gA);
	    edAAB = add_edge(vdAA, vdAB, gA).first;
	    edAAC = add_edge(vdAA, vdAC, gA).first;
	    edAAE = add_edge(vdAA, vdAE, gA).first;
	    edABD = add_edge(vdAB, vdAD, gA).first;
	    edABE = add_edge(vdAB, vdAE, gA).first;
	    edACD = add_edge(vdAC, vdAD, gA).first;
	    edADE = add_edge(vdAD, vdAE, gA).first;
	    edADF = add_edge(vdAD, vdAF, gA).first;
	    edAFD = add_edge(vdAF, vdAD, gA).first;
	    edAFH = add_edge(vdAF, vdAH, gA).first;
	    edAGH = add_edge(vdAG, vdAH, gA).first;
	    
        /*--------gB--------*/
        vdBA = add_vertex(gB);
        vdBB = add_vertex(gB);
        vdBC = add_vertex(gB);
        vdBD = add_vertex(gB);
        vdBE = add_vertex(gB);
        vdBF = add_vertex(gB);
        vdBG = add_vertex(gB);
        vdBH = add_vertex(gB);
        edBAB = add_edge(vdBA, vdBB, gB).first;
        edBAC = add_edge(vdBA, vdBC, gB).first;
        edBAE = add_edge(vdBA, vdBE, gB).first;
        edBBD = add_edge(vdBB, vdBD, gB).first;
        edBBE = add_edge(vdBB, vdBE, gB).first;
        edBCD = add_edge(vdBC, vdBD, gB).first;
        edBDE = add_edge(vdBD, vdBE, gB).first;
        edBDF = add_edge(vdBD, vdBF, gB).first;
        edBFD = add_edge(vdBF, vdBD, gB).first;
        edBFH = add_edge(vdBF, vdBH, gB).first;
        edBGH = add_edge(vdBG, vdBH, gB).first;

        /*
	    //g3
	    vdI = add_vertex(g3);
	    vdJ = add_vertex(g3);
	    vdK = add_vertex(g3);
	    vdL = add_vertex(g3);
	    vdM = add_vertex(g3);
	    vdN = add_vertex(g3);
	    vdO = add_vertex(g3);
	    vdP = add_vertex(g3);
	    edIJ = add_edge(vdI, vdJ, g3).first;
	    edIK = add_edge(vdI, vdK, g3).first;
	    edIM = add_edge(vdI, vdM, g3).first;
	    edJL = add_edge(vdJ, vdL, g3).first;
	    edJM = add_edge(vdJ, vdM, g3).first;
	    edKL = add_edge(vdK, vdL, g3).first;
	    edLM = add_edge(vdL, vdM, g3).first;
	    edLN = add_edge(vdL, vdN, g3).first;
	    edNL = add_edge(vdN, vdL, g3).first;
	    edNP = add_edge(vdN, vdP, g3).first;
	    edOP = add_edge(vdO, vdP, g3).first;
	    */

	    /*--------gC-------*/
	    vdCA = add_vertex(gC);
	    vdCB = add_vertex(gC);
	    edCAB = add_edge(vdCA, vdCB, gC).first;
	    
        /*
	    //g5
	    vdS = add_vertex(g5);
	    vdT = add_vertex(g5);
	    vdU = add_vertex(g5);
	    vdV = add_vertex(g5);
	    vdW = add_vertex(g5);
	    vdX = add_vertex(g5);
	    vdY = add_vertex(g5);
	    vdZ = add_vertex(g5);
	    vdAA = add_vertex(g5);
	    vdBB = add_vertex(g5);
	    vdCC = add_vertex(g5);
	    edBBCC = add_edge(vdBB, vdCC, g5).first;
	    
	    //g6
	    vdAAA = add_vertex(g6);
	    vdBBB = add_vertex(g6);
	    vdCCC = add_vertex(g6);
	    vdDDD = add_vertex(g6);
	    vdEEE = add_vertex(g6);
	    vdFFF = add_vertex(g6);
	    vdGGG = add_vertex(g6);
	    vdHHH = add_vertex(g6);
	    edAAABBB = add_edge(vdAAA, vdBBB, g6).first;
	    edAAACCC = add_edge(vdAAA, vdCCC, g6).first;
	    edAAAEEE = add_edge(vdAAA, vdEEE, g6).first;
	    edBBBDDD = add_edge(vdBBB, vdDDD, g6).first;
	    edBBBEEE = add_edge(vdBBB, vdEEE, g6).first;
	    edCCCDDD = add_edge(vdCCC, vdDDD, g6).first;
	    edDDDEEE = add_edge(vdDDD, vdEEE, g6).first;
	    edDDDFFF = add_edge(vdDDD, vdFFF, g6).first;
	    edFFFHHH = add_edge(vdFFF, vdHHH, g6).first;
	    edGGGHHH = add_edge(vdGGG, vdHHH, g6).first;
        */

        /*
	    //##############################        
	    //g12
	    vdA2 = add_vertex(g12);
	    vdB2 = add_vertex(g12);
	    vdC2 = add_vertex(g12);
	    vdD2 = add_vertex(g12);
	    vdE2 = add_vertex(g12);
	    vdF2 = add_vertex(g12);
	    vdG2 = add_vertex(g12);
	    vdH2 = add_vertex(g12);
	    edAB2 = add_edge(vdA2, vdB2, g12).first;
	    edAC2 = add_edge(vdA2, vdC2, g12).first;
	    edAE2 = add_edge(vdA2, vdE2, g12).first;
	    edBD2 = add_edge(vdB2, vdD2, g12).first;
	    edBE2 = add_edge(vdB2, vdE2, g12).first;
	    edCD2 = add_edge(vdC2, vdD2, g12).first;
	    edDE2 = add_edge(vdD2, vdE2, g12).first;
	    edDF2 = add_edge(vdD2, vdF2, g12).first;
	    edFD2 = add_edge(vdF2, vdD2, g12).first;
	    edFH2 = add_edge(vdF2, vdH2, g12).first;
	    edGH2 = add_edge(vdG2, vdH2, g12).first;
	    
	    //g32
	    vdI2 = add_vertex(g32);
	    vdJ2 = add_vertex(g32);
	    vdK2 = add_vertex(g32);
	    vdL2 = add_vertex(g32);
	    vdM2 = add_vertex(g32);
	    vdN2 = add_vertex(g32);
	    vdO2 = add_vertex(g32);
	    vdP2 = add_vertex(g32);
	    edIJ2 = add_edge(vdI2, vdJ2, g32).first;
	    edIK2 = add_edge(vdI2, vdK2, g32).first;
	    edIM2 = add_edge(vdI2, vdM2, g32).first;
	    edJL2 = add_edge(vdJ2, vdL2, g32).first;
	    edJM2 = add_edge(vdJ2, vdM2, g32).first;
	    edKL2 = add_edge(vdK2, vdL2, g32).first;
	    edLM2 = add_edge(vdL2, vdM2, g32).first;
	    edLN2 = add_edge(vdL2, vdN2, g32).first;
	    edNL2 = add_edge(vdN2, vdL2, g32).first;
	    edNP2 = add_edge(vdN2, vdP2, g32).first;
	    edOP2 = add_edge(vdO2, vdP2, g32).first;
	    
	    //g42
	    vdQ2 = add_vertex(g42);
	    vdR2 = add_vertex(g42);
	    edQR2 = add_edge(vdQ2, vdR2, g42).first;
	    
	    //g52
	    vdS2 = add_vertex(g52);
	    vdT2 = add_vertex(g52);
	    vdU2 = add_vertex(g52);
	    vdV2 = add_vertex(g52);
	    vdW2 = add_vertex(g52);
	    vdX2 = add_vertex(g52);
	    vdY2 = add_vertex(g52);
	    vdZ2 = add_vertex(g52);
	    vdAA2 = add_vertex(g52);
	    vdBB2 = add_vertex(g52);
	    vdCC2 = add_vertex(g52);
	    edBBCC2 = add_edge(vdBB2, vdCC2, g52).first;
	    
	    //g62
	    vdAAA2 = add_vertex(g62);
	    vdBBB2 = add_vertex(g62);
	    vdCCC2 = add_vertex(g62);
	    vdDDD2 = add_vertex(g62);
	    vdEEE2 = add_vertex(g62);
	    vdFFF2 = add_vertex(g62);
	    vdGGG2 = add_vertex(g62);
	    vdHHH2 = add_vertex(g62);
	    edAAABBB2 = add_edge(vdAAA2, vdBBB2, g62).first;
	    edAAACCC2 = add_edge(vdAAA2, vdCCC2, g62).first;
	    edAAAEEE2 = add_edge(vdAAA2, vdEEE2, g62).first;
	    edBBBDDD2 = add_edge(vdBBB2, vdDDD2, g62).first;
	    edBBBEEE2 = add_edge(vdBBB2, vdEEE2, g62).first;
	    edCCCDDD2 = add_edge(vdCCC2, vdDDD2, g62).first;
	    edDDDEEE2 = add_edge(vdDDD2, vdEEE2, g62).first;
	    edDDDFFF2 = add_edge(vdDDD2, vdFFF2, g62).first;
	    edFFFHHH2 = add_edge(vdFFF2, vdHHH2, g62).first;
	    edGGGHHH2 = add_edge(vdGGG2, vdHHH2, g62).first;
        */

	}
	
	virtual void TearDown() {
	}
};

// --------
// add_edge
// --------

TEST_F(MyGraphTest, AddEdgeTest1) {
    ASSERT_EQ(0, num_edges(gD));
    vertex_descriptor vdDA = add_vertex(gD);
    vertex_descriptor vdDB = add_vertex(gD);
    std::pair<edge_descriptor, bool> p = add_edge(vdDA, vdDB, gD);
    ASSERT_EQ(true, p.second);
    ASSERT_EQ(1, num_edges(gD));
}

 TEST_F(MyGraphTest, AddEdgeTest2) {
    ASSERT_EQ(11, num_edges(gA));
    std::pair<edge_descriptor, bool> p = add_edge(vdAA, vdAB, gA);
    ASSERT_EQ(edAAB, p.first);
    ASSERT_EQ(true, p.second == false);
    ASSERT_EQ(11, num_edges(gA));
}

 TEST_F(MyGraphTest, AddEdgeTest3) {
    ASSERT_EQ(0, num_edges(gD));
    ASSERT_EQ(0, num_vertices(gD));
    vertex_descriptor q = vertex(100, gD);
    vertex_descriptor r = vertex(101, gD);
    ASSERT_EQ(0, num_vertices(gD));
    std::pair<edge_descriptor, bool> p = add_edge(q, r, gD);
    ASSERT_EQ(1, num_edges(gD));
    ASSERT_EQ(102, num_vertices(gD));
}

// ----------
// add_vertex
// ----------

 TEST_F(MyGraphTest, AddVertexTest1) {
	ASSERT_EQ(0, num_vertices(gD));
	vertex_descriptor vd = 0;
	ASSERT_EQ(vd, add_vertex(gD));
	ASSERT_EQ(1, num_vertices(gD));

	vd = 1;
	ASSERT_EQ(vd, add_vertex(gD));
	ASSERT_EQ(2, num_vertices(gD));
}

 TEST_F(MyGraphTest, AddVertexTest2) {
	ASSERT_EQ(8, num_vertices(gA));
	vertex_descriptor vd = 8;
	ASSERT_EQ(vd, add_vertex(gA));
	ASSERT_EQ(9, num_vertices(gA));
}

// ------------
// num_vertices
// ------------

 TEST_F(MyGraphTest, NumVerticesTest1) {
	ASSERT_EQ(0, num_vertices(gD));
    vertex_descriptor vd = 0;
    ASSERT_EQ(vd, add_vertex(gD));
    vd = 1;
    ASSERT_EQ(vd, add_vertex(gD));
	ASSERT_EQ(2, num_vertices(gD));
}

 TEST_F(MyGraphTest, NumVerticesTest2) {
	ASSERT_EQ(8, num_vertices(gA));
	vertex_descriptor vd = 8;
    ASSERT_EQ(vd, add_vertex(gA));
    vd = 9;
    ASSERT_EQ(vd, add_vertex(gA)); 
    vd = 10;
    ASSERT_EQ(vd, add_vertex(gA));
    vd = 11;
    ASSERT_EQ(vd, add_vertex(gA));
	ASSERT_EQ(12, num_vertices(gA));
}

//********************************************

 TEST_F(MyGraphTest, NumEdgesTest1) {
	ASSERT_EQ(0, num_edges(gD));
}

 TEST_F(MyGraphTest, NumEdgesTest2) {
	ASSERT_EQ(11, num_edges(gA));
}

//********************************************
/*
 


 TEST_F(MyGraphTest, AdjacenctVerticesTest1) {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g1);
        adjacency_iterator b = p.first; 
        adjacency_iterator e = p.second;
        ASSERT_EQ(true, b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            ASSERT_EQ(true, vd == vdB);}
        ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            ASSERT_EQ(true, vd == vdC);}
	//#######################################
        std::pair<adjacency_iterator2, adjacency_iterator2> p2 = adjacent_vertices(vdA2, g12);
        adjacency_iterator2 b2 = p2.first; 
        adjacency_iterator2 e2 = p2.second;
        ASSERT_EQ(true, b2 != e2);
        if (b2 != e2) {
            vertex_descriptor2 vd2 = *b2;
            ASSERT_EQ(true, vd2 == vdB2);}
        ++b2;
        if (b2 != e2) {
            vertex_descriptor2 vd2 = *b2;
            ASSERT_EQ(true, vd2 == vdC2);}
}

 TEST_F(MyGraphTest, AdjacenctVerticesTest2) {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdQ, g4);
        adjacency_iterator b = p.first; 
        adjacency_iterator e = p.second;
        ASSERT_EQ(true, b != e);
        vertex_descriptor vd = *b;
        ASSERT_EQ(true, vd == vdR);
        ++b;
	ASSERT_EQ(true, b == e);
	
	add_edge(vdQ, vdQ, g4);
        p = adjacent_vertices(vdQ, g4);
        b = p.first; 
        e = p.second;
        ASSERT_EQ(true, b != e);
        vd = *b;
        ASSERT_EQ(true, vd == vdQ);
        ++b;
        vd = *b;
        ASSERT_EQ(true, vd == vdR);
	++b;
	ASSERT_EQ(true, b == e);
	
	//#######################################
        std::pair<adjacency_iterator2, adjacency_iterator2> p2 = adjacent_vertices(vdQ2, g42);
        adjacency_iterator2 b2 = p2.first; 
        adjacency_iterator2 e2 = p2.second;
        ASSERT_EQ(true, b2 != e2);
        vertex_descriptor vd2 = *b2;
        ASSERT_EQ(true, vd2 == vdR2);
        ++b2;
	ASSERT_EQ(true, b2 == e2);
	
	add_edge(vdQ2, vdQ2, g42);
        p2 = adjacent_vertices(vdQ2, g42);
        b2 = p2.first; 
        e2 = p2.second;
        ASSERT_EQ(true, b2 != e2);
        vd2 = *b2;
        ASSERT_EQ(true, vd2 == vdQ2);
        ++b2;
        vd2 = *b2;
        ASSERT_EQ(true, vd2 == vdR2);
	++b2;
	ASSERT_EQ(true, b2 == e2);
}



 TEST_F(MyGraphTest, EdgeTest1) {
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
	// produces runtime-error
        //std::pair<edge_descriptor, bool> p = edge(vdA, vdB, g2);
        //ASSERT_EQ(true, p.first  == edAB);
	//ASSERT_EQ(true, p.second == true);
	//#######################################
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
	// produces runtime-error
        //std::pair<edge_descriptor2, bool> p2 = edge(vdA2, vdB2, g22);
        //ASSERT_EQ(true, p2.first  == edAB2);
	//ASSERT_EQ(true, p2.second == true);
}

 TEST_F(MyGraphTest, EdgeTest2) {
	ASSERT_EQ(0, edAB.m_source);
	ASSERT_EQ(1, edAB.m_target);
	ASSERT_EQ(11, num_edges(g1));
	ASSERT_EQ(8, num_vertices(g1));
        std::pair<edge_descriptor, bool> p = edge(vdA, vdB, g1);
	ASSERT_EQ(11, num_edges(g1));
	ASSERT_EQ(8, num_vertices(g1));
        ASSERT_EQ(0, p.first.m_source);
        ASSERT_EQ(1, p.first.m_target);
	ASSERT_EQ(0, edAB.m_source);
	ASSERT_EQ(1, edAB.m_target);
        ASSERT_EQ(true, p.first  == edAB);
        ASSERT_EQ(true, p.second == true);
	//#######################################
	ASSERT_EQ(0, edAB2.first);
	ASSERT_EQ(1, edAB2.second);
	ASSERT_EQ(11, num_edges(g12));
	ASSERT_EQ(8, num_vertices(g12));
        std::pair<edge_descriptor2, bool> p2 = edge(vdA2, vdB2, g12);
	ASSERT_EQ(11, num_edges(g12));
	ASSERT_EQ(8, num_vertices(g12));
        ASSERT_EQ(0, p2.first.first);
        ASSERT_EQ(1, p2.first.second);
	ASSERT_EQ(0, edAB2.first);
	ASSERT_EQ(1, edAB2.second);
        ASSERT_EQ(true, p2.first  == edAB2);
        ASSERT_EQ(true, p2.second == true);
}

 TEST_F(MyGraphTest, EdgeTest3) {
	ASSERT_EQ(11, num_edges(g1));
	ASSERT_EQ(8, num_vertices(g1));
	ASSERT_EQ(9, vdBB);
	ASSERT_EQ(10, vdCC);
        //std::pair<edge_descriptor, bool> p = edge(vdBB, vdCC, g1);
	// ___ASSERT_EQ(11, num_edges(g1));
	//ASSERT_EQ(8, num_vertices(g1));
        //ASSERT_EQ(9, p.first.m_source);
        //ASSERT_EQ(10, p.first.m_target);
	//ASSERT_EQ(9, edBBCC.m_source);
	//ASSERT_EQ(10, edBBCC.m_target);
	
	// extra wrinkle/detail of edge_descriptor: why does/should the ASSERT_EQ below work??
        //ASSERT_EQ(false, p.first == edBBCC);
        //ASSERT_EQ(true, p.second == false);^^^
	//#######################################
	// ___
	//ASSERT_EQ(11, num_edges(g12));
	//ASSERT_EQ(8, num_vertices(g12));
	//ASSERT_EQ(9, vdBB2);
	//ASSERT_EQ(10, vdCC2);
        //std::pair<edge_descriptor2, bool> p2 = edge(vdBB2, vdCC2, g12);
	//ASSERT_EQ(11, num_edges(g12));
	//ASSERT_EQ(8, num_vertices(g12));
        //ASSERT_EQ(9, p2.first.first);
        //ASSERT_EQ(10, p2.first.second);
	//ASSERT_EQ(9, edBBCC2.first);
	//ASSERT_EQ(10, edBBCC2.second);
	// NOTICE: the assertion below fails b/c p2.first == edBBCC2 is true
        // ASSERT_EQ(false, p2.first == edBBCC2);
        //ASSERT_EQ(true, p2.second == false);
        // ^^^
}

 TEST_F(MyGraphTest, EdgesTest1) {
        std::pair<edge_iterator, edge_iterator> p = edges(g2);
        edge_iterator                           b = p.first;
        edge_iterator                           e = p.second;
        ASSERT_EQ(true, b == e);
	//#######################################
        std::pair<edge_iterator2, edge_iterator2> p2 = edges(g22);
        edge_iterator2                           b2 = p2.first;
        edge_iterator2                           e2 = p2.second;
        ASSERT_EQ(true, b2 == e2);
}

 TEST_F(MyGraphTest, EdgesTest2) {
        std::pair<edge_iterator, edge_iterator> p = edges(g1);
        edge_iterator                           b = p.first;
        edge_iterator                           e = p.second;
        ASSERT_EQ(true, b != e);
        if (b != e) {
            edge_descriptor ed = *b;
            ASSERT_EQ(true, ed == edAB);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            ASSERT_EQ(true, ed == edAC);}
	//#######################################
        std::pair<edge_iterator2, edge_iterator2> p2 = edges(g12);
        edge_iterator2                           b2 = p2.first;
        edge_iterator2                           e2 = p2.second;
        ASSERT_EQ(true, b2 != e2);
        if (b2 != e2) {
            edge_descriptor2 ed2 = *b2;
            ASSERT_EQ(true, ed2 == edAB2);}
        ++b2;
        if (b2 != e2) {
            edge_descriptor2 ed2 = *b2;
            ASSERT_EQ(true, ed2 == edAC2);}
}



 TEST_F(MyGraphTest, SourceTest1) {
	// NOTICE: source() doesn't care if the 
	// edge_descriptor is in the graph that
	// you give it, so long as the 
	// edge_descriptor is in scope
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
        vertex_descriptor vd = source(edAB, g2);
        ASSERT_EQ(true, vd == vdA);
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
	//#######################################
	// NOTICE: source() doesn't care if the 
	// edge_descriptor is in the graph that
	// you give it, so long as the 
	// edge_descriptor is in scope
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
        vertex_descriptor2 vd2 = source(edAB2, g22);
        ASSERT_EQ(true, vd2 == vdA2);
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
}

 TEST_F(MyGraphTest, SourceTest2) {
        vertex_descriptor vd = source(edAB, g1);
        ASSERT_EQ(true, vd == vdA);
	//#######################################
        vertex_descriptor2 vd2 = source(edAB2, g12);
        ASSERT_EQ(true, vd2 == vdA2);
}



 TEST_F(MyGraphTest, TargetTest1) {
	// NOTICE: target() doesn't care if the 
	// edge_descriptor is in the graph that
	// you give it, so long as the 
	// edge_descriptor is in scope
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
        vertex_descriptor vd = target(edAB, g2);
        ASSERT_EQ(true, vd == vdB);
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
	//#######################################
	// NOTICE: target() doesn't care if the 
	// edge_descriptor is in the graph that
	// you give it, so long as the 
	// edge_descriptor is in scope
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
        vertex_descriptor2 vd2 = target(edAB2, g22);
        ASSERT_EQ(true, vd2 == vdB2);
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
}

 TEST_F(MyGraphTest, TargetTest2) {
        vertex_descriptor vd = target(edAB, g1);
        ASSERT_EQ(true, vd == vdB);
	//#######################################
        vertex_descriptor2 vd2 = target(edAB2, g12);
        ASSERT_EQ(true, vd2 == vdB2);
}



 TEST_F(MyGraphTest, VertexTest1) {
	//NOTICE: vertex() doesn't require that
	// the vertex be in the graph given to
	// it ie vertex(vertex_descriptor, graph)
   
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
        vertex_descriptor vd = vertex(0, g2);
        ASSERT_EQ(true, vd == vdA);
        ASSERT_EQ(true, vd == vdI);
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
	
   
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
        vertex_descriptor2 vd2 = vertex(0, g22);
        ASSERT_EQ(true, vd2 == vdA2);
        ASSERT_EQ(true, vd2 == vdI2);
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
}

 TEST_F(MyGraphTest, VertexTest2) {
        vertex_descriptor vd = vertex(0, g1);
        ASSERT_EQ(true, vd == vdA);
	
        vertex_descriptor2 vd2 = vertex(0, g12);
        ASSERT_EQ(true, vd2 == vdA2);
}

 TEST_F(MyGraphTest, VertexTest3) {
	// vertex() seems to act like a 
	// vertex_descriptor constructor
	int wayOutOfRange = 1000;
        vertex_descriptor vd = vertex(wayOutOfRange, g1);
        ASSERT_EQ(true, vd == wayOutOfRange);
	vertex_descriptor vd1 = vd;
	vd = 80;
        ASSERT_EQ(true, vd == 80);
        ASSERT_EQ(true, vd != wayOutOfRange);
        ASSERT_EQ(true, vd1 != 80);
        ASSERT_EQ(true, vd1 == wayOutOfRange);
	//#######################################
	// vertex() seems to act like a 
	// vertex_descriptor constructor
	int wayOutOfRange2 = 1000;
        vertex_descriptor2 vd2 = vertex(wayOutOfRange2, g12);
        ASSERT_EQ(true, vd2 == wayOutOfRange2);
	vertex_descriptor2 vd12 = vd2;
	vd2 = 80;
        ASSERT_EQ(true, vd2 == 80);
        ASSERT_EQ(true, vd2 != wayOutOfRange2);
        ASSERT_EQ(true, vd12 != 80);
        ASSERT_EQ(true, vd12 == wayOutOfRange2);
}



 TEST_F(MyGraphTest, VerticesTest1) {
        std::pair<vertex_iterator, vertex_iterator> p = vertices(g2);
        vertex_iterator                             b = p.first;
        vertex_iterator                             e = p.second;
        ASSERT_EQ(true, b == e);
	//#######################################
        std::pair<vertex_iterator2, vertex_iterator2> p2 = vertices(g22);
        vertex_iterator2                             b2 = p2.first;
        vertex_iterator2                             e2 = p2.second;
        ASSERT_EQ(true, b2 == e2);
}

 TEST_F(MyGraphTest, VerticesTest2) {
        std::pair<vertex_iterator, vertex_iterator> p = vertices(g1);
        vertex_iterator                             b = p.first;
        vertex_iterator                             e = p.second;
        ASSERT_EQ(true, b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            ASSERT_EQ(true, vd == vdA);}
        ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            ASSERT_EQ(true, vd == vdB);}
	//#######################################
        std::pair<vertex_iterator2, vertex_iterator2> p2 = vertices(g12);
        vertex_iterator2                             b2 = p2.first;
        vertex_iterator2                             e2 = p2.second;
        ASSERT_EQ(true, b2 != e2);
        if (b2 != e2) {
            vertex_descriptor vd2 = *b2;
            ASSERT_EQ(true, vd2 == vdA2);}
        ++b2;
        if (b2 != e2) {
            vertex_descriptor vd2 = *b2;
            ASSERT_EQ(true, vd2 == vdB2);}
}



  TEST_F(MyGraphTest, HasCycleTest1){
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
	ASSERT_EQ(false, has_cycle(g2));
	ASSERT_EQ(0, num_edges(g2));
	ASSERT_EQ(0, num_vertices(g2));
	//#######################################
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
	ASSERT_EQ(false, has_cycle(g22));
	ASSERT_EQ(0, num_edges(g22));
	ASSERT_EQ(0, num_vertices(g22));
}

 TEST_F(MyGraphTest, HasCycleTest2) {
	ASSERT_EQ(true, has_cycle(g1));
	//#######################################
	ASSERT_EQ(true, has_cycle(g12));
}

  TEST_F(MyGraphTest, HasCycleTest3){
	ASSERT_EQ(1, num_edges(g4));
	ASSERT_EQ(2, num_vertices(g4));
	ASSERT_EQ(false, has_cycle(g4));
	ASSERT_EQ(1, num_edges(g4));
	ASSERT_EQ(2, num_vertices(g4));
	//#######################################
	ASSERT_EQ(1, num_edges(g42));
	ASSERT_EQ(2, num_vertices(g42));
	ASSERT_EQ(false, has_cycle(g42));
	ASSERT_EQ(1, num_edges(g42));
	ASSERT_EQ(2, num_vertices(g42));
}

  TEST_F(MyGraphTest, HasCycleTest4){
	ASSERT_EQ(10, num_edges(g6));
	ASSERT_EQ(8, num_vertices(g6));
	ASSERT_EQ(false, has_cycle(g6));
	ASSERT_EQ(10, num_edges(g6));
	ASSERT_EQ(8, num_vertices(g6));
	//#######################################
	ASSERT_EQ(10, num_edges(g62));
	ASSERT_EQ(8, num_vertices(g62));
	ASSERT_EQ(false, has_cycle(g62));
	ASSERT_EQ(10, num_edges(g62));
	ASSERT_EQ(8, num_vertices(g62));
}

 TEST_F(MyGraphTest, HasCycleTest5) {
	//add self-loop
	
	ASSERT_EQ(false, has_cycle(g6));
	
	ASSERT_EQ(10, num_edges(g6));
	ASSERT_EQ(8, num_vertices(g6));
	std::pair<edge_descriptor, bool> p = add_edge(vdAAA, vdAAA, g6);
	ASSERT_EQ(0, p.first.m_source);
	ASSERT_EQ(0, p.first.m_target);
	ASSERT_EQ(true, p.second == true);
	ASSERT_EQ(11, num_edges(g6));
	ASSERT_EQ(8, num_vertices(g6));
	
	ASSERT_EQ(true, has_cycle(g6));
	
	ASSERT_EQ(11, num_edges(g6));
	ASSERT_EQ(8, num_vertices(g6));
	//#######################################
	//add self-loop
	
	ASSERT_EQ(false, has_cycle(g62));
	
	ASSERT_EQ(10, num_edges(g62));
	ASSERT_EQ(8, num_vertices(g62));
	std::pair<edge_descriptor2, bool> p2 = add_edge(vdAAA2, vdAAA2, g62);
	ASSERT_EQ(0, p2.first.first);
	ASSERT_EQ(0, p2.first.second);
	ASSERT_EQ(true, p2.second == true);
	ASSERT_EQ(11, num_edges(g62));
	ASSERT_EQ(8, num_vertices(g62));
	
	ASSERT_EQ(true, has_cycle(g62));
	
	ASSERT_EQ(11, num_edges(g62));
	ASSERT_EQ(8, num_vertices(g62));
}


  TEST_F(MyGraphTest, TopologicalSortTest1){
        std::ostringstream out;
        topological_sort(g2, std::ostream_iterator<vertex_descriptor>(out, " "));
        ASSERT_EQ(true, out.str() == "");
	//#######################################
        std::ostringstream out2;
        topological_sort(g22, std::ostream_iterator<vertex_descriptor2>(out2, " "));
        ASSERT_EQ(true, out2.str() == "");
}

 TEST_F(MyGraphTest, TopologicalSortTest2) {
        std::ostringstream out;
	try {
	    topological_sort(g1, std::ostream_iterator<vertex_descriptor>(out, " "));
	    ASSERT_EQ(false, true); // must fail if reaches this point
	} catch (const boost::not_a_dag& e){
	    ASSERT_EQ("The graph must be a DAG.",  std::string(e.what()));
	}
	//#######################################
        std::ostringstream out2;
	try {
	    topological_sort(g12, std::ostream_iterator<vertex_descriptor2>(out2, " "));
	    ASSERT_EQ(false, true); // must fail if reaches this point
	} catch (const boost::not_a_dag& e2){
	    ASSERT_EQ("The graph must be a DAG.",  std::string(e2.what()));
	}
}

  TEST_F(MyGraphTest, TopologicalSortTest3){
        std::ostringstream out;
        topological_sort(g4, std::ostream_iterator<vertex_descriptor>(out, " "));
        ASSERT_EQ("1 0 ",out.str());
	//#######################################
        std::ostringstream out2;
        topological_sort(g42, std::ostream_iterator<vertex_descriptor2>(out2, " "));
        ASSERT_EQ("1 0 ",out2.str());
}

  TEST_F(MyGraphTest, TopologicalSortTest4){
        std::ostringstream out;
        topological_sort(g6, std::ostream_iterator<vertex_descriptor>(out, " "));
        ASSERT_EQ("4 7 5 3 1 2 0 6 ", out.str());
	//#######################################
        std::ostringstream out2;
        topological_sort(g62, std::ostream_iterator<vertex_descriptor2>(out2, " "));
        ASSERT_EQ("4 7 5 3 1 2 0 6 ", out2.str());
}



  TEST_F(MyGraphTest, DefaultConstructorTest1){
      graph_type gr;
      ASSERT_EQ(0, num_vertices(gr));
      ASSERT_EQ(0, num_edges(gr));
      //#######################################
      graph_type2 gr2;
      ASSERT_EQ(0, num_vertices(gr2));
      ASSERT_EQ(0, num_edges(gr2));
  }


  TEST_F(MyGraphTest, ValidTest1){
      graph_type gr;
      ASSERT_EQ("the default constructor's assert(valid()) did not fail if this assert runs", "the default constructor's assert(valid()) did not fail if this assert runs");
      //#######################################
      graph_type2 gr2;
      ASSERT_EQ("the default constructor's assert(valid()) did not fail if this assert runs", "the default constructor's assert(valid()) did not fail if this assert runs");
  }


  TEST_F(MyGraphTest, HasCycleHelperTest1){
    std::vector<bool> explored;
    for (int i = 0; i < num_vertices(g1); ++i){
	explored.push_back(false);
    }
    bool result = false;
    ASSERT_EQ(true, has_cycle_helper(g1, 0, explored, result));
    //#######################################
    std::vector<bool> explored2;
    for (int i = 0; i < num_vertices(g12); ++i){
	explored2.push_back(false);
    }
    bool result2 = false;
    ASSERT_EQ(true, has_cycle_helper(g12, 0, explored, result2));
  }

  TEST_F(MyGraphTest, HasCycleHelperTest2){
    std::vector<bool> explored;
    for (int i = 0; i < num_vertices(g6); ++i){
	explored.push_back(false);
    }
    bool result = false;
    ASSERT_EQ(false, has_cycle_helper(g6, 0, explored, result));
    //#######################################
    std::vector<bool> explored2;
    for (int i = 0; i < num_vertices(g62); ++i){
	explored2.push_back(false);
    }
    bool result2 = false;
    ASSERT_EQ(false, has_cycle_helper(g62, 0, explored, result2));
  }

  TEST_F(MyGraphTest, HasCycleHelperTest3){
    std::vector<bool> explored;
    for (int i = 0; i < num_vertices(g5); ++i){
	explored.push_back(false);
    }
    bool result = false;
    ASSERT_EQ(false, has_cycle_helper(g5, 0, explored, result));
    //#######################################
    std::vector<bool> explored2;
    for (int i = 0; i < num_vertices(g52); ++i){
	explored2.push_back(false);
    }
    bool result2 = false;
    ASSERT_EQ(false, has_cycle_helper(g52, 0, explored, result2));
  }

  TEST_F(MyGraphTest, DefaultCopyConstructorTest1){
      graph_type gr(g4);
      ASSERT_EQ(2, num_vertices(gr));
      ASSERT_EQ(1, num_edges(gr));
      ASSERT_EQ(true, edge(vdQ, vdR, gr).second);
      //#######################################
      graph_type2 gr2(g42);
      ASSERT_EQ(2, num_vertices(gr2));
      ASSERT_EQ(1, num_edges(gr2));
      ASSERT_EQ(true, edge(vdQ2, vdR2, gr2).second);
  }



  TEST_F(MyGraphTest, DefualtCopyAssignmentTest1){
      g1 = g4;
      ASSERT_EQ(2, num_vertices(g1));
      ASSERT_EQ(1, num_edges(g1));
      ASSERT_EQ(true, edge(vdQ, vdR, g1).second);
      //#######################################
      g12 = g42;
      ASSERT_EQ(2, num_vertices(g12));
      ASSERT_EQ(1, num_edges(g12));
      ASSERT_EQ(true, edge(vdQ2, vdR2, g12).second);

  }
  */