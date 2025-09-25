# CcSetFileSizes function

## Description

The **CcSetFileSizes** routine updates the cache maps and section object for a cached file whose size has changed. Use [**CcSetFileSizesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetfilesizesex) instead since it provides an NTSTATUS return code along with better guidance for error handling.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file.

### `FileSizes` [in]

Pointer to a [**CC_FILE_SIZES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-cc_file_sizes) structure containing the new file size information.

## Remarks

File systems must call [**CcSetFileSizesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetfilesizesex) or **CcSetFileSizes** to update the cache manager data structures whenever one of the following changes is made to a cached file:

* Its allocation size is increased.

* Its valid data length is decreased.

* Its valid data length is increased by a non-cached I/O operation.

* Its file size is increased or decreased.

If any failure occurs, **CcSetFileSizes** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcSetFileSizes** raises a STATUS_INSUFFICIENT_RESOURCES exception. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcSetFileSizes** in a *try-except* or *try-finally* statement.

The file system must ensure that the cache map is valid and will remain so for the duration of this call.

To cache a file, use [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

To get the size of the cached file, pass **FileObject** to [**CcGetFileSizePointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetfilesizepointer).

## See also

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

 [**CcSetFileSizesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetfilesizesex)