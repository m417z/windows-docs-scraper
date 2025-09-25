# MmForceSectionClosed function

## Description

The **MmForceSectionClosed** routine deletes the data and image sections for a file that is no longer in use.

## Parameters

### `SectionObjectPointer` [in]

A pointer to a structure that contains the file object's section object pointers.

### `DelayClose` [in]

A Boolean value that specifies whether the section is subsequently deleted if **MmForceSectionClosed** cannot delete the section synchronously (that is, prior to **MmForceSectionClosed** returning).

**TRUE** indicates that if **MmForceSectionClosed** cannot delete the section synchronously, **MmForceSectionClosed** sets a flag. With this flag set, when the section's outstanding reference count reaches zero, the memory manager deletes the section automatically.

**FALSE** indicates that if **MmForceSectionClosed** cannot delete the section synchronously, the section is not deleted.

## Return value

**MmForceSectionClosed** returns **TRUE** if the sections were successfully deleted or no sections were found, **FALSE** otherwise.

**Note** If there are one or more outstanding write probes on the file's data section, [MmFlushImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmflushimagesection) returns **FALSE**.

## Remarks

For more information about creating mapped sections and views of memory, see [Sections and Views](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#sections-and-views).

## See also

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)

[MmFlushImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mmflushimagesection)