# CcFastCopyWrite function

## Description

The **CcFastCopyWrite** routine performs a fast copy write from a buffer in memory to a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file to which the data is to be written.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the cached file.

### `Length` [in]

Length in bytes of the data to be written.

### `Buffer` [in]

Pointer to the buffer from which the data is to be copied.

## Remarks

**CcFastCopyWrite** is a faster version of [**CcCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite). It differs from **CcCopyWrite** in the following respects:

* **FileOffset** is a ULONG, not a PLARGE_INTEGER.

* There is no **Wait** parameter. The caller must be able to enter a wait state until all the data has been copied.

* **CcFastCopyWrite** does not return a BOOLEAN to indicate whether the write operation was successful.

If the required pages of the cached file are already resident in memory, the data is copied immediately and no blocking occurs. If any needed pages are not resident, the caller is put in a wait state until all required pages have been made resident and the data can be copied.

If any failure occurs, **CcFastCopyWrite** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcFastCopyWrite** raises a STATUS_INSUFFICIENT_RESOURCES exception; if an I/O error occurs, **CcFastCopyWrite** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcFastCopyWrite** in a *try-except* or *try-finally* statement.

To cache a file, use [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[**CcCopyWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite)

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)