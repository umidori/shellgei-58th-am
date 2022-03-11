#!/usr/bin/env perl

$next = <>;
while ($next) {
	$n = 0;
	$curr = $next;
	while ($next && $curr eq $next) {
		$n++;
		$next = <>;
	}
	printf("%d %s", $n, $curr);
}
