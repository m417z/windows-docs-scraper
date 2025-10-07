# D3DX10DisassembleEffect function

> [!Note]
> Instead of using this legacy function, we recommend that you use the [**D3DDisassemble**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3ddisassemble) API.

This function -- which disassembles a compiled effect into a text string that contains assembly instructions and register assignments -- has been deprecated. Instead, use [**D3DDisassemble10Effect**](https://learn.microsoft.com/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3ddisassemble10effect).

## Parameters

*pEffect* \[in\]

Type: **[**ID3D10Effect**](https://learn.microsoft.com/windows/desktop/api/D3D10Effect/nn-d3d10effect-id3d10effect)\***

A pointer to the effect interface (see [**ID3D10Effect Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10Effect/nn-d3d10effect-id3d10effect)).

*EnableColorCode* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Include HTML tags in the output to color code the result.

*ppDisassembly* \[out\]

Type: **[**ID3D10Blob**](https://learn.microsoft.com/windows/desktop/api/D3DCommon/nn-d3dcommon-id3d10blob)\*\***

Address of a buffer (see [**ID3D10Blob Interface**](https://learn.microsoft.com/windows/desktop/api/D3DCommon/nn-d3dcommon-id3d10blob)) which contains the disassembled effect.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

