# IDirect3D9::EnumAdapterModes

## Description

Queries the device to determine whether the specified adapter supports the requested format and display mode. This method could be used in a loop to enumerate all the available adapter modes.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter to enumerate. [D3DADAPTER_DEFAULT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-default) is always the primary display adapter. This method returns D3DERR_INVALIDCALL when this value equals or exceeds the number of display adapters in the system.

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Allowable pixel formats. See Remarks.

### `Mode` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Represents the display-mode index which is an unsigned integer between zero and the value returned by [GetAdapterModeCount](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-getadaptermodecount) minus one.

### `pMode` [out]

Type: **[D3DDISPLAYMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymode)***

A pointer to the available display mode of type [D3DDISPLAYMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymode). See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

* If the device can be used on this adapter, D3D_OK is returned.
* If the Adapter equals or exceeds the number of display adapters in the system, D3DERR_INVALIDCALL is returned.
* If either surface format is not supported or if hardware acceleration is not available for the specified formats, D3DERR_NOTAVAILABLE is returned.

## Remarks

An application supplies a display mode and a format to **EnumAdapterModes** which returns a display mode. This method could be used in a loop to enumerate all available display modes.

The application specifies a format and the enumeration is restricted to those display modes that exactly match the format (alpha is ignored). Allowed formats (which are members of [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)) are as follows:

* D3DFMT_A1R5G5B5
* D3DFMT_A2R10G10B10
* D3DFMT_A8R8G8B8
* D3DFMT_R5G6B5
* D3DFMT_X1R5G5B5
* D3DFMT_X8R8G8B8

In addition, **EnumAdapterModes** treats pixel formats 565 and 555 as equivalent, and returns the correct version. The difference comes into play only when the application locks the back buffer and there is an explicit flag that the application must set in order to accomplish this.

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)