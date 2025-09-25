# IDirect3D9::CheckDeviceFormatConversion

## Description

Tests the device to see if it supports conversion from one display format to another.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Display adapter ordinal number. D3DADAPTER_DEFAULT is always the primary display adapter. This method returns D3DERR_INVALIDCALL when this value equals or exceeds the number of display adapters in the system.

### `DeviceType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Device type. Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type.

### `SourceFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Source adapter format. Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type.

### `TargetFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Target adapter format. Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value is D3DERR_INVALIDCALL.
The method will return D3DERR_NOTAVAILABLE when the hardware does not support conversion between the two formats.

## Remarks

Using [CheckDeviceType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdevicetype) to test for compatibility between a back buffer that differs from the display format will return appropriate values. This means that the call will reflect device capabilities. If the device cannot render to the requested back buffer format, the call will still return D3DERR_NOTAVAILABLE. If the device can render to the format, but cannot perform the color-converting presentation, the return value will also be D3DERR_NOTAVAILABLE. Applications can discover hardware support for the presentation itself by calling **CheckDeviceFormatConversion**. No software emulation for the color-converting presentation itself will be offered.

**CheckDeviceFormatConversion** can also be used to determine which combinations of source surface formats and destination surface formats are permissible in calls to [StretchRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-stretchrect).

Color conversion is restricted to the following source and target formats.

* The source format must be a FOURCC format or a valid back buffer format. For a list of these, see [FourCC Formats](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) and BackBuffer or Display Formats.
* The target format must be one of these unsigned formats:

  |  |  |  |
  | --- | --- | --- |
  | D3DFMT_X1R5G5B5 | D3DFMT_A1R5G5B5 | D3DFMT_R5G6B5 |
  | D3DFMT_R8G8B8 | D3DFMT_X8R8G8B8 | D3DFMT_A8R8G8B8 |
  | D3DFMT_A2R10G10B10 | D3DFMT_A16B16G16R16 | D3DFMT_A2B10G10R10 |
  | D3DFMT_A8B8G8R8 | D3DFMT_X8B8G8R8 | D3DFMT_A16B16G16R16F |
  | D3DFMT_A32B32G32R32F |  |  |

## See also

[ColorFill](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-colorfill)

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)