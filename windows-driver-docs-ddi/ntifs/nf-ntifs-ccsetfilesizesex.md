## Description

The **CcSetFileSizesEx** routine updates the cache maps and section object for a cached file whose size has changed.

## Parameters

### `FileObject`

[in] Pointer to a file object for the cached file.

### `FileSizes`

[in] Pointer to a [**CC_FILE_SIZES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-cc_file_sizes) structure containing the new file size information.

## Return value

**CcSetFileSizesEx** returns STATUS_SUCCESS if the file size was successfully changed, and, if a purge was needed that the purge was successful. Otherwise it returns a non-success NSTATUS code such as STATUS_INSUFFICIENT_RESOURCES, and might raise a status exception.

Regarding raising a status exception on error:

* If the operation causes **CcSetFileSizesEx** to flush and/or purge the file, **CcSetFileSizesEx** won't raise on errors; it just returns the appropriate non-success NTSTATUS code of the flush or purge operation.

* If the operation causes **CcSetFileSizesEx** to extend the section, then **CcSetFileSizesEx** will raise on any error it hits during this extension.

## Remarks

File systems must call **CcSetFileSizesEx** to update the cache manager data structures whenever one of the following changes is made to a cached file:

* Its allocation size is increased.

* Its valid data length is decreased.

* Its valid data length is increased by a non-cached I/O operation.

* Its file size is increased or decreased.

If the operation causes **CcSetFileSizesEx** to extend the section and a failure occurs, **CcSetFileSizesEx** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcSetFileSizesEx** raises a STATUS_INSUFFICIENT_RESOURCES exception. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcSetFileSizesEx** in a *try-except* or *try-finally* statement.

The file system must ensure that the cache map is valid and will remain so for the duration of this call.

To cache a file, use [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

To get the size of the cached file, pass **FileObject** to [**CcGetFileSizePointer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetfilesizepointer).

## See also

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[**CcSetCacheFileSizes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetcachefilesizes)