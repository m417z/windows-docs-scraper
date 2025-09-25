# CcSetLogHandleForFile function

## Description

The **CcSetLogHandleForFile** routine sets a log handle for a file.

## Parameters

### `FileObject` [in]

Pointer to the file object for the file for which the log handle is to be stored.

### `LogHandle` [in]

Pointer to the log handle that is to be stored.

### `FlushToLsnRoutine` [in]

Pointer to a log file flush callback routine to call before flushing buffers for this file. This routine is called to ensure that a log file is flushed to the most recent logical sequence number (LSN) for any buffer control block (BCB) being flushed. This routine is declared as follows:

```
typedef
VOID (*PFLUSH_TO_LSN) (
            IN PVOID LogHandle,
            IN LARGE_INTEGER Lsn
            );
```

#### LogHandle

Pointer to an opaque structure that is used to identify this client.

#### Lsn

This is the LSN that must be on the disk on return from this callback routine.

## Remarks

**CcSetLogHandleForFile** sets a log handle for a file, for use in subsequent calls to [CcGetDirtyPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetdirtypages).

## See also

[CcGetDirtyPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetdirtypages)

[CcSetDirtyPinnedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypinneddata)