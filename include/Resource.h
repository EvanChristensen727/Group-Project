#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>

using namespace std;

class Resource{

	public:
		Resource();
		Resource(string resource_ID, string name, string type, bool available);
		bool getAvailable();
		void setAvailable(bool state);
		string getResource_ID();
		void setResource_ID(string r_ID);
		string getName();
		void setName(string name);
		string getType();
		void setType(string type);

	private:
		string resource_ID;
		string name;
		string type;
		bool available;
};


class ResourceManager{
	public:
		void getFromFile();
		void displayResources();
		//void searchResources(string criteria);
		//void sortResources(string criteria); //not sure about this one yet
		void setResourceAvailability(string r_ID, bool state); // mutator that iterates throught the vector for ID, then changes state to provided state.
		bool resourceExists(string r_ID); // accessor that iterates through the vector for a given string ID then returns if the ID exists
		bool isAvailable(string r_ID);  //accessor that iterates through the vector for a given string ID then returns the state of the ID
	private:
	 	vector<Resource> Resource_List; 
};

#endif
