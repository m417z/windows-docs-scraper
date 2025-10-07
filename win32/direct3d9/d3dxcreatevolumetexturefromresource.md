# D3DXCreateVolumeTextureFromResource function

Creates a volume texture from a resource.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device to be associated with the volume texture.

*hSrcModule* \[in\]

Type: **[**HMODULE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Handle to the module where the resource is located, or **NULL** for the module associated with the image the operating system used to create the current process.

*pSrcResource* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the resource name. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*ppVolumeTexture* \[out\]

Type: **[**LPDIRECT3DVOLUMETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)\***

Address of a pointer to an [**IDirect3DVolumeTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9) interface representing the created texture object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_NOTAVAILABLE, D3DERR\_OUTOFVIDEOMEMORY, D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateVolumeTextureFromResourceW. Otherwise, the function call resolves to D3DXCreateVolumeTextureFromResourceA because ANSI strings are being used.

The function is equivalent to D3DXCreateVolumeTextureFromResourceEx(pDevice, hSrcModule, pSrcResource, D3DX\_DEFAULT, D3DX\_DEFAULT, D3DX\_DEFAULT, D3DX\_DEFAULT, 0, D3DFMT\_UNKNOWN, D3DPOOL\_MANAGED, D3DX\_DEFAULT, D3DX\_DEFAULT, 0, **NULL**, **NULL**, ppVolumeTexture).

The resource being loaded must be an application-defined resource (RT\_RCDATA).

This function supports the following file formats: .bmp, .dds, .dib, .hdr, .jpg, .pfm, .png, .ppm, and .tga. See [**D3DXIMAGE\_FILEFORMAT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-fileformat).

Note that a resource created with this function when called from a IDirect3DDevice9 object will be placed in the memory class denoted by D3DPOOL\_MANAGED. When this method is called from a IDirect3DDevice9Ex object the resource will be placed in the memory class denoted by D3DPOOL\_DEFAULT.

Filtering is automatically applied to a texture created using this method. The filtering is equivalent to D3DX\_FILTER\_TRIANGLE \| D3DX\_FILTER\_DITHER in [D3DX\_FILTER](https://learn.microsoft.com/windows/win32/direct3d9/d3dx-filter).

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[**D3DXCreateVolumeTextureFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfile)

[**D3DXCreateVolumeTextureFromFileEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfileex)

[**D3DXCreateVolumeTextureFromFileInMemory**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfileinmemory)

[**D3DXCreateVolumeTextureFromFileInMemoryEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromfileinmemoryex)

[**D3DXCreateVolumeTextureFromResourceEx**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreatevolumetexturefromresourceex)

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

