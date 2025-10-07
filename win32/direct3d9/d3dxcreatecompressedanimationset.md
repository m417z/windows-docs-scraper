# D3DXCreateCompressedAnimationSet function

Creates a [**ID3DXCompressedAnimationSet**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxcompressedanimationset) key framed animation set interface that stores key frame data in a compressed format.

## Parameters

*pName* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the name of the animation set.

*TicksPerSecond* \[in\]

Type: **[**DOUBLE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of key frame ticks that elapse per second.

*Playback* \[in\]

Type: **[**D3DXPLAYBACK\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplayback-type)**

Type of the animation set playback loop. See [**D3DXPLAYBACK\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplayback-type).

*pCompressedData* \[in\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)**

Pointer to the [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) buffer that stores the animation set as compressed data.

*NumCallbackKeys* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of callback keys.

*pCallKeys* \[in\]

Type: **const [**LPD3DXKEY\_CALLBACK**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxkey-callback)\***

Pointer to a [**D3DXKEY\_CALLBACK**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxkey-callback) structure that stores user callback data.

*ppAnimationSet* \[out\]

Type: **[**LPD3DXCOMPRESSEDANIMATIONSET**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxcompressedanimationset)\***

Address of a pointer to the [**ID3DXCompressedAnimationSet**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxcompressedanimationset) interface that stores key framed animation set data in a compressed format.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |
| Library<br> | D3dx9.lib |

## See also

[Animation Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-animation)

