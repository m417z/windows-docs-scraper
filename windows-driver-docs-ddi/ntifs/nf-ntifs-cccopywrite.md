# CcCopyWrite function

## Description

The **CcCopyWrite** routine copies data from a user buffer to a cached file.

## Parameters

### `FileObject` [in]

A pointer to a file object for the cached file to which the data is to be written.

### `FileOffset` [in]

A pointer to a variable that specifies the starting byte offset within the cached file.

### `Length` [in]

The length in bytes of the data to be written.

### `Wait` [in]

Set to **TRUE** if the caller can be put into a wait state until all the data has been copied, **FALSE** otherwise.

### `Buffer` [in]

A pointer to the buffer from which the data is to be copied.

## Return value

The **CcCopyWrite** routine returns **TRUE** if the data was copied successfully, **FALSE** otherwise.

## Remarks

If *Wait* is **TRUE**, **CcCopyWrite** is guaranteed to complete the copy request and return **TRUE**. If the required pages of the cached file are already resident in memory, the data will be copied immediately and no blocking will occur. If any needed pages are not resident, the caller will be put in a wait state until all required pages have been made resident and the data can be copied.

If *Wait* is **FALSE**, **CcCopyWrite** will refuse to block, and will return **FALSE**, if the required pages of the cached file are not already resident in memory or if the FO_WRITE_THROUGH flag is set on the file object.

If any failure occurs, **CcCopyWrite** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcCopyWrite** raises a STATUS_INSUFFICIENT_RESOURCES exception; if an I/O error occurs, **CcCopyWrite** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcCopyWrite** in a **try-except** or **try-finally** statement.

To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)