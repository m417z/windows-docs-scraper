# ClfsLsnEqual function

## Description

The **ClfsLsnEqual** routine determines whether two LSNs from the same stream are equal.

## Parameters

### `plsn1` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies one of the LSNs to be compared.

### `plsn2` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies the other LSN to be compared.

## Return value

**ClfsLsnEqual** returns **TRUE** if the two LSNs are equal; otherwise, it returns **FALSE**.

## Remarks

CLFS_LSN_NULL (the smallest LSN) and CLFS_LSN_INVALID (larger than any valid LSN) are valid arguments to **ClfsLsnEqual**.

LSNs from different streams are not comparable. Do not use **ClfsLsnEqual**, [ClfsLsnGreater](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsngreater), and the like to compare LSNs from different streams.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsLsnGreater](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsngreater)

[ClfsLsnLess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnless)

[ClfsLsnNull](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnnull)