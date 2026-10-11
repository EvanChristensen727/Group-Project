#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include "Resource.h"

Resource::Resource(){
	resource_ID = "NONE";
	name = "NONE";
	type = "NONE";
	available = false;
};

Resource::Resource(string resource_ID, string name, string type, bool available){
	this->resource_ID = resource_ID;
	this->name = name;
	this->type = type;
	this->available = available;
}


string Resource::getResource_ID()
{
	return resource_ID;
}

void Resource::setResource_ID(string resource_ID){
	this->resource_ID = resource_ID;
}

string Resource::getName(){
	return name;
}

void Resource::setName(string name){
	this->name = name;
}

string Resource::getType(){
	return type;
}

void Resource::setType(string type){
	this->type = type;
}

bool Resource::getAvailable(){
	return available;
}

void Resource::setAvailable(bool state){
	available = state;
}

//TODO ResourceManager
void ResourceManager::getFromFile()
{
	string line;
	string id;
	string name;
	string type;
	string status;
	bool state;
	

	ifstream inputFile("data/resources.txt");

	if(!inputFile.is_open()){
		std::cout << "ERROR: Unable to open resource file" << endl;
		return;
	}
	while (getline(inputFile, line)){
		std::stringstream ss(line);
		getline(ss, id, '|');
		getline(ss, name, '|');
		getline(ss, type, '|');
		getline(ss, status);
		
		state = (status == "Available") ? true : false;
		Resource current(id, name ,type, state);
		Resource_List.push_back(current);
	}
}

void ResourceManager::displayResources(){
	for (auto it : Resource_List){
		cout << it.getResource_ID() << " | " << it.getName() << " | " << it.getType() << " | " << it.getAvailable() << endl;
	}
}

void ResourceManager::setResourceAvailability(string id, bool state){
	for (auto& it : Resource_List){
		if (it.getResource_ID() == id)
		{
			it.setAvailable(state);
			return;
		}
	}
}

bool ResourceManager::isAvailable(string r_ID){
	for (auto& it : Resource_List){
		if (it.getResource_ID() == r_ID)
		{
			return it.getAvailable();
		}
	}	
	
	cout << "Error No such Resource." << endl;
	return false;			
}

bool ResourceManager::resourceExists(string r_ID){
	for (auto& it : Resource_List){
		if (it.getResource_ID() == r_ID)
		{
			return true;
		}
	}
	
	return false;
}
//Merge sort subsection
void ResourceManager::sortResources(string sort){ //set as a seperate function for the main call for main clarity and to be update infuture for other sort options
	if (sort == "name" && !Resource_List.empty()){
		mergeSort(0, Resource_List.size() - 1);
	}
}

void ResourceManager::merge(int left,int mid, int right){ //this merges the the subvectors backgether sorting them as the are merged up
	vector<Resource> temp;

	int i = left;
	int j = mid+1;

	while (i <= mid && j <= right) {
		if (Resource_List[i].getName() <= Resource_List[j].getName()){
			temp.push_back(Resource_List[i]);
			i++;
		}
		else {
			temp.push_back(Resource_List[j]);
			j++;
		}
	}

	while (i <= mid) {
		temp.push_back(Resource_List[i]);
		i++;
	}

	while (j <= right) {
		temp.push_back(Resource_List[j]);
		j++;
	}

	for (int k = 0; k < static_cast<int>(temp.size()); k++) {
		Resource_List[left + k] = temp[k];
	}

}

void ResourceManager::mergeSort(int left, int right){ //recursion hurts my brain but this seperates out the main vector for the merge sort
	if(left < right) {
		int mid = left + (right - left) /2;

		mergeSort(left, mid);
		mergeSort(mid+1, right);

		merge(left, mid, right);
	}
}
