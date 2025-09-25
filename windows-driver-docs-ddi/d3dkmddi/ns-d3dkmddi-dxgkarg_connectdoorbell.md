## Description

The **DXGKARG_CONNECTDOORBELL** structure contains parameters for [**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell).

## Members

### `hDoorbell`

[in] KMD handle to the doorbell object, which was previously created using [**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell).

### `Flags`

[in] A bit field of [**DXGKARG_CONNECTDOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_connectdoorbell_flags) values specifying the doorbell connection flags. If UMD created this doorbell with the **RequireSecondaryCpuVA** flag, then *Dxgkrnl* sets the **RequireSecondaryAddress** flag in this DDI to inform KMD that this doorbell requires two physical addresses.

### `KernelCpuVirtualAddress`

[out] Kernel-mode CPU virtual address mapped to the physical address that KMD wants to assign to this doorbell. *Dxgkrnl* will map this address to a process address space CPU virtual address that was provided to the UMD in [**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell). UMD will write a specific value to this address, effectively "ringing the doorbell" to notify the GPU scheduler of a new work submission on **hHwQueue**.

### `SecondaryKernelCpuVirtualAddress`

[out/optional] Kernel-mode CPU virtual address mapped to the secondary physical address that KMD wants to assign to this doorbell, if required.

### `Status`

[out] A [**D3DDDI_DOORBELLSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_doorbellstatus) value that KMD wants *Dxgkrnl* to write into the UMD-visible page that [**pDoorbellStatusCpuVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell) points to. This value can only be D3DDDI_DOORBELL_STATUS_CONNECTED or D3DDDI_DOORBELL_STATUS_CONNECTED_NOTIFY.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DDDI_DOORBELLSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_doorbellstatus)

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)

[**DXGKARG_CONNECTDOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_connectdoorbell_flags)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)