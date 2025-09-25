## Description

The **CcGetCacheFileSize** function retrieves the current size of a file as known to the cache manager.

## Parameters

### `SectionObjectPointer` [in]

Pointer to a [**SECTION_OBJECT_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers) structure that contains the section object information.

## Return value

**CcGetCacheFileSize** returns a 64-bit value that indicates the current file size.

## See also

[**CcSetCacheFileSizes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetcachefilesizes)