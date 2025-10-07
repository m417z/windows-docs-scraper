# D3DXPASS\_DESC structure

Describes a pass for an effect object.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

String value used for the pass.

**Annotations**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Annotations are user-specific data that can be attached to any technique, pass, or parameter. See [Add Information to Effect Parameters with\_Annotations](https://learn.microsoft.com/windows/win32/direct3d9/using-an-effect).

**pVertexShaderFunction**

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the vertex shader function. If an effect is created with [D3DXFX\_NOT\_CLONEABLE](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfx), this structure will return a **NULL** pointer when called by [**GetPassDesc**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbaseeffect--getpassdesc).

**pPixelShaderFunction**

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the pixel shader function. If an effect is created with [D3DXFX\_NOT\_CLONEABLE](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfx), this structure will return a **NULL** pointer when called by [**GetPassDesc**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbaseeffect--getpassdesc).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9effect.h |

## See also

[Effect Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-structures)

[**GetPassDesc**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbaseeffect--getpassdesc)

