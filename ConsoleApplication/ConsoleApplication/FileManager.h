#pragma once
#include <iostream>
#include<fstream>
#include<chrono>



struct FileManager

{
	FileManager() {}

	// Метод создания файла
	void create_file() {

		std::ofstream result;
		result.open(("Result.txt"));

	}

	// Метод записи в файл
	template<typename Type>
	void writing(std::pair<size_t, Type*> message) {

		std::ofstream result;

		result.open("Result.txt", std::ofstream::app);

		if (!result.is_open()) {
			throw std::runtime_error("failed to open file");
		}

		Type* data = message.second;

		auto start = std::chrono::steady_clock::now(); // Измерение времени выполнения

		for (size_t i = 0; i < message.first; i++) 
		{
			result << *data << " "; 
			data++;
		}

		auto end = std::chrono::steady_clock::now();

		auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

		float time = delta.count();

		float speed = 1000 / time; // Определение скорости записи

		result.close();

		std::cout << "скорость записи в файл " << speed << " МБ/C" << std::endl;

		
	}

};
