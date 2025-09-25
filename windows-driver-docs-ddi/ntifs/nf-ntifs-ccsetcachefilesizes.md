## Description

The **CcSetCacheFileSizes** function sets the cache manager file sizes by section object pointers.

## Parameters

### `SectionObjectPointer` [in]

Pointer to a [**SECTION_OBJECT_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers) structure that contains the section object information.

### `FileSizes` [in]

Pointer to a [**CC_FILE_SIZES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-cc_file_sizes) structure that specifies the file size to set.

## Return value

**CcSetCacheFileSizes** returns STATUS_SUCCESS if the file size was successfully changed, and, if a purge was needed that the purge was successful. Otherwise it returns a non-success NSTATUS code such as STATUS_INSUFFICIENT_RESOURCES, and might raise a status exception.

Regarding raising a status exception on error:

* If the operation causes **CcSetCacheFileSizes** to flush and/or purge the file, **CcSetCacheFileSizes** won't raise on errors; it just returns the appropriate non-success NTSTATUS code of the flush or purge operation.

* If the operation causes **CcSetCacheFileSizes** to extend the section, then **CcSetCacheFileSizes** will raise on any error it hits during this extension.

## Remarks

If the operation causes **CcSetCacheFileSizes** to extend the section and a failure occurs, **CcSetCacheFileSizes** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcSetCacheFileSizes** raises a STATUS_INSUFFICIENT_RESOURCES exception. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcSetCacheFileSizes** in a *try-except* or *try-finally* statement.

The file system must ensure that the cache map is valid and will remain so for the duration of this call.

To get the size of the cached file, pass **SectionObjectPointer** to [**CcGetCacheFileSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetcachefilesize).

## See also

[**CcGetCacheFileSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetcachefilesize)

 [**CcSetFileSizesEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetfilesizesex)