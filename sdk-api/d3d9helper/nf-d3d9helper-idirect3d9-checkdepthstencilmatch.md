# IDirect3D9::CheckDepthStencilMatch

## Description

Determines whether a depth-stencil format is compatible with a render-target format in a particular display mode.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter to query. D3DADAPTER_DEFAULT is always the primary display adapter.

### `DeviceType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type, identifying the device type.

### `AdapterFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, identifying the format of the display mode into which the adapter will be placed.

### `RenderTargetFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, identifying the format of the render-target surface to be tested.

### `DepthStencilFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, identifying the format of the depth-stencil surface to be tested.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the depth-stencil format is compatible with the render-target format in the display mode, this method returns D3D_OK. D3DERR_INVALIDCALL can be returned if one or more of the parameters is invalid. If a depth-stencil format is not compatible with the render target in the display mode, then this method returns D3DERR_NOTAVAILABLE.

## Remarks

This method is provided to enable applications to work with hardware requiring that certain depth formats can only work with certain render-target formats.

The behavior of this method has been changed for DirectX 8.1. This method now pays attention to the D24x8 and D32 depth-stencil formats. The previous version assumed that these formats would always be usable with 32- or 16-bit render targets. This method will now return D3D_OK for these formats only if the device is capable of mixed-depth operations.

The following code fragment shows how you could use [CheckDeviceFormat](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat) to validate a depth stencil format.

```

BOOL IsDepthFormatOk(D3DFORMAT DepthFormat,
                          D3DFORMAT AdapterFormat,
                          D3DFORMAT BackBufferFormat)
{

    // Verify that the depth format exists
    HRESULT hr = pD3D->CheckDeviceFormat(D3DADAPTER_DEFAULT,
                                         D3DDEVTYPE_HAL,
                                         AdapterFormat,
                                         D3DUSAGE_DEPTHSTENCIL,
                                         D3DRTYPE_SURFACE,
                                         DepthFormat);

    if(FAILED(hr)) return FALSE;

    // Verify that the depth format is compatible
    hr = pD3D->CheckDepthStencilMatch(D3DADAPTER_DEFAULT,
                                      D3DDEVTYPE_HAL,
                                      AdapterFormat,
                                      BackBufferFormat,
                                      DepthFormat);

    return SUCCEEDED(hr);

}

```

The preceding call will return **FALSE** if DepthFormat cannot be used in conjunction with AdapterFormat and BackBufferFormat.

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)