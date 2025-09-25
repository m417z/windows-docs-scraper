# MmForceSectionClosedEx function

## Description

The MmForceSectionClosedEx function examines the section object pointers. If they are NULL, no further action is taken and the value TRUE is returned.

If the section object pointer is not NULL, the section reference count and the map view count are checked. If both counts are zero, the segment associated with the file is deleted and the file closed. If one of the counts is non-zero, no action is taken and the value FALSE is returned.

## Parameters

### `SectionObjectPointer`

Specifies a pointer to the [SECTION_OBJECT_POINTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_section_object_pointers) object.

### `ForceCloseFlags`

Contains flags that indicate if the section should be marked for closing later (as soon as possible) in the event this section cannot be closed now due to outstanding references.

Contains one of the following flags:

* MM_FORCE_CLOSED_LATER_OK if the section should be marked for immediate closing in the event that the section cannot be closed due to outstanding references.

* MM_FORCE_CLOSED_DATA to force data section closure.

* MM_FORCE_CLOSED_IMAGE to force image section closure.

## Return value

This function returns TRUE if the segment was deleted and the file closed or no segment was located. If more than one segment type is specified (data/image) then they must both be successfully deleted for TRUE to be returned.

This function returns FALSE if the segment was not deleted.

## Remarks

## See also