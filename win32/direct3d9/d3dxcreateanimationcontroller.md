# D3DXCreateAnimationController function

Creates an animation controller object.

## Parameters

*MaxNumAnimationOutputs* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum number of animation outputs the controller can support.

*MaxNumAnimationSets* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum number of animation sets that can be mixed.

*MaxNumTracks* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum number of animation sets that can be mixed simultaneously.

*MaxNumEvents* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum number of outstanding events that the controller will support.

*ppAnimController* \[out\]

Type: **[**LPD3DXANIMATIONCONTROLLER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller)\***

Pointer to the animation controller object created. See [**ID3DXAnimationController**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxanimationcontroller).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

An animation controller controls an animation mixer. The controller adds methods to modify blending parameters over time to enable smooth transitions.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |
| Library<br> | D3dx9.lib |

## See also

[Animation Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-animation)

