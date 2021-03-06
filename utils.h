/*
	Copyright(C) 2016, Red Hat, Inc., Stanislav Kozina

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef UTILS_H_
#define	UTILS_H_

#define	fail(m...)	{			\
	fprintf(stderr, "%s():%d ", __func__, __LINE__);	\
	fprintf(stderr, m);				\
	exit(1);				\
}

static inline void *safe_malloc(size_t size) {
	void *result = malloc(size);
	if (result == NULL)
		fail("Malloc of size %zu failed", size);
	memset(result, 0, size);
	return (result);
}

extern void walk_dir(char *, bool, bool (*)(char *, void *), void *);
extern int check_is_directory(char *);
extern void rec_mkdir(char *);

#endif /* UTILS_H */
