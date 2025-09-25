# ClfsLsnGreater function

## Description

Determines whether one LSN is greater than another LSN. The two LSNs must be from the same stream.

## Parameters

### `plsn1` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to be compared with *plsn2*.

### `plsn2` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to be compared with *plsn1*.

## Return value

**TRUE** if *plsn1* is strictly greater than *plsn2*; otherwise, **FALSE**.

## Remarks

CLFS_LSN_NULL (the smallest LSN) and CLFS_LSN_INVALID (larger than any valid LSN) are valid arguments to this function.

LSNs from different streams are not comparable. Do not use this function to compare LSNs from different streams.

## See also

[LsnEqual](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsnequal)

[LsnLess](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsnless)

[LsnNull](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsnnull)