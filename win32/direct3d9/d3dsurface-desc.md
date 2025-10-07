# D3DSURFACE\_DESC structure

Describes a surface.

## Members

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the surface format.

**Type**

Type: **[**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype)**

Member of the [**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype) enumerated type, identifying this resource as a surface.

**Usage**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Either the D3DUSAGE\_DEPTHSTENCIL or D3DUSAGE\_RENDERTARGET values. For more information, see [**D3DUSAGE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage).

**Pool**

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, specifying the class of memory allocated for this surface.

**MultiSampleType**

Type: **[**D3DMULTISAMPLE\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmultisample-type)**

Member of the [**D3DMULTISAMPLE\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmultisample-type) enumerated type, specifying the levels of full-scene multisampling supported by the surface.

**MultiSampleQuality**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Quality level. The valid range is between zero and one less than the level returned by pQualityLevels used by [**CheckDeviceMultiSampleType**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdevicemultisampletype). Passing a larger value returns the error, D3DERR\_INVALIDCALL. The MultisampleQuality values of paired render targets, depth stencil surfaces and the MultiSample type must all match.

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the surface, in pixels.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the surface, in pixels.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetLevelDesc**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dcubetexture9-getleveldesc)

[**GetDesc**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-getdesc)

[**GetLevelDesc**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dcubetexture9-getleveldesc)

