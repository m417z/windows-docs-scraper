# CcGetFileObjectFromSectionPtrsRef function

## Description

When passed a pointer to a SECTION_OBJECT_POINTERS structure for a cached file, the **CcGetFileObjectFromSectionPtrsRef** routine returns a pointer to the file object that the cache manager is using for the cached file.

## Parameters

### `SectionObjectPointer` [in]

A pointer to the [SECTION_OBJECT_POINTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers) structure that is associated with the cached file.

## Return value

A pointer to the file object for the cached file, or **NULL** if the file is not cached or is no longer cached.

## Remarks

The file object is returned with a reference. The caller is responsible for calling [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) on the file object when it has finished using the file object.

## See also

[CcGetFileObjectFromSectionPtrs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccgetfileobjectfromsectionptrs)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[SECTION_OBJECT_POINTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers)