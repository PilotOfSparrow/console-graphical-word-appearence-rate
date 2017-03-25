#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <unordered_map>


int main()
{
	const int MAX_APPEARANCE = 10;
	const int INITIAL_APPEARANCE_NUMBER = 1;

	unsigned max_str_length = 0;
	unsigned max_appearance = 0;
	std::string inp_str;

	std::deque<std::pair<int, std::string>> words_deque;
	std::unordered_map<std::string, unsigned> words_map;

	getline(std::cin, inp_str);
	
	std::stringstream ss;

	ss << inp_str;

	std::string word;

	while (ss >> word)
	{
		unsigned curr_w_size = word.size();
		if (curr_w_size > max_str_length) max_str_length = curr_w_size;

		if (words_map.find(word) != words_map.end()) 
		{
			++words_map[word];
			if (words_map[word] > max_appearance) max_appearance = words_map[word];
		}
		else
			words_map.insert(make_pair(word, INITIAL_APPEARANCE_NUMBER));
	}

	for (auto iter : words_map)
	{
		std::string tmp_w = iter.first;
		unsigned num_of_underscores = max_str_length - tmp_w.size();

		if (num_of_underscores != 0) tmp_w.insert(0, num_of_underscores, '_');

		double num_of_dots = 0;

		if (iter.second < max_appearance)
		{
			double tmp_denominator = static_cast<double>(max_appearance) / iter.second;
			num_of_dots = round(MAX_APPEARANCE / tmp_denominator);
		}
		else
			num_of_dots = MAX_APPEARANCE;

		words_deque.push_back(make_pair(num_of_dots, tmp_w));
	}

	sort(words_deque.begin(), words_deque.end());
	for (auto iter : words_deque)
	{
		std::cout << iter.second << " " << std::string(iter.first, '.') << std::endl;
	}

}