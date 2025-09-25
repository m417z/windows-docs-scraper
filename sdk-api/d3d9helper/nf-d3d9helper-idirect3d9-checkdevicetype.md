# IDirect3D9::CheckDeviceType

## Description

Verifies whether a hardware accelerated device type can be used on this adapter.

## Parameters

### `iAdapter`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter to enumerate. D3DADAPTER_DEFAULT is always the primary display adapter. This method returns D3DERR_INVALIDCALL when this value equals or exceeds the number of display adapters in the system.

### `DevType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type, indicating the device type to check.

### `DisplayFormat`

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, indicating the format of the adapter display mode for which the device type is to be checked. For example, some devices will operate only in 16-bits-per-pixel modes.

### `BackBufferFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Back buffer format. For more information about formats, see [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat). This value must be one of the render-target formats. You can use [GetAdapterDisplayMode](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-getadapterdisplaymode) to obtain the current format.
For windowed applications, the back buffer format does not need to match the display mode format if the hardware supports color conversion. The set of possible back buffer formats is constrained, but the runtime will allow any valid back buffer format to be presented to any desktop format. There is the additional requirement that the device be operable in the desktop because devices typically do not operate in 8 bits per pixel modes.
Full-screen applications cannot do color conversion.
D3DFMT_UNKNOWN is allowed for windowed mode.

### `bWindowed` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value indicating whether the device type will be used in full-screen or windowed mode. If set to **TRUE**, the query is performed for windowed applications; otherwise, this value should be set **FALSE**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the device can be used on this adapter, D3D_OK is returned.

 D3DERR_INVALIDCALL is returned if Adapter equals or exceeds the number of display adapters in the system. D3DERR_INVALIDCALL is also returned if **CheckDeviceType** specified a device that does not exist.

 D3DERR_NOTAVAILABLE is returned if the requested back buffer format is not supported, or if hardware acceleration is not available for the specified formats.

## Remarks

A hal device type requires hardware acceleration. Applications can use CheckDeviceType to determine if the needed hardware and drivers are present to support a hal device.

Full-screen applications should not specify a DisplayFormat that contains an alpha channel. This will result in a failed call. Note that an alpha channel can be present in the back buffer but the two display formats must be identical in all other respects. For example, if DisplayFormat = D3DFMT_X1R5G5B5, valid values for BackBufferFormat include D3DFMT_X1R5G5B5 and D3DFMT_A1R5G5B5 but exclude D3DFMT_R5G6B5.

The following code fragment shows how you could use CheckDeviceType to test whether a certain device type can be used on this adapter.

```

if(SUCCEEDED(pD3Device->CheckDeviceType(D3DADAPTER_DEFAULT,
                                        D3DDEVTYPE_HAL,
                                        DisplayFormat,
                                        BackBufferFormat,
                                        bIsWindowed)))

     return S_OK;
// There is no HAL on this adapter using this render-target format.
// Try again, using another format.

```

This code returns S_OK if the device can be used on the default adapter with the specified surface format.

Using **CheckDeviceType** to test for compatibility between a back buffer that differs from the display format will return appropriate values. This means that the call will reflect device capabilities. If the device cannot render to the requested back-buffer format, the call will still return D3DERR_NOTAVAILABLE. If the device can render to the format, but cannot perform the color-converting presentation, the return value will also be D3DERR_NOTAVAILABLE. Applications can discover hardware support for the presentation itself by calling [CheckDeviceFormatConversion](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformatconversion). No software emulation for the color-converting presentation itself will be offered.

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)