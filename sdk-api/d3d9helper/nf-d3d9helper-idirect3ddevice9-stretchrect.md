# IDirect3DDevice9::StretchRect

## Description

Copy the contents of the source rectangle to the destination rectangle. The source rectangle can be stretched and filtered by the copy. This function is often used to change the aspect ratio of a video stream.

## Parameters

### `pSourceSurface` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to the source surface. See [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9).

### `pSourceRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to the source rectangle. A **NULL** for this parameter causes the entire source surface to be used.

### `pDestSurface` [in]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)***

Pointer to the destination surface. See [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9).

### `pDestRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to the destination rectangle. A **NULL** for this parameter causes the entire destination surface to be used.

### `Filter` [in]

Type: **[D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype)**

Filter type. Allowable values are D3DTEXF_NONE, D3DTEXF_POINT, or D3DTEXF_LINEAR. For more information, see [D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be:
D3DERR_INVALIDCALL.

## Remarks

StretchRect Restrictions

* Driver support varies. See the section on driver support (below) to see which drivers support which source and destination formats.
* The source and destination surfaces must be created in the default memory pool.
* If filtering is specified, you must set the appropriate filter caps (see StretchRectFilterCaps in [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9)).
* Stretching is not supported between source and destination rectangles on the same surface.
* Stretching is not supported if the destination surface is an off-screen plain surface but the source is not.
* You many not stretch between source and destination rectangles if either surface is in a compressed format (see [Using Compressed Textures (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/using-compressed-textures)).
* Stretching supports color-space conversion from YUV to high-precision RGBA only. Since color conversion support is not supported by software emulation, use [IDirect3D9::CheckDeviceFormatConversion](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformatconversion) to test the hardware for color conversion support.
* If the source or destination surface is a texture surface (or a cube texture surface), you must use a Direct3D 9 driver that supports D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES (see [D3DDEVCAPS2](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevcaps2)).

Additional Restrictions for Depth and Stencil Surfaces

* The source and destination surfaces must be plain depth stencil surfaces (not textures) (see [IDirect3DDevice9::CreateDepthStencilSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createdepthstencilsurface)).
* Neither of the surfaces can be discardable.
* The entire surface must be copied (that is: sub-rectangle copies are not allowed).
* Format conversion, stretching, and shrinking are not supported.
* StretchRect cannot be called inside of a BeginScene/EndScene pair.

Using StretchRect to downsample a Multisample Rendertarget

You can use StretchRect to copy from one rendertarget to another. If the source rendertarget is multisampled, this results in downsampling the source rendertarget. For instance you could:

* Create a multisampled rendertarget.
* Create a second rendertarget of the same size, that is not multisampled.
* Copy (using StretchRect the multisample rendertarget to the second rendertarget.

Note that use of the extra surface involved in using StretchRect to downsample a Multisample Rendertarget will result in a performance hit.

Driver Support

There are many restrictions as to which surface combinations are valid for StretchRect. Factors include whether the driver is a Direct3D 9 driver or older, and whether the operation will result in stretching/shrinking. Since applications are not expected to recognize if the driver is a Direct3D 9 driver or not, the runtime will automatically set a new cap, D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES cap (see [D3DDEVCAPS2](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevcaps2)), for Direct3D 9-level drivers and above.

| DirectX 8 Driver (no stretching) |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
|  |  | Dest formats |  |  |  |
|  |  | Texture | RT texture | RT | Off-screen plain |
| Src formats | Texture | No | No | No | No |
|  | RT texture | No | Yes | Yes | No |
|  | RT | No | Yes | Yes | No |
|  | Off-screen plain | Yes | Yes | Yes | Yes |

| DirectX 8 Driver (stretching) |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
|  |  | Dest formats |  |  |  |
|  |  | Texture | RT texture | RT | Off-screen plain |
| Src formats | Texture | No | No | No | No |
|  | RT texture | No | No | No | No |
|  | RT | No | Yes | Yes | No |
|  | Off-screen plain | No | Yes | Yes | No |

| Direct3D 9 Driver (no stretching) |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
|  |  | Dest formats |  |  |  |
|  |  | Texture | RT texture | RT | Off-screen plain |
| Src formats | Texture | No | Yes | Yes | No |
|  | RT texture | No | Yes | Yes | No |
|  | RT | No | Yes | Yes | No |
|  | Off-screen plain | No | Yes | Yes | Yes |

| Direct3D 9 Driver (stretching) |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
|  |  | Dest formats |  |  |  |
|  |  | Texture | RT texture | RT | Off-screen plain |
| Src formats | Texture | No | Yes | Yes | No |
|  | RT texture | No | Yes | Yes | No |
|  | RT | No | Yes | Yes | No |
|  | Off-screen plain | No | Yes | Yes | No |

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::BeginScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-beginscene)

[IDirect3DDevice9::EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene)