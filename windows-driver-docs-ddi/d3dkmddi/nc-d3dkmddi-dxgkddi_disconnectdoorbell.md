## Description

The **DxgkDdiDisconnectDoorbell** function disconnects a previously connected doorbell from a hardware queue.

## Parameters

### `pArgs`

[in/out] Pointer to a [**DXGKARG_DISCONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_disconnectdoorbell) structure that describes the doorbell to disconnect.

## Return value

**DxgkDdiDisconnectDoorbell** must succeed and return STATUS_SUCCESS.

## Remarks

The OS calls **DxgkDdiDisconnectDoorbell** to unmap the physical doorbell location assigned to this doorbell. KMD should disconnect the hardware queue, doorbell physical address and engine, etc. The physical doorbell location can be assigned to some other logical doorbell object.

KMD should not destroy or free any other objects associated with **hDoorbell** because the doorbell object is not being destroyed and can be reconnected at a later point.

On return from this DDI call, *Dxgkrnl* does the following steps to disconnect the doorbell:

* Rotates the user-mode [**DoorbellCpuVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell) to a dummy page so that UMD can no longer write to the physical doorbell location.
* Writes [D3DDDI_DOORBELL_STATUS_DISCONNECTED_RETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_doorbellstatus) into **DoorbellStatusCpuVirtualAddress** so that UMD knows the doorbell is disconnected.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DDDI_DOORBELLSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_doorbellstatus)

[**D3DKMT_CREATE_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell)

[**DXGKARG_DISCONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_disconnectdoorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)

[**DxgkDdiDisconnectDoorbellCB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell)