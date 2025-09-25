# MmFlushImageSection function

## Description

The **MmFlushImageSection** routine flushes the image section for a file.

## Parameters

### `SectionObjectPointer`

Pointer to a structure that contains the file object's section object pointers.

### `FlushType` [in]

Specifies the reason for the flush operation. It can be one of the values listed in the following table.

| FlushType Value | Meaning |
| --- | --- |
| **MmFlushForDelete** | The file is being deleted. |
| **MmFlushForWrite** | The file is being opened for write access. |

## Return value

**MmFlushImageSection** returns **TRUE** if the flush operation is successful, or if no image section exists for the file; otherwise **MmFlushImageSection** returns **FALSE**.

**Note** If the FlushType MmFlushForDelete value is specified and there are one or more outstanding write probes on the file's data section, **MmFlushImageSection** returns **FALSE**.

## Remarks

A file system must call the **MmFlushImageSection** routine before deleting a file or opening a file for write access.

Before deleting a file, the file system should call **MmFlushImageSection** from its IRP_MJ_SET_INFORMATION or IRP_MJ_CLEANUP dispatch routine, passing **MmFlushForDelete** for the *FlushType* parameter.

When opening a file for write access, the file system should call **MmFlushImageSection** from its IRP_MJ_CREATE dispatch routine, passing **MmFlushForWrite** for the *FlushType* parameter.

If there are no mapped views of the image section, **MmFlushImageSection** destroys the image section and returns any used pages to the free list.

Before using **MmFlushImageSection**, file system writers are strongly encouraged to study the way this routine is used in the FASTFAT sample.

## See also

[CcPurgeCacheSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpurgecachesection)