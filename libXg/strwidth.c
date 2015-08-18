/* Copyright (c) 1998 Lucent Technologies - All rights reserved. */
#include <u.h>
#include <libc.h>
#include <libg.h>
#include "libgint.h"

long
strwidth(Font *f, char *s)
{
	int wid, twid;
	enum { Max = 128 };
	Rune cbuf[Max];
	unsigned short fbuf[Max];
	Rune r;

	twid = 0;
	while (*s)
	{
		if (cachechars(f, &s, cbuf, Max, &wid, fbuf) <= 0)
			s += chartorune(&r, s);
		else
			twid += wid;
	}
	return twid;
}

Point
strsize(Font *f, char *s)
{
	return Pt(strwidth(f, s), f->height);
}
