#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H
#include "cl_base.h"
#include <sstream>

#define signal_1 1
#define signal_2 2
#define signal_3 3
#define SIGNAL (cl_base* signal_trans, cl_base* signal_rec)
#define HENDLER (cl_base* signaLing, string content)
#define OBJECT (vector<cl_base*> Derived, string signal)

class cl_application : public cl_base {
public:
	vector<cl_base*> signalTrans, signalRec, signaling;
	vector<string> contentTrans;
	cl_base* findObjectPointer OBJECT;

	/*
		Constructor of derived class
		@param s Name of derived object
		@param parent Pointer to parent object
		@param state State of object (ON/OFF)
	*/
	cl_application();
	cl_application(string s, cl_base* parent, int state) : cl_base(s, parent, state) {};
	cl_application(cl_base* parent) : cl_base(parent) {};

	/*
		Add handlers for the object
		@param signaLing Pointer to object transfer data
		@param content Data to transfer
	*/
	void addHendler HENDLER;

	/*
		Add signal for the object
		@param signal_trans Pointer to object transfer data
		@param signal_rec Pointer to object receive data
	*/
	void addSignal SIGNAL;

	/*
		Ser connection between 2 object
		@param s_num Set of signals
		@param s_trans Set of data transfer object
		@param s_rec Set of data receive object
	*/
	void setConnect(vector<int> s_num, vector<string> s_trans, vector<string> s_rec);

	/*
		Building object trees
	*/
	void bild_object_tree();

	/*
		Delete old signal
	*/
	void deleteSignal();

	/*
		`Processing signal has been set
	*/
	void handleSignal();

	/*
		Enter the operation
		@param s Sequence of operations
	*/
	void input(string& s);

	/*
		Format the sequence of operations to process
		@param s Sequence of operations
		@param format Store new format of sequence operations
	*/
	void format_input(string s, vector<string>& format);

	/*
		Perform the calculation
		@param ans Store answer of each operation
		@param format Store new format of sequence operations
	*/
	void cal(vector<string>& ans, vector<string> format);

	/*
		Print out each calculation
		@param ans Store answer of each operation
	*/
	void output(vector<string> ans);
};
#endif