#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *super = 0;
int pos, cnt[14];

int fact_sum(int n)
{
	int s, x, f;
	for (s = 0, x = 0, f = 1; x < n; f *= ++x, s += f);
	return s;
}

int r(int n)
{
	if (!n)
		return 0;

	char c = super[pos - n];
	if (!--cnt[n])
	{
		cnt[n] = n;
		if (!r(n - 1))
			return 0;
	}
	super[pos++] = c;
	return 1;
}

void superperm(int n)
{
	int i, len;

	pos = n;
	len = fact_sum(n);
	super = (char *)realloc(super, len + 1);
	super[len] = '\0';

	for (i = 0; i <= n; i++)
		cnt[i] = i;
	for (i = 1; i <= n; i++)
		super[i - 1] = i + '0';

	while (r(n));
}

int main(void)
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	superperm(n);
	printf("[%d] %s", (int)strlen(super), super);

	return 0;
}