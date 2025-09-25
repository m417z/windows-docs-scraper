# ClfsLsnNull function

## Description

The **ClfsLsnNull** routine determines whether a specified LSN is equal to the smallest possible LSN, CLFS_LSN_NULL.

## Parameters

### `plsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies the LSN to be tested.

## Return value

**ClfsLsnNull** returns **TRUE** if the LSN supplied by the caller is equal to CLFS_LSN_NULL; otherwise, it returns **FALSE**.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsLsnEqual](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnequal)

[ClfsLsnGreater](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsngreater)

[ClfsLsnLess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnless)