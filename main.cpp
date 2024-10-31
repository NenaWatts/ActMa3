#include <map>
#include <unordered_map>
#include "generateUsers.hpp"
using namespace std;


map<string, User> buildMapByUserName(vector<User> users) 
{
    map<string, User> usersMap;
    
    for (const auto& user : users)
    {
        usersMap[user.userName] = user;
    }
   
    //cout << "TODO" << endl;

    return usersMap;
}


map<string, User> buildMapByEmail(vector<User> users) {
    
    map<string, User> usersMap;

    for (const auto& user : users)
    {
        usersMap[user.email] = user;
    }
    /*cout << "TODO" << endl;*/

    return usersMap;
}


void printMap(map<string, User>& aMap) {
    /*cout << "TODO" << endl;*/
    int index = 0;
    for (const auto& entry : aMap)
    {
       
       const string& userName = entry.first;
       const User& user = entry.second;
       cout << "#:" << index++ << " Key:" << userName << " Value:" << userName<< "," << user.firstName << "," << user.lastName << "," << user.email << "," << user.numPosts << "," << user.mostViewedCategory << " " << endl;
    }
}


bool isMapSorted(map<string, User> aMap) {
    if (aMap.empty())
        return true;

    auto curr = aMap.begin();
    auto checkMap = next(curr);
    while (checkMap != aMap.end())
    {
        if (curr->first >= checkMap->first)
        {
            return false;
        }
        curr = checkMap;
        checkMap = next(checkMap);
    }
    return true;
}


bool testSearchByKey(map<string, User> aMap, string keyToSearch) {
    auto use = aMap.find(keyToSearch);
    if (use != aMap.end())
    {
        cout << "Key found is:" << keyToSearch << endl;
        return true;
    }
    else
    {
        cout << "Key not found" << keyToSearch << endl;
    }
    //cout << "TODO" << endl;
    return false;
}


bool testDeleteByKey(map<string, User> aMap, string keyToDelete) {
    
    if (aMap.empty())
    {
        return false;
    }
    int ErasedKey = aMap.erase(keyToDelete);
    
    if (ErasedKey > 0)
    {
        cout << "This key was deleted:" << keyToDelete << endl;
    }
  
    return true;
}


void printActiveUsers(map<string, User> aMap) {
    //int activeThreshold = 800;
    for (const auto& entry : aMap)
    {
        const User& user = entry.second;
        if (user.numPosts >= 800)
        {
            cout << "Username:" << user.userName << endl;
        }
    }
}


void printMostPopularCategory(map<string, User> aMap) {
    int index = 0;
    string mostUsed;
    unordered_map<string, int> newMap;
    for (const auto& entry : aMap)
    {
        const string& prefC = entry.second.mostViewedCategory;
        newMap[prefC]++;
    }
    
    for (const auto& newEntry : newMap)
    {
        if (newEntry.second > index)
        {
            index = newEntry.second;
            mostUsed = newEntry.first;

        }
    }
    if (index > 0)
    {
        cout << "" << mostUsed << endl;
    }
    else
    {
        cout << "No max category found:" << endl;
    }
}


int main()
{
 
    int numUsers = 10;
    vector<User> users = generateUsers(numUsers);
    map<User, string> userMap;
    

    cout << "Build map with username as key" << endl;
    map<string, User> mapByUserName = buildMapByUserName(users);
    if (mapByUserName.size() == numUsers)
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;


    cout << "Print \"mapByUserName\" map:" << endl;
    printMap(mapByUserName);
    cout << endl;


    string keyToSearch = "smith55";
    cout << "Search by key: mapByUserName[\"" << keyToSearch << "\"]" << endl;
    if (testSearchByKey(mapByUserName, keyToSearch))
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    string keyToDelete = "smith55";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if (testDeleteByKey(mapByUserName, keyToDelete))
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    cout << "Test if map's key is sorted" << endl;
    if (isMapSorted(mapByUserName))
        cout << "  Order test passed!" << endl << endl;
    else
        cout << "  Order test failed!" << endl << endl;


    cout << "Print usernames with more than 800 tweets:" << endl;
    printActiveUsers(mapByUserName);
    cout << endl;

    cout << "Print the most popular category" << endl;
    printMostPopularCategory(mapByUserName);
    cout << endl;


    cout << " ============================================================================== " << endl << endl;


    cout << "Build map with username as key" << endl;
    map<string, User> mapByEmail = buildMapByEmail(users);
    if (mapByEmail.size() == numUsers)
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;


    keyToSearch = "kat@gmail.com";
    cout << "Search by key: mapByEmail[\"" << keyToSearch << "\"]" << endl;
    if (testSearchByKey(mapByEmail, keyToSearch))
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    keyToDelete = "kat@gmail.com";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if (testDeleteByKey(mapByEmail, keyToDelete))
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    return 0;
}