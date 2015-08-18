/* Copyright (c) 1998 Lucent Technologies - All rights reserved. */
#include <u.h>
#include <libc.h>
#include <regexp.h>


main(int ac, char **av)
{
	Resub rs[10];
	Reprog *p;
	char *s;
	int i;

	p = regcomp("[^a-z]");
	s = "\n";
	rs[0].s.sp = 0;
	rs[0].e.ep = 0;
	if(regexec(p, s, rs, 10))
		printf("%s %x %x %x\n", s, s, rs[0].s.sp, rs[0].e.ep);
	s = "0";
	if(regexec(p, s, rs, 10))
		printf("%s %x %x %x\n", s, s, rs[0].s.sp, rs[0].e.ep);
	_exits(0);
}
