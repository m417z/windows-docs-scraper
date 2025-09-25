# D3DKMT_GET_DEVICE_VIDPN_OWNERSHIP_INFO structure

## Description

The **D3DKMT_GET_DEVICE_VIDPN_OWNERSHIP_INFO** structure is used to get device VidPn ownership information.

## Members

### `hDevice`

A handle to the device.

### `bFailedDwmAcquireVidPn`

Boolean value that indicates whether the Desktop Windows Manager (DWM) failed to acquire the VidPn. This is set TRUE if DWM failed to acquire the VidPn due to another DWM device already owning the VidPn.

## See also

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)