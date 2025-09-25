# DXGKARGCB_SAVEMEMORYFORHOTUPDATE structure

## Description

The **DXGKARGCB_SAVEMEMORYFORHOTUPDATE** structure contains the information used by the [**DXGKCB_SAVEMEMORYFORHOTUPDATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_savememoryforhotupdate) callback function, to save memory for a driver hot update.

## Members

### `NumDataMemoryRanges` [in]

The number of physical memory ranges in the **pDataMemoryRanges** array.

### `pDataMemoryRanges` [in, optional]

Pointer to the array of physical memory ranges.

### `pDataMdl` [in, optional]

Pointer to a memory descriptor list (MDL) that describes the physical memory pages.

When passing **pDataMdl**, the driver should do the following:

* Compute how much memory to allocate
* [MmAllocatePagesForMdlEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex)
* [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)
* Copy description of the data to the buffer
* Copy data into pages from internal data structures
* [MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages)
* Give MDL to *Dxgkrnl*

### `DataSize` [in]

The number of bytes in the buffer that **pData** points to.

### `pData` [in, optional]

A pointer to the virtual memory to save.

### `MetaDataSize` [in]

The number of bytes in the buffer that *pMetaData* points to.

### `pMetaData` [in, optional]

The virtual memory pointer to metadata that is associated with the saved memory block.

## Remarks

The driver must not save the same physical page twice.

## See also

[**DXGKCB_SAVEMEMORYFORHOTUPDATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_savememoryforhotupdate)