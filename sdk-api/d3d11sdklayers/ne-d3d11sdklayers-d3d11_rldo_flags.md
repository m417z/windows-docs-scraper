# D3D11_RLDO_FLAGS enumeration

## Description

Options for the amount of information to report about a device object's lifetime.

## Constants

### `D3D11_RLDO_SUMMARY:0x1`

Specifies to obtain a summary about a device object's lifetime.

### `D3D11_RLDO_DETAIL:0x2`

Specifies to obtain detailed information about a device object's lifetime.

### `D3D11_RLDO_IGNORE_INTERNAL:0x4`

This flag indicates to ignore objects which have no external refcounts keeping them alive. D3D objects are printed using an external refcount and an internal refcount. Typically, all objects are printed. This flag means ignore the objects whose external refcount is 0, because the application is not responsible for keeping them alive.

## Remarks

This enumeration is used by [ID3D11Debug::ReportLiveDeviceObjects](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11debug-reportlivedeviceobjects).

Several inline functions exist to combine the options using operators, see the D3D11SDKLayers.h header file for details.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-enums)