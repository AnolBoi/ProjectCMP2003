#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<int, vector<pair<int, int>>> movieRatings;
unordered_map<int, vector<pair<int, int>>> userRatings;

void populateRatings(const string& filename) {
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        string userIDStr, movieIDStr, ratingStr;

        if (!getline(ss, userIDStr, ',') ||
            !getline(ss, movieIDStr, ',') ||
            !getline(ss, ratingStr, ',')) {
            cerr << "Error: Invalid data format in line: " << line << endl;
            continue;
        }

        int userID = 0;
        int movieID = 0;
        int rating = 0;

        movieRatings[movieID].push_back({ userID, rating });
        userRatings[userID].push_back({ movieID, rating });
    }
}



int main() {
    string filePath = "C:/Users/Asus/Desktop/BAU/CMP2003/training_data.csv";
    populateRatings(filePath);


    cout << "Ratings loaded successfully." << endl;
    return 0;
}