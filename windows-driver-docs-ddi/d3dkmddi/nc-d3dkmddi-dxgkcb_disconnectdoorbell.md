## Description

KMD calls **DxgkCbDisconnectDoorbell** to notify *Dxgkrnl* that KMD needs to disconnect a previously connected doorbell from a hardware queue.

## Parameters

### `pArgs`

[in] Pointer to a [**DXGKARGCB_DISCONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_disconnectdoorbell) structure that describes the doorbell to disconnect.

## Return value

**DxgkCbDisconnectDoorbell** returns STATUS_INVALID_PARAMETER if *Dxgkrnl* can't find the associated **hDoorbell** for **hHwQueue**, or if **DisconnectReason** isn't one of the **D3DDDI_DOORBELLSTATUS_DISCONNECTED_*XXX*** values. In all other cases this function succeeds, even when the doorbell is already disconnected.

## Remarks

KMD calls this function to notify *Dxgkrnl* when it needs to disconnect a doorbell. KMD should consider the physical doorbell address to be disconnected only after return from this callback.

*Dxgkrnl* unmaps the virtual addresses and marks the doorbell as disconnected. Specifically, *Dxgkrnl* does the following steps to disconnect the doorbell:

* Rotates the user-mode [**DoorbellCpuVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell) to a dummy page so that UMD can no longer write to the physical doorbell location.
* Writes the **DisconnectReason** into **DoorbellStatusCpuVirtualAddress** so that UMD knows that the doorbell is disconnected and the reason why.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**DXGKARGCB_DISCONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_disconnectdoorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)