# FltFastIoMdlReadComplete function

## Description

The **FltFastIoMdlReadComplete** routine completes the read operation that the [FltFastIoMdlRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlread) routine initiated.

## Parameters

### `InitiatingInstance`

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

A pointer to the file object.

### `MdlChain` [in]

A pointer to a linked list of memory descriptor lists (MDLs) that the [FltFastIoMdlRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlread) routine allocated.

## Return value

None

## Remarks

The **FltFastIoMdlReadComplete** routine unlocks the pages in cache memory that the [FltFastIoMdlRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlread) routine allocated.

## See also

[FltFastIoMdlRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiomdlread)