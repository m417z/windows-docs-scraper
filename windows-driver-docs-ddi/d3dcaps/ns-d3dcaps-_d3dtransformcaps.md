# _D3DTRANSFORMCAPS structure

## Description

 Obsolete in DirectX 8.0 and later versions.

D3DTRANSFORMCAPS structure describes the transform capabilities of a device.

## Members

### `dwSize`

Specifies the size, in bytes, of the D3DTRANSFORMCAPS structure.

### `dwCaps`

Specifies flags describing the capabilities of the lighting module. The following flag is defined:

D3DTRANSFORMCAPS_CLIP

The device can do clipping operations while transforming.

## Remarks

This structure has been replaced by D3DCAPS8 (see the DirectX 8.0 SDK documentation) for DirectX 8.0 and later runtimes, but is required for DirectX 7.0 and earlier runtime compatibility. See [Reporting DirectX 8.0 Style Direct3D Capabilities](https://learn.microsoft.com/windows-hardware/drivers/display/reporting-directx-8-0-style-direct3d-capabilities) for details.

This structure is a member of the [D3DDEVICEDESC_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3ddevicedesc_v1) structure.

## See also

[D3DDEVICEDESC_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3ddevicedesc_v1)