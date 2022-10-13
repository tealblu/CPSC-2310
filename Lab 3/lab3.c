/***********************
 *C. Hartsell
 *ckharts
 *Lab 3 Sec 002
 **********************/

#include <stdio.h>
struct NODE{
	int a;
	struct NODE *b;
	struct NODE *c;
};


int main(void) {

struct NODE nodes[5] = {
	{20,	nodes + 3, 	NULL},
	{59,	nodes + 2, 	nodes + 4},
	{8,	NULL,		nodes + 1},
	{44, 	nodes + 4, 	nodes},
	{32, 	nodes + 1, 	nodes + 3}
};

struct NODE  *np  = nodes + 2;
struct NODE  **npp = &nodes[1].b;

printf("nodes = %i\n", nodes);
printf("nodes.a = %i\n", nodes.a);
printf("nodes[3].a = %i\n", nodes[3].a);
printf("nodes[3].c = %X\n", nodes[3].c);
printf("nodes[3].c->a = %X\n", nodes[3].c->a);
printf("*nodes.a = %i\n", nodes.a);
printf("(*nodes).a = %i\n", (*nodes).a);
printf("nodes->a = %i\n", nodes->a);
printf("nodes[3].b->b = %i\n", nodes[3].b->b);
printf("&nodes = %X\n", &nodes);
printf("&nodes[3].a = %X\n", &nodes[3].a);
printf("&nodes[3].c = %X\n",&nodes[3].c);
printf("&nodes[3].c->a = %i\n", &nodes[3].c->a);
printf("&nodes->a = %i\n", &nodes->a);
printf("np = %X\n", np);
printf("np->a = %i\n", np->a);
printf("npp = %X", npp);
printf("*npp = %X\n", *npp);
printf("*npp->a = %i\n", *npp->a);
printf("(*npp)->a = %i\n", (*npp)->a);
printf("&np = %X\n", &np);
puts("All done, have a nice day!");
}