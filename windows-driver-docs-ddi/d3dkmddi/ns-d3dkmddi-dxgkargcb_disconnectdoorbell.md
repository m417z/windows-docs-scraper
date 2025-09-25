## Description

The **DXGKARGCB_DISCONNECTDOORBELL** structure contains parameters for [**DXGKCB_DISCONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell).

## Members

### `hHwQueue`

[in] Handle to the hardware queue whose doorbell must be disconnected. This handle was previously created using [**DxgkddiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue).

### `hDoorbell`

[in] Handle to the doorbell to disconnect. The doorbell was previously created on the hardware queue identified by **hHwQueue** using [**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell).

### `Flags`

[in] A bit field of [**DXGKARGCB_DISCONNECTDOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_disconnectdoorbell_flags) values specifying the doorbell disconnection flags.

### `DisconnectReason`

[in] A [**D3DDDI_DOORBELLSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_doorbellstatus) enumeration value that specifies the reason for the disconnection. **DisconnectReason** must be one of the **D3DDDI_DOORBELLSTATUS_DISCONNECTED_*XXX*** values.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DDDI_DOORBELLSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_doorbellstatus)

[**DXGKARGCB_DISCONNECTDOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_disconnectdoorbell_flags)

[**DXGKCB_DISCONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell)