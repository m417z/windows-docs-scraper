# DXGKARG_RESTOREMEMORYFORHOTUPDATE structure

## Description

Arguments used to restore memory for driver hot update.

## Members

### `Flags` [in]

A [DXGK_RESTOREMEMORYFORHOTUPDATEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_restorememoryforhotupdateflags) structure. When the flag is set, all other input data is set to NULL. The driver can delete all memory, allocated during restore operation.

### `pDataMdl` [in]

The MDL (memory descriptor list), which describes the memory pages to restore.

If the driver returns STATUS_SUCCESS from this function, the driver assumes the ownership of the MDL. The driver can keep the pointer to the MDL until it is no longer used. After that the driver must free the MDL pages and the MDL itself by calling [MmFreePagesFromMdl(pDataMdl)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmfreepagesfrommdl) and [ExFreePool(pDataMdl)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepool).

The driver can use [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache) or [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdl) to get a CPU pointer to the buffer.

Here is an example of how you would get a CPU pointer to the buffer:

```cpp
pBuffer = MmMapLockedPagesSpecifyCache(
    pMdl,
    KernelMode,
    MmCached,
    NULL,
    FALSE,
    NormalPagePriority | MdlMappingNoExecute);

pBuffer = MmGetSystemAddressForMdlSafe(pMdl, NormalPagePriority | MdlMappingNoExecute);
```

### `MetaDataSize` [in]

The number of bytes in the buffer that *pMetaData* points to.

### `pMetaData` [in]

A virtual memory pointer to the metadata that is associated with the memory block.

## Remarks

## See also