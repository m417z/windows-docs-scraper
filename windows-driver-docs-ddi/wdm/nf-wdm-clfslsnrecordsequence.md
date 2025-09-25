# ClfsLsnRecordSequence function

## Description

The **ClfsLsnRecordSequence** routine returns the record sequence number contained in a specified LSN.

## Parameters

### `plsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure from which the record sequence number is retrieved.

## Return value

**ClfsLsnRecordSequence** returns the record sequence number contained in the LSN that is supplied by the caller.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsLsnBlockOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnblockoffset)

[ClfsLsnContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsncontainer)