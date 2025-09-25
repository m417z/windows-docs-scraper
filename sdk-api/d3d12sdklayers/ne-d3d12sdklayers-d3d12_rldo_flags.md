# D3D12_RLDO_FLAGS enumeration

## Description

Specifies options for the amount of information to report about a live device object's lifetime.

## Constants

### `D3D12_RLDO_NONE:0`

### `D3D12_RLDO_SUMMARY:0x1`

Obtain a summary about a live device object's lifetime.

### `D3D12_RLDO_DETAIL:0x2`

Obtain detailed information about a live device object's lifetime.

### `D3D12_RLDO_IGNORE_INTERNAL:0x4`

This flag indicates to ignore objects which have no external refcounts keeping them alive. D3D objects are printed using an external refcount and an internal refcount. Typically, all objects are printed. This flag means ignore the objects whose external refcount is 0, because the application is not responsible for keeping them alive.

## Remarks

This enumeration is used by [ID3D12DebugDevice::ReportLiveDeviceObjects](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice-reportlivedeviceobjects).

## See also

[Debug Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-enumerations)