# _CLFS_CONTEXT_MODE enumeration

## Description

The **CLFS_CONTEXT_MODE** enumeration indicates the type of sequence that the Common Log File System (CLFS) driver follows when it reads a set of records from a stream.

## Constants

### `ClfsContextNone`

Indicates that a variable of type **CLFS_CONTEXT_MODE** has not yet been assigned a meaningful value.

### `ClfsContextUndoNext`

Indicates that the next record in the sequence is pointed to by the [undo-next LSN](https://learn.microsoft.com/windows-hardware/drivers/kernel/clfs-log-sequence-numbers) of the current record.

### `ClfsContextPrevious`

Indicates that the next record in the sequence is pointed to by the [previous LSN](https://learn.microsoft.com/windows-hardware/drivers/kernel/clfs-log-sequence-numbers) of the current record.

### `ClfsContextForward`

Indicates that the next record in the sequence is the record in the stream that immediately follows the current record.

## See also

[ClfsReadLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadlogrecord)

[ClfsReadNextLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadnextlogrecord)

[ClfsReadPreviousRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadpreviousrestartarea)

[ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea)