## Description

The **D3DDDI_DOORBELLSTATUS** enumeration indicates the status of a doorbell object.

## Constants

### `D3DDDI_DOORBELLSTATUS_CONNECTED`

Indicates that the doorbell object is successfully connected to a hardware queue and ready for work submission.

### `D3DDDI_DOORBELLSTATUS_CONNECTED_NOTIFY_KMD`

Indicates that the doorbell object is connected; however, after every new work submission and doorbell ring, UMD should notify KMD by calling [**D3DKMTNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtnotifyworksubmission).

### `D3DDDI_DOORBELLSTATUS_DISCONNECTED_RETRY`

Indicates that the doorbell can't be connected at this time, but UMD should retry to connect it.

### `D3DDDI_DOORBELLSTATUS_DISCONNECTED_ABORT`

Indicates that the doorbell won't be connected and UMD can't use this hardware queue for work submission. This failure typically implies a nonrecoverable scenario such as a GPU reset or stopped adapter.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**DXGKARG_CONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_connectdoorbell)

[**DXGKARG_DISCONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_disconnectdoorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)

[**DxgkDdiDisconnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_disconnectdoorbell)