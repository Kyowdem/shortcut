#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>

using namespace std;

class Error
{
public:
    /**
 * Print an error message and leave exit
 * @param error {string} The error message
 */
    Error(string error)
    {
        std::cout << error << std::endl;
        exit(1);
    }
};

class Command
{
private:
    string command;
    map<string, string> commands{
        {"gaa", "git add -A"},
        {"gcm", "git commit -am {message}"},
        {"gcma", "git commit --amend"},
        {"gch", "git checkout {branch}"},
        {"gchb", "git checkout -b {branch}"},
        {"glo", "git log --oneline"},
        {"glop", "git log --pretty=format:\"%h  %cr  %cn : %s\""},
        {"gps", "git push -u origin {branch}"},
        {"gba", "git branch -a"},
        {"gpd", "git push origin --delete"},
        {"gcro", "git config --get remote.origin.url"}};

public:
    Command(string key)
    {
        this->command = this->getCommands(key);
    }
    /**
     * Simple getters
     * @return {string} return command or an error
     */
    string getCommands(string key)
    {
        string cmd = commands[key];
        if (cmd != "")
            return cmd;
        else
            Error("La commande est introuvable.\nLire le README: https://github.com/Kyowdem/shortcut/");
        return "";
    }
    /**
     * check if command got arg
     * @return {boolean} 
    */
    bool containArg()
    {
        if(this->command.find("{"))
            return true;
        return false;
    }
    void run(string cmd) { run(cmd, ""); }
    void run(string cmd, string arg);
};

class String
{
private:
    static const string WHITESPACE;

    static string ltrim(string s)
    {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == string::npos) ? "" : s.substr(start);
    }
    static string rtrim(string s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == string::npos) ? "" : s.substr(0, end + 1);
    }

public:
    static string trim(string s) { return rtrim(ltrim(s)); }
};
const string String::WHITESPACE = " \r\t\f\v";
