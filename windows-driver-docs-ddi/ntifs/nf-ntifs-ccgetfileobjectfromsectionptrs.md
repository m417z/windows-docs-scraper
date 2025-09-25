# CcGetFileObjectFromSectionPtrs function

## Description

Given a pointer to the section object pointers for a cached file, the **CcGetFileObjectFromSectionPtrs** routine returns a pointer to the file object that the cache manager is using for the file.

## Parameters

### `SectionObjectPointer` [in]

Pointer to a structure containing the file object's section object pointers.

## Return value

A pointer to the file object, or **NULL** if the file is not cached or is no longer cached.

## Remarks

The file system is responsible for ensuring that the file object remains valid while in use. It is impossible for the cache manager to guarantee this.

By using **CcGetFileObjectFromSectionPtrs**, you lose some caching functionality. Instead, use the [CcGetFileObjectFromSectionPtrsRef](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetfileobjectfromsectionptrsref) routine, which provides the same functionality as **CcGetFileObjectFromSectionPtrs** as well as creating a reference for the object.

For more information about creating mapped sections and views of memory, see [Sections and Views](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#sections-and-views).

## See also

[CcGetFileObjectFromSectionPtrsRef](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetfileobjectfromsectionptrsref)

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)