# ID3D11Linker::AddClipPlaneFromCBuffer

## Description

Adds a [clip plane](https://learn.microsoft.com/windows/desktop/direct3dhlsl/user-clip-planes-on-10level9) with the plane coefficients taken from a [cbuffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-constants) entry for 10Level9 shaders.

## Parameters

### `uCBufferSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [cbuffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-constants) slot number.

### `uCBufferEntry` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [cbuffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-constants) entry number.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Linker](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linker)