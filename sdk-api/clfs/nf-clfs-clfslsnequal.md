# ClfsLsnEqual function

## Description

Determines whether two LSNs from the same stream are equal.

## Parameters

### `plsn1` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to be compared with *plsn2*.

### `plsn2` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to be compared with *plsn1*.

## Return value

Returns **TRUE** if the two LSNs are equal; otherwise, **FALSE**.

## Remarks

CLFS_LSN_NULL (the smallest LSN) and CLFS_LSN_INVALID (larger than any valid LSN) are valid arguments to this function.

LSNs from different streams are not comparable. Do not use this function to compare LSNs from different streams.

## See also

[LsnGreater](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsngreater)

[LsnLess](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsnless)

[LsnNull](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsnnull)