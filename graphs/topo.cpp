#include "../template.cpp"

#define MX 207
bitset<MX> TM;
vll path; // reverse path
void tdfs(vector<vll>& G, ll n)
{
  TM[n] = 1;
  F(G[n].size())
    if (!TM[G[n][i]])
      tdfs(G, G[n][i]);
  path.pb(n);
}
void topo(vector<vll>& G)
{
  F(MX) if (!TM[i]) tdfs(G, i);
}
