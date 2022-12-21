#pragma once
#include <iostream>
#include<fstream>



struct FileManager

{
	FileManager() {}

	void create_file() {

		std::ofstream result;
		result.open(("Result.txt"));

	}

	template<typename Type>
	void writing(std::pair<size_t, Type*> message) {

		std::ofstream result;

		result.open("Result.txt", std::ofstream::app);

		if (!result.is_open()) {
			throw std::runtime_error("failed to open file");
		}

		Type* data = message.second;

		for (size_t i = 0; i < message.first; i++) // запись в конец еще не реализована
		{
			result << *data << " ";
			data++;
		}
	}

private:

};