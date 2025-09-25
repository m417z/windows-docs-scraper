## Description

The **D3DKMT_DRIVERCAPS_EXT** structure describes the extended capabilities of the display miniport driver (KMD).

## Members

### `VirtualModeSupport`

The driver supports virtual mode.

### `Usb4MonitorSupport`

The driver supports monitors connected via USB4.

### `Reserved`

Reserved for future use.

### `Value`

An alternative way to access the capability bits.

## See also

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)