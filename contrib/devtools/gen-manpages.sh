#!/bin/bash

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

TPCD=${TPCD:-$BINDIR/tpcd}
TPCCLI=${TPCCLI:-$BINDIR/tpc-cli}
TPCTX=${TPCTX:-$BINDIR/tpc-tx}
TPCQT=${TPCQT:-$BINDIR/qt/tpc-qt}

[ ! -x $TPCD ] && echo "$TPCD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
TPCVER=($($TPCCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for tpcd if --version-string is not set,
# but has different outcomes for tpc-qt and tpc-cli.
echo "[COPYRIGHT]" > footer.h2m
$TPCD --version | sed -n '1!p' >> footer.h2m

for cmd in $TPCD $TPCCLI $TPCTX $TPCQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${TPCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${TPCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
