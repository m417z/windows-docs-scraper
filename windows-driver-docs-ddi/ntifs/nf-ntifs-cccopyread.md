# CcCopyRead function

## Description

The **CcCopyRead** routine copies data from a cached file to a user buffer.

## Parameters

### `FileObject` [in]

A pointer to a file object for the cached file from which the data is to be read.

### `FileOffset` [in]

A pointer to a variable that specifies the starting byte offset within the cached file.

### `Length` [in]

The length in bytes of the data to be read.

### `Wait` [in]

Set to **TRUE** if the caller can be put into a wait state until all the data has been copied, **FALSE** otherwise.

### `Buffer` [out]

A pointer to a buffer into which the data is to be copied.

### `IoStatus` [out]

A pointer to a caller-allocated structure that receives the final completion status and information about the operation. If not all of the data is copied successfully, *IoStatus.Information* contains the actual number of bytes that were copied.

## Return value

The **CcCopyRead** routine returns **TRUE** if the data was copied successfully, **FALSE** otherwise.

## Remarks

If *Wait* is **TRUE**, **CcCopyRead** is guaranteed to complete the copy request and return **TRUE**. If the required pages of the cached file are already resident in memory, the data will be copied immediately and no blocking will occur. If any needed pages are not resident, the caller will be put in a wait state until all required pages have been made resident and the data can be copied.

If *Wait* is **FALSE**, **CcCopyRead** will refuse to block, and will return **FALSE**, if the required pages of the cached file are not already resident in memory.

*FileOffset* plus *Length* must be less than or equal to the size of the cached file, or an assertion failure will occur.

If any failure occurs, **CcCopyRead** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcCopyRead** raises a STATUS_INSUFFICIENT_RESOURCES exception; if an I/O error occurs, **CcCopyRead** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcCopyRead** in a **try-except** or **try-finally** statement.

To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[CcFastCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccfastcopyread)

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcReadAhead](https://learn.microsoft.com/previous-versions/ff539191(v=vs.85))

[CcScheduleReadAhead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccschedulereadahead)

[CcSetAdditionalCacheAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)

[CcSetReadAheadGranularity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetreadaheadgranularity)