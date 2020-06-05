#include "cl_application.h"
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"

cl_application::cl_application() {

}

cl_base* cl_application::findObjectPointer OBJECT{
	for (int i = 0; i < Derived.size(); ++i) {
		if (Derived[i]->get_object_name() == signal) {
			return Derived[i];
		}
	}
	return NULL;
}

void cl_application::input(string& s) {
	getline(cin, s);
}

void cl_application::format_input(string s, vector<string>& format) {
	string temp;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ') {
			temp += s[i];
		}
		else {
			format.push_back(temp);
			temp = "";
		}
	}
	format.push_back(temp);
}

void cl_application::cal(vector<string>& ans, vector<string> format) {
	int answer = -1;
	for (int i = 1; i < format.size() - 1; i += 2) {
		string symbol = format[i];
		if (symbol == "+") {
			if (answer == -1) {
				int first, second;
				istringstream(format[i - 1]) >> first;
				istringstream(format[i + 1]) >> second;
				answer = first + second;
				string ok = to_string(first) + " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
			else {
				int second;
				istringstream(format[i + 1]) >> second;
				string ok = to_string(answer);
				answer += second;
				ok += " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
		}
		else if (symbol == "-") {
			if (answer == -1) {
				int first, second;
				istringstream(format[i - 1]) >> first;
				istringstream(format[i + 1]) >> second;
				answer = first - second;
				string ok = to_string(first) + " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
			else {
				int second;
				istringstream(format[i + 1]) >> second;
				string ok = to_string(answer);
				answer -= second;
				ok += " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
		}
		else if (symbol == "*") {
			if (answer == -1) {
				int first, second;
				istringstream(format[i - 1]) >> first;
				istringstream(format[i + 1]) >> second;
				answer = first * second;
				string ok = to_string(first) + " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
			else {
				int second;
				istringstream(format[i + 1]) >> second;
				string ok = to_string(answer);
				answer *= second;
				ok += " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
		}
		else if (symbol == "%") {
			if (answer == -1) {
				int first, second;
				istringstream(format[i - 1]) >> first;
				istringstream(format[i + 1]) >> second;
				answer = first % second;
				string ok = to_string(first) + " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
			else {
				int second;
				istringstream(format[i + 1]) >> second;
				string ok = to_string(answer);
				answer %= second;
				ok += " " + symbol + " " + to_string(second) + " = " + to_string(answer);
				ans.push_back(ok);
			}
		}

	}
}

void cl_application::output(vector<string> ans) {
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i < ans.size() - 1) cout << endl;
	}
}

void cl_application::addSignal SIGNAL{
	signalTrans.push_back(signal_trans);
	signalRec.push_back(signal_rec);
}

void cl_application::deleteSignal() {
	for (int i = 0; i < signalTrans.size(); ++i) {
		if (signalTrans[i] == NULL || signalRec[i] == NULL) {
			signalTrans.erase(signalTrans.begin() + i);
			signalRec.erase(signalRec.begin() + i);
		}
	}
	for (int i = 0; i < signaling.size(); ++i) {
		if (signaling[i] == NULL) {
			signaling.erase(signaling.begin() + i);
			contentTrans.erase(contentTrans.begin() + i);
		}
	}
}

void cl_application::addHendler HENDLER{
	signaling.push_back(signaLing);
	contentTrans.push_back(content);
}

void cl_application::setConnect(vector<int> s_num, vector<string> s_trans, vector<string> s_rec) {
	cout << endl << "Set connects";
	for (int i = 0; i < s_num.size(); ++i) {
		cout << endl << s_num[i] << " " << s_trans[i] << " " << s_rec[i];
	}
	cout << endl;
}

void cl_application::handleSignal() {
	deleteSignal();
	cout << "Emmit signals";
	for (int i = 0; i < signaling.size(); ++i) {
		for (int j = 0; j < signalTrans.size(); ++j) {
			if (signaling[i] == signalTrans[j]) {
				cout << endl << "Signal to " << signalRec[j]->get_object_name() << " Text: " << signalTrans[j]->get_object_name() << " -> " << contentTrans[i];
			}
		}
	}
}

void cl_application::bild_object_tree() {
	string s;
	cin >> s;
	vector <cl_base*> Derived; //store nodes;
	string parent, child;
	int cl, state;

	this->set_object_name(s);
	this->set_object_state(1);
	
	Derived.push_back(this);	
	cin >> parent;

	if (parent == "endtree") {
		cout << "Object tree" << endl;
		cout << this->get_object_name() << endl;

		vector<pair<int, pair<string, string>>> connection;

		while (1) {
			int in_signal;
			cin >> in_signal;
			if (in_signal == 0) break;
			string in_current, in_target;
			cin >> in_current >> in_target;
			connection.push_back({ in_signal, {in_current, in_target} });
		}

		//Set send message
		vector<pair<string, string>> obj_mes;

		while (1) {
			string obj, mes;
			cin >> obj;
			if (obj == "endsignals") break;
			cin >> mes;
			obj_mes.push_back({ obj, mes });
		}

		set_connection(connection);
		return;
	}
	cin >> child >> cl >> state;

	cl_base* nodes1;
	cl_2* nodes2;
	cl_3* nodes3;
	while (1) {
		for (int i = 0; i < Derived.size(); ++i) {
			if (Derived[i]->get_object_name() == parent) {
				if (Derived[i]->get_object_state() <= 0) state = 0;

				if (Derived[i]->get_object_name() == child) state = 0;
				switch (cl)
				{
				case 2:
					nodes2 = new cl_2(child, Derived[i], state);
					Derived[i]->m_child.push_back(nodes2);
					Derived.push_back(nodes2);
					break;
				case 3:
					nodes3 = new cl_3(child, Derived[i], state);
					Derived[i]->m_child.push_back(nodes3);
					Derived.push_back(nodes3);
					break;
				default:
					nodes1 = new cl_base(child, Derived[i], state);
					Derived[i]->m_child.push_back(nodes1);
					Derived.push_back(nodes1);
					break;
				}
			}
		}

		cin >> parent;
		if (parent == "endtree") break;
		cin >> child >> cl >> state;
	}

	cout << "Object tree" << endl;
	cout << this->get_object_name() << endl;

	for (int i = 0; i < this->m_child.size(); ++i) {
		cout << "    ";
		show_state(this->m_child[i], 2);
		if (i < this->m_child.size() - 1) {
			cout << endl;
		}
	}	
	//-------------Lab 3_4---------------------	
	//Set connection
	cl_application pa(NULL);
	vector<string> s_trans, s_rec;
	vector<int> s_num;

	while (1) {
		int signal_num;
		string signal_trans, signal_rec;
		cin >> signal_num;
		if (signal_num == 0) break;
		cin >> signal_trans >> signal_rec;
		s_num.push_back(signal_num);
		s_trans.push_back(signal_trans);
		s_rec.push_back(signal_rec);
		pa.addSignal(pa.findObjectPointer(Derived, signal_trans), pa.findObjectPointer(Derived, signal_rec));
	}
	while (1) {
		string signaling, content_trans;
		cin >> signaling;
		if (signaling == "endsignals") break;
		cin >> content_trans;
		pa.addHendler(pa.findObjectPointer(Derived, signaling), content_trans);
	}
	pa.setConnect(s_num, s_trans, s_rec);
	pa.handleSignal();
}

//root
//root ob1 2 1
//root ob2 2 1
//ob1 ob3 6 1
//ob2 ob4 5 1
//endtree
////ob1
////ob2
//root/ob1
//root/ob1/ob3
//root/ob3
//root/ob1/ob4
////