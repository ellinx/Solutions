#include "../Solutions.hpp"

using namespace std;

/***************** Minimum Size Subarray Sum  *****************/
/*
 Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
*/

int Solutions::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> wordSet;
	queue<pair<string,int>> toVisit;
	for (int i=0;i<wordList.size();i++) {
		if (wordList[i]==endWord) {
			toVisit.emplace(endWord,1);
		} else {
			wordSet.insert(wordList[i]);
		}
	}

	if (toVisit.empty()) return 0;

	while (!toVisit.empty()) {
		string node =toVisit.front().first;
		int len = toVisit.front().second;
		toVisit.pop();
		for (int i=0;i<node.size();i++) {
			for (char a='a';a<='z';a++) {
				if (a!=node[i]) {
					string tmp = node;
					tmp[i] = a;
					if (tmp==beginWord) return len+1;
					if (wordSet.find(tmp)!=wordSet.end()) {
						toVisit.emplace(tmp,len+1);
						wordSet.erase(tmp);
					}
				}
			}
		}
	}
	return 0;
}