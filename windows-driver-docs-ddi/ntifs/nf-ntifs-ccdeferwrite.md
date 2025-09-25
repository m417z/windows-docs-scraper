# CcDeferWrite function

## Description

The **CcDeferWrite** routine defers writing to a cached file. The post routine that is supplied, is called by the cache manager when it can accommodate the write operation.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file to which the data is to be written.

### `PostRoutine` [in]

Address of a routine for the cache manager to call to write to the cached file. Note that it is possible that this routine will be called immediately, even if [CcCanIWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccaniwrite) has just returned **FALSE** .

The post routine is defined in ntifs.h as:

```
typedef
VOID (*PCC_POST_DEFERRED_WRITE) (
    _In_ PVOID Context1,
    _In_ PVOID Context2
    );
```
This function can be called with the TopLevelIrp field in the current IRP set to FSRTL_MOD_WRITE_TOP_LEVEL_IRP.

### `Context1` [in]

First parameter for the post routine at *PostRoutine*.

### `Context2` [in]

Second parameter for the post routine at *PostRoutine*.

### `BytesToWrite` [in]

Number of bytes of data to be written.

### `Retrying` [in]

Set to **FALSE** if the request is being posted for the first time, **TRUE** otherwise.

## Remarks

A file system would normally call **CcDeferWrite** after receiving a return value of **FALSE** from [CcCanIWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccaniwrite).

To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

The context parameters passed to *PostRoutine* are typically the I/O request and related context data.

## See also

[CcCanIWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccaniwrite)

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcSetDirtyPageThreshold](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetdirtypagethreshold)