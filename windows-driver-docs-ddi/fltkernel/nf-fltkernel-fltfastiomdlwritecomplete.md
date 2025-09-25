# FltFastIoMdlWriteComplete function

## Description

The **FltFastIoMdlWriteComplete** routine frees the resources that [FltFastIoPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiopreparemdlwrite) allocated.

## Parameters

### `InitiatingInstance`

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

A pointer to the file object.

### `FileOffset` [in]

A pointer to a value that specifies the starting byte offset within the cache that holds the data.

### `MdlChain` [in]

A pointer to a linked list of memory descriptor lists (MDLs) that [FltFastIoPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiopreparemdlwrite) allocated.

## Return value

The **FltFastIoMdlWriteComplete** routine returns **TRUE** if the operation succeeds and **FALSE** if the operation fails or if the FO_WRITE_THROUGH flag is set in the file object.

## Remarks

The **FltFastIoMdlWriteComplete** routine frees the memory descriptor lists (MDLs) that [FltFastIoPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiopreparemdlwrite) allocated and unlocks the cache memory that **FltFastIoPrepareMdlWrite** locked.

If the FO_WRITE_THROUGH flag is set on the file object pointed to by the *FileObject* parameter, **FltFastIoMdlWriteComplete** immediately flushes the cached memory to disk. This flush operation re-enters the file system and can cause **FltFastIoMdlWriteComplete** to raise an exception if the flush operation fails.

Each call to [FltFastIoPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiopreparemdlwrite) must be followed by a call to **FltFastIoMdlWriteComplete**.

## See also

[FltFastIoPrepareMdlWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfastiopreparemdlwrite)