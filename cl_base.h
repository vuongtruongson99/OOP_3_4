#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class cl_base
{
private:
	string m_name;
	cl_base* m_parent;
	int m_state;

public:
	vector<cl_base*> m_child;
	cl_base(cl_base* parent);
	cl_base(string name, cl_base* parent, int state);
	cl_base();
	void set_object_name(string name);
	string get_object_name();
	void set_object_state(int state);
	int get_object_state();
	void add_child(cl_base* child);
	void get_child();
	void show_state(cl_base* next, int cnt);
	
	//K_L_3_4
	void set_connection(vector<pair<int, pair<string, string>>> connection); 
};