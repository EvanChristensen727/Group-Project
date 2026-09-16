#include <fstream>
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
