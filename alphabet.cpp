#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string temp, text, line;
    vector <string> words;

    ifstream read("text.txt");

    if (!read.is_open())
    {
        cout << "Error: File not read!\n\n";
        system("pause");
        return 0;
    }

    while (getline(read, temp))
        text += temp + " ";

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    read.close();

    stringstream stream(text);
    while (getline(stream, line))
    {
        int prev = 0, pos;
        while ((pos = line.find_first_of(" `~!@#$%^&*()_+-=[]{}|;:'<,>.?/\\\"", prev)) != string::npos)
        {
            if (pos > prev)
                words.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < line.length())
            words.push_back(line.substr(prev, string::npos));
    }

    sort(words.begin(), words.end());

    ofstream result("result.txt");

    cout << "Result: \n\n";
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
        result << words[i] << endl;
    }
    cout << endl;

    result.close();

    system("pause");
    return 0;
}