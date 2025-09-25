# MmFreePagesFromMdl function

## Description

The **MmFreePagesFromMdl** routine frees all the physical pages that are described by an MDL that was created by the [MmAllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl) routine.

## Parameters

### `MemoryDescriptorList` [in]

Pointer to an MDL that was created by **MmAllocatePagesForMdl**.

## Remarks

**MmFreePagesFromMdl** can only be used to free the memory pages that are described by an MDL that was created by **MmAllocatePagesForMdl**.

After calling **MmFreePagesFromMdl**, the caller must also call [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) to release the memory that was allocated for the MDL structure.

**MmFreePagesFromMdl** runs at IRQL <= APC_LEVEL. For Windows Server 2008 and later versions of the Windows operating system, you can also call this routine at DISPATCH_LEVEL. However, you can improve driver performance by calling at IRQL <= APC_LEVEL.

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[MmAllocatePagesForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl)