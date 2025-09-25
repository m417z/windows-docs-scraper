# RxCeFreeIrp function

## Description

**RxCeFreeIrp** frees an IRP.

## Parameters

### `pIrp`

A pointer to the IRP to be freed.

## Remarks

An IRP allocated with an associated memory descriptor list allocated with **RxCeAllocateIrpWithMDL** should be freed when the IRP is completed using **RxCeFreeIrp**.

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[RxCeAllocateIrpWithMDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceallocateirpwithmdl)