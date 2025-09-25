# DXVACompBufferInfo structure

## Description

Specifies the requirements for compressed surfaces for DirectX Video Acceleration (DXVA).

To get this information, call [IDirect3DVideoDevice9::GetDXVACompressedBufferInfo](https://learn.microsoft.com/windows/desktop/medfound/idirect3dvideodevice9-getdxvacompressedbufferinfo). Each **DXVACompBufferInfo** structure gives the requirements for a specific DXVA surface type. The surface type is defined implicitly by the index of the array that is passed into the *pBufferInfo* parameter.

## Members

### `NumCompBuffers`

The number of surfaces of this type to create.

### `WidthToCreate`

The width of the surface, in pixels.

### `HeightToCreate`

The height of the surface, in pixels.

### `BytesToAllocate`

The size of the surface, in bytes.

### `Usage`

A bitwise **OR** of one or more **D3DUSAGE** constants.

### `Pool`

The memory pool in which to create the surface, specified as a **D3DPOOL** value.

### `Format`

The pixel format, specified as a **D3DFORMAT** value.

## Remarks

To create the compressed surfaces, call [IDirect3DVideoDevice9::CreateSurface](https://learn.microsoft.com/windows/desktop/medfound/idirect3dvideodevice9-createsurface).

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDirect3DVideoDevice9::GetDXVACompressedBufferInfo](https://learn.microsoft.com/windows/desktop/medfound/idirect3dvideodevice9-getdxvacompressedbufferinfo)