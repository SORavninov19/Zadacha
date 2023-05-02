#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printVector(vector<string> v)
{
    cout << "[";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }

    cout << "]" << endl;
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
    {
        return {};
    }

    unordered_map<char, string> letters =
    {
        {'1', " "}, {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> combinations;

    backtrack("", 0, digits, letters, combinations);

    return combinations;
}

void backtrack(string thing, int index, string digits, unordered_map<char, string> letters, vector<string>& combinations)
{
    if (thing.length() == digits.length()) {
        combinations.push_back(thing);
        return;
    }

    auto& chars = letters[digits[index]];

    for (auto c : chars)
    {
        thing.push_back(c);
        backtrack(thing, index + 1, digits, letters, combinations);

        thing.pop_back();
    }
}



int main() {
    vector<string> nums = { "22", "132", "792" };

    for (auto& num : nums)
    {
        printVector(letterCombinations(num));
        cout << string(100, '-') << endl;
    }
}
