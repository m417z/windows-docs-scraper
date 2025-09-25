# _D3DLIGHTINGCAPS structure

## Description

 Obsolete in DirectX 8.0 and later versions; see Remarks.

The D3DLIGHTINGCAPS structure describes the lighting capabilities of a device.

## Members

### `dwSize`

Specifies the size, in bytes, of the D3DLIGHTINGCAPS structure.

### `dwCaps`

 Specifies flags describing the capabilities of the lighting module. The following flags are defined:

|Value|Meaning|
|--- |--- |
|D3DLIGHTCAPS_DIRECTIONAL|Directional lights are supported.|
|D3DLIGHTCAPS_GLSPOT|OpenGL-style spotlights are supported.|
|D3DLIGHTCAPS_PARALLELPOINT|Parallel-point lights are supported.|
|D3DLIGHTCAPS_POINT|Point lights are supported.|
|D3DLIGHTCAPS_SPOT|Spotlights are supported.|

### `dwLightingModel`

 Specifies flags indicating whether the lighting model is RGB or monochrome. The following flags are defined:

|Value|Meaning|
|--- |--- |
|D3DLIGHTINGMODEL_MONO|The lighting model is monochromatic.|
|D3DLIGHTINGMODEL_RGB|The lighting model is RGB.|

### `dwNumLights`

Specifies the number of lights that can be handled.

## Remarks

This structure has been replaced by D3DCAPS8 (see the DirectX 8.0 SDK documentation) for DirectX 8.0 and later runtimes, but is required for DirectX 7.0 and earlier runtime compatibility. See [Reporting DirectX 8.0 Style Direct3D Capabilities](https://learn.microsoft.com/windows-hardware/drivers/display/reporting-directx-8-0-style-direct3d-capabilities) for details.

This structure is a member of the [D3DDEVICEDESC_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3ddevicedesc_v1) structure.

## See also

[D3DDEVICEDESC_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3ddevicedesc_v1)