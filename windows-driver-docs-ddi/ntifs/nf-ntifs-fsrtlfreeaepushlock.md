## Description

**FsRtlFreeAePushLock** deallocates an auto-expand push lock.

## Parameters

### `AePushLock` [in]

Pointer to an auto-expand push lock that was allocated by [**FsRtlAllocateAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateaepushlock).

## Remarks

See [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) for more information about auto-expand push locks.

## See also

[**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[**FsRtlAllocateAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateaepushlock)