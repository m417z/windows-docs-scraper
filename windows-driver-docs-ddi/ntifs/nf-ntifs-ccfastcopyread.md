# CcFastCopyRead function

## Description

The **CcFastCopyRead** routine performs a fast copy read from a cached file to a buffer in memory.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file from which the data is to be read.

### `FileOffset` [in]

Starting byte offset within the cached file.

### `Length` [in]

Length in bytes of the data to be read.

### `PageCount` [in]

Number of pages spanned by the read.

### `Buffer` [out]

Pointer to a buffer into which the data is to be copied.

### `IoStatus` [out]

Pointer to a structure that receives the final completion status and information about the operation. If not all of the data is copied successfully, **IoStatus.Information** contains the actual number of bytes that were copied.

## Remarks

**CcFastCopyRead** is a faster version of [**CcCopyRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyread). It differs from **CcCopyRead** in the following respects:

* **FileOffset** is a ULONG, not a PLARGE_INTEGER.

* There is no **Wait** parameter. The caller must be able to enter a wait state until all the data has been copied.

* **CcFastCopyRead** does not return a BOOLEAN to indicate whether the read operation was successful.

**FileOffset** plus **Length** must be less than or equal to the size of the cached file, or an assertion failure will occur.

If any failure occurs, **CcFastCopyRead** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcFastCopyRead** raises a STATUS_INSUFFICIENT_RESOURCES exception; if an I/O error occurs, **CcFastCopyRead** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcFastCopyRead** in a *try-except* or *try-finally* statement.

To cache a file, use [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[**CcCopyRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopyread)

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[**CcReadAhead**](https://learn.microsoft.com/previous-versions/ff539191(v=vs.85))

[**CcScheduleReadAhead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccschedulereadahead)

[**CcSetAdditionalCacheAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)

[**CcSetReadAheadGranularity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetreadaheadgranularity)