# ClfsLsnLess function

## Description

The **ClfsLsnLess** routine determines whether one LSN is less than another LSN. The two LSNs must be from the same stream.

## Parameters

### `plsn1` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies one of the LSNs to be compared.

### `plsn2` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies the other LSN to be compared.

## Return value

**ClfsLsnLess** returns **TRUE** if *plsn1* is strictly less than *plsn2*; otherwise, it returns **FALSE**.

## Remarks

CLFS_LSN_NULL (the smallest LSN) and CLFS_LSN_INVALID (larger than any valid LSN) are valid arguments to **ClfsLsnLess**.

LSNs from different streams are not comparable. Do not use [ClfsLsnEqual](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnequal), **ClfsLsnLess** and the like to compare LSNs from different streams.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsLsnEqual](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnequal)

[ClfsLsnGreater](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsngreater)

[ClfsLsnNull](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnnull)