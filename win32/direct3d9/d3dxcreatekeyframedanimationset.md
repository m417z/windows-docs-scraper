# D3DXCreateKeyframedAnimationSet function

Creates a [**ID3DXKeyframedAnimationSet**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxkeyframedanimationset) key framed animation set interface.

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

*NumAnimations* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of scale, rotate, and translate (SRT) animation sets.

*NumCallbackKeys* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of callback keys.

*pCallKeys* \[in\]

Type: **const [**LPD3DXKEY\_CALLBACK**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxkey-callback)\***

Pointer to a [**D3DXKEY\_CALLBACK**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxkey-callback) structure that stores user callback data.

*ppAnimationSet* \[out\]

Type: **[**LPD3DXKEYFRAMEDANIMATIONSET**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxkeyframedanimationset)\***

Address of a pointer to the [**ID3DXKeyframedAnimationSet**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxkeyframedanimationset) key framed animation set interface.

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

