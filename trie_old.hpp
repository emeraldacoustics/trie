const int maxn = 150;
const int maxpl = 70;
const int maxtl = 1000000;

const int maxnode = maxn*maxpl+1;
const int sigma_size = 26;

int cnt[maxn+1];
int sz;
int son[maxnode][sigma_size];
int val[maxnode];

void initialize(void)
{
	sz = 1;
	memset(son[0], 0, sizeof(son[0][0])*sigma_size);
}

int idx(char ch)
{
	return ch-'a';
}

void add(char * s, int id)
{
	int i;
	int c;
	int u, v;

	u = 0;
	for(i=0 ; s[i] ; ++i)
	{
		c = idx(s[i]);
		v = son[u][c];

		if(v == 0)
		{
			son[u][c] = sz;
			++sz;
			v = son[u][c];
			memset(son[v], 0, sizeof(son[v][0])*sigma_size);
			val[v] = 0;
		}

		u = v;
	}

	val[u] = id;
}
