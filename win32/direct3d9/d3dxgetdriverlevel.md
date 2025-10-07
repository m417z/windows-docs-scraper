# D3DXGetDriverLevel function

Returns the driver level.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface representing the device.

## Return value

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The driver level. See remarks.

## Remarks

This method returns the driver version, which is one of the following:

- 700 - Direct3D 7 level driver
- 800 - Direct3D 8 level driver
- 900 - Direct3D 9 level driver

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |
| Library<br> | D3dx9.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-general-purpose)

