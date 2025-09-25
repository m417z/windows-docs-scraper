# IoFreeMdl function

## Description

The **IoFreeMdl** routine releases a caller-allocated memory descriptor list (MDL).

## Parameters

### `Mdl` [in]

Pointer to the MDL to be released.

## Remarks

If a driver allocates an MDL to describe a buffer, it must explicitly release the MDL when operations on the buffer are done.

If the MDL is a partial MDL, **IoFreeMdl** unmaps any pages that have been mapped to the MDL.

If the physical pages that are described by the MDL are locked, the driver must unlock the pages before it frees the MDL.

This routine frees only the specified MDL. Any MDLs that are chained to this MDL must be explicitly freed through additional calls to this routine. For a code example that shows how to free an MDL chain, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl)

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)