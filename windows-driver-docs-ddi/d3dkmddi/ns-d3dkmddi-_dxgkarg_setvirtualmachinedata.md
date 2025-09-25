# DXGKARG_SETVIRTUALMACHINEDATA structure

## Description

The **DXGKARG_SETVIRTUALMACHINEDATA** structure contains arguments passed to [**DxgkddiSetVirtualMachineData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvirtualmachinedata).

## Members

### `hKmdVmWorkerProcess`

[in] Handle to the KMD process returned by [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)
with [**VirtualMachineWorkerProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createprocessflags) set.

### `pVmGuid`

[in] Pointer to a GUID that uniquely identifies the VM. This GUID is provided for debugging purposes, so developers can attribute rendering to a specific VM when multiple VMs are running.

### `Flags`

[in] A [**DXGK_VIRTUALMACHINEDATAFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_virtualmachinedataflags) structure that specifies attributes of the VM.

## Remarks

For more information, see [GPU paravitualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

## See also

[**DXGK_VIRTUALMACHINEDATAFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_virtualmachinedataflags)

[**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)

[**DxgkddiSetVirtualMachineData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvirtualmachinedata)