typedef int (*interfaz_somefunc)(int,int);

int product(int u, int v) {
  return u*v;
}

interfaz_somefunc afunc = &product;

int x2 = (*afunc)(123, 456); // call product() to calculate 123*456