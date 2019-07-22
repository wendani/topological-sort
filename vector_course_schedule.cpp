bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> adjList(numCourses);
	vector<int> preCourseNum(numCourses, 0);

	queue<int> zeroPreCourses;

	for (const auto &prerequisite : prerequisites) {
		adjList[prerequisite[1]].push_back(prerequisite[0]);
		++preCourseNum[prerequisite[0]];
	}

	for (int i = 0; i < numCourses; i++) {
		if (!preCourseNum[i]) {
			zeroPreCourses.push(i);
		}
	}

	int coursesTaken = 0;
	while (!zeroPreCourses.empty()) {
		int &i = zeroPreCourses.front();

		for (const auto &j : adjList[i]) {
			preCourseNum[j]--;
			if (!preCourseNum[j]) {
				zeroPreCourses.push(j);
			}
		}

		++coursesTaken;
		zeroPreCourses.pop();
	}

	return coursesTaken == numCourses;
}



bool  _dfs(const vector<vector<int>> &adjList, vector<bool> &searched, int courseNum)
{
	if (searched[courseNum]) {
		return false;
	}

	searched[courseNum] = true;

	for (const auto &i : adjList[courseNum]) {
		if (!_dfs(adjList, searched, i)) {
			return false;
		}
	}

	searched[courseNum] = false;
	return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> adjList(numCourses);
	vector<bool> searched(numCourses, false);

	for (const auto &prerequisite : prerequisites) {
		adjList[prerequisite[1]].push_back(prerequisite[0]);
	}

	for (int i = 0; i < numCourses; i++) {
		if (!_dfs(adjList, searched, i)) {
			return false;
		}
	}

	return true;
}
