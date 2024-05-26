#include <bits/stdc++.h>

using namespace std;

const int maxn = 150;
const int maxplen = 70;

class Trie
{
public:
	static const int maxnode = maxplen * maxn + 1;
	static const int sigma_size = 26;

	int sz;
	int son[maxnode][sigma_size];
	int val[maxnode];

	Trie(void)
	{
		clear();
	}

	void clear(void)
	{
		sz = 1;
		memset(son[0], 0, sizeof(son[0][0]) * sigma_size);
		val[0] = -1;
	}

	int idx(const char &ch)
	{
		return ch - 'a';
	}

	void insert(const char *s, const int &id)
	{
		int u = 0;
		for(int i = 0; s[i]; i++)
		{
			int c = idx(s[i]), &v = son[u][c];
			if(v == 0)
			{
				v = sz++;
				memset(son[v], 0, sizeof(son[v][0]) * sigma_size);
				val[v] = -1;
			}
			u = son[u][c];
		}
		val[u] = id;
	}
};

int main(void)
{
	return 0;
}

