//正则表达式
#include <iostream>
#include <iterator>
#include <string>
#include <regex>

int main()
{
	std::string s = "Some people, when confronted with a problem, think "
		"\"I know, I'll use regular expressions.\" "
		"Now they have two problems.";

	//查找regular expressions
	std::regex self_regex("REGULAR EXPRESSIONS",
		std::regex_constants::ECMAScript | std::regex_constants::icase);//使用ECMA-262指定的语法；忽略大小写
	if (std::regex_search(s, self_regex)) {
		std::cout << "Text contains the phrase 'regular expressions'\n";
	}

	//   \w:匹配字母、数字、下划线、汉字等字符;
	//   \W:匹配非字母、数字、下划线、汉字等字符;
	//   \\w:转义字符，匹配字母、数字、下划线、汉字等字符;
	//    +:重复一次或更多次，表示s内的字符可以取任意多个;
	//    \b:单词的开头或结尾
	std::regex word_regex("(\\w+)");
	auto words_begin =std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();
	std::cout << "Found "<< std::distance(words_begin, words_end)<< " words\n";

	const int N = 6;
	std::cout << "Words longer than " << N << " characters:\n";
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		if (match_str.size() > N) {
			std::cout << "  " << match_str << '\n';
		}
	}

	std::regex long_word_regex("(\\w{7,})");//长度不低于7的单词
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");// [$&]代替格式$&,例如[hello]代替hello
	std::cout << new_s << '\n';
}