const int maxn = 10000;
const int maxlen = 40;

const int maxnode = maxn*maxlen*2+1;

int sz;
char chr[maxnode];
int son[maxnode];
int sbl[maxnode];

void initialize(void)
{
	sz = 1;
	son[0] = 0;
	sbl[0] = 0;
}

void add(char * s)
{
	int i;
	int u, v;

	u = 0;
	for(i=0 ; s[i] ; ++i)
	{
		if(son[u] == 0)
		{
			son[u] = sz;
			++sz;
			v = son[u];
			chr[v] = s[i];
			son[v] = 0;
			sbl[v] = 0;
		}

		for(v=son[u] ; chr[v]!=s[i]&&sbl[v]!=0 ; v=sbl[v]);
		if(chr[v] != s[i])
		{
			sbl[v] = sz;
			++sz;
			v = sbl[v];
			chr[v] = s[i];
			son[v] = 0;
			sbl[v] = 0;
		}

		u = v;
	}
}
