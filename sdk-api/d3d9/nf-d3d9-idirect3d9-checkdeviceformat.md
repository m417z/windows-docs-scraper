# IDirect3D9::CheckDeviceFormat

## Description

Determines whether a surface format is available as a specified resource type and can be used as a texture, depth-stencil buffer, or render target, or any combination of the three, on a device representing this adapter.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter to query. [D3DADAPTER_DEFAULT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dadapter-default) is always the primary display adapter. This method returns D3DERR_INVALIDCALL when this value equals or exceeds the number of display adapters in the system.

### `DeviceType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type, identifying the device type.

### `AdapterFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, identifying the format of the display mode into which the adapter will be placed.

### `Usage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Requested usage options for the surface. Usage options are any combination of [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) and [D3DUSAGE_QUERY](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage-query) constants (only a subset of the D3DUSAGE constants are valid for **CheckDeviceFormat**; see the table on the D3DUSAGE page).

### `RType` [in]

Type: **[D3DRESOURCETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dresourcetype)**

Resource type requested for use with the queried format. Member of [D3DRESOURCETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dresourcetype).

### `CheckFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Format of the surfaces which may be used, as defined by Usage. Member of [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the format is compatible with the specified device for the requested usage, this method returns D3D_OK.

D3DERR_INVALIDCALL is returned if Adapter equals or exceeds the number of display adapters in the system, or if DeviceType is unsupported.

D3DERR_NOTAVAILABLE is returned if the format is not acceptable to the device for this usage.

## Remarks

Here are some examples using **CheckDeviceFormat** to check for hardware support of:

* An off-screen plain surface format - Specify Usage = 0 and RType = D3DRTYPE_SURFACE.
* A depth-stencil format - The following snippet tests for the passed in depth-stencil format:

  ```

  BOOL IsDepthFormatExisting( D3DFORMAT DepthFormat, D3DFORMAT AdapterFormat )
  {
      HRESULT hr = pD3D->CheckDeviceFormat( D3DADAPTER_DEFAULT,
                                            D3DDEVTYPE_HAL,
                                            AdapterFormat,
                                            D3DUSAGE_DEPTHSTENCIL,
                                            D3DRTYPE_SURFACE,
                                            DepthFormat);

      return SUCCEEDED( hr );
  }
  ```

  See [Selecting a Device (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/selecting-a-device) for more detail on the enumeration process.
* Can this texture be rendered in a particular format - Given the current display mode, this example shows how to verify that the texture format is compatible with the specific back-buffer format:

  ```

  BOOL IsTextureFormatOk( D3DFORMAT TextureFormat, D3DFORMAT AdapterFormat )
  {
      HRESULT hr = pD3D->CheckDeviceFormat( D3DADAPTER_DEFAULT,
                                            D3DDEVTYPE_HAL,
                                            AdapterFormat,
                                            0,
                                            D3DRTYPE_TEXTURE,
                                            TextureFormat);

      return SUCCEEDED( hr );
  }
  ```
* Alpha blending in a pixel shader - Set Usage to [D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage). Expect this to fail for all floating-point render targets.
* Autogeneration of mipmaps - Set Usage to [D3DUSAGE_AUTOGENMIPMAP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage). If the mipmap automatic generation fails, the application will get a non-mipmapped texture. Calling this method is considered a hint, so this method can return D3DOK_NOAUTOGEN (a valid success code) if the only thing that fails is the mipmap generation. For more information about mipmap generation, see [Automatic Generation of Mipmaps (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/automatic-generation-of-mipmaps).

When migrating code from Direct3D 9 to Direct3D 10, the Direct3D 10 equivalent to CheckDeviceFormat is [CheckFormatSupport](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-checkformatsupport).

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)