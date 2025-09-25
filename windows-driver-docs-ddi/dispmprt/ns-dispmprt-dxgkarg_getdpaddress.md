# DXGKARG_GETDPADDRESS structure

## Description

The **DXGKARG_GETDPADDRESS** structure is a parameter for the [**DXGKDDI_GETDPADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdpaddress) callback.

## Members

### `TargetId`

[**D3DDDI_VIDEO_PRESENT_TARGET_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_target) structure that contains information about video present target.

### `DPNativeError`

Field in which the driver can encode more details about the error when returning STATUS_DEVICE_PROTOCOL_ERROR from [**DXGKDDI_GETDPADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdpaddress).

### `RootPortIndex`

Index value of the DP-capable connector.

### `NumLinks`

Number of links between the root port and target device. **NumLinks** should be **0** if the DP monitor is directly connected to the GPU.

### `RelAddress`

DP Relative Address. The format is described in the DP specification.

## Remarks

## See also

[**D3DDDI_VIDEO_PRESENT_TARGET_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_target)

[**DXGKDDI_GETDPADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdpaddress)