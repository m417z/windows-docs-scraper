# D3DXDisassembleEffect function

Disassemble an effect.

## Parameters

*pEffect* \[in\]

Type: **[**LPD3DXEFFECT**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffect)**

Pointer to an [**ID3DXEffect**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxeffect) interface that contains the effect.

*EnableColorCode* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Enable color coding to make the disassembly easier to read.

*ppDisassembly* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Returns a buffer containing the disassembled shader. See [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Effect.h |
| Library<br> | D3dx9.lib |

## See also

[Effect Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-functions)

