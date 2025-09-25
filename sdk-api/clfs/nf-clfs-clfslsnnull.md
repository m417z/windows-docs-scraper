# ClfsLsnNull function

## Description

Determines whether a specified LSN is equal to the smallest possible LSN, which is CLFS_LSN_NULL.

## Parameters

### `plsn` [in]

A pointer to the [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to be tested.

## Return value

**TRUE** if *plsn* is equal to CLFS_LSN_NULL; otherwise, **FALSE**.

## See also

[LsnEqual](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsnequal)

[LsnGreater](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsngreater)

[LsnLess](https://learn.microsoft.com/windows/desktop/api/clfs/nf-clfs-clfslsnless)