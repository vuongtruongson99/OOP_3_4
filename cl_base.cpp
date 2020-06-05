#include "cl_base.h"

cl_base::cl_base() {

}

cl_base::cl_base(cl_base* parent) {
	m_parent = parent;
}

cl_base::cl_base(string name, cl_base* parent, int state)
{
	m_name = name;
	m_parent = parent;
	m_state = state;
}

void cl_base::set_object_name(string name) {
	m_name = name;
}

void cl_base::set_object_state(int state) {
	m_state = state;
}

int cl_base::get_object_state() {
	return m_state;
}

string cl_base::get_object_name() {
	return m_name;
}

void cl_base::add_child(cl_base* child) {
	m_child.push_back(child);
}

void cl_base::get_child() {
	cout << get_object_name();
	for (auto x : m_child) {
		cout << "  " << x->get_object_name();
	}
}

void cl_base::show_state(cl_base* next, int cnt) {
	cout << next->get_object_name();

	if (next->m_child.size() == 0) return;
	else {
		cout << endl;
		for (int i = 0; i < next->m_child.size(); ++i) {
			for (int j = 0; j < cnt * 4; ++j) {
				cout << " ";
			}
			show_state(next->m_child[i], cnt + 1);
			if (i < next->m_child.size() - 1) cout << endl;
		}
	}
}

void cl_base::set_connection(vector<pair<int, pair<string, string>>> connection) {
	cout << "Set connects";
	for (int i = 0; i < connection.size(); ++i) {
		cout << endl << connection[i].first << " " << connection[i].second.first << " " << connection[i].second.second;
	}
}

//void cl_base::emit_signals(vector <cl_application*> Derived, vector<pair<int, pair<string, string>>> connection, vector<pair<string, string>> obj_mes) {

//}