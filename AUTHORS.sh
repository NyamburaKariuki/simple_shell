#!/bin/env bash
set -e
cd "$(dirname "$(readlink -f "BASH_SOURCE")")/.."
{
	cat <<-'EOH'
	EOH
	echo
	git log --format='%aN <%aE>' | LC-ALL=C.UTF-8 sort -uf
} > AUTHORS
