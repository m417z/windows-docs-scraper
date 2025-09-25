# ClfsLsnCreate function

## Description

The **ClfsLsnCreate** routine creates a log sequence number (LSN), given a container identifier, a block offset, and a record sequence number.

## Parameters

### `cidContainer` [in]

An integer in the range 0x0 through 0xFFFFFFFF that supplies the container identifier.

### `offBlock` [in]

The block offset. This parameter must be a multiple of 512.

### `cRecord` [in]

An integer in the range 0 - 511 that supplies the record sequence number.

## Return value

**ClfsLsnCreate** returns a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that represents the container identifier, block offset, and record sequence number supplied by the caller.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

systems.

## See also

[ClfsLsnBlockOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnblockoffset)

[ClfsLsnContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsncontainer)

[ClfsLsnRecordSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnrecordsequence)