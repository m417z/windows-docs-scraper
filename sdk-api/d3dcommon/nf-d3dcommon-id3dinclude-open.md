# ID3DInclude::Open

## Description

A user-implemented method for opening and reading the contents of a shader #include file.

## Parameters

### `IncludeType`

Type: **[D3D_INCLUDE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_include_type)**

A [D3D_INCLUDE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_include_type)-typed value that indicates the location of the #include file.

### `pFileName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the #include file.

### `pParentData`

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the container that includes the #include file. The compiler might pass NULL in *pParentData*. For more information, see the "Searching for Include Files" section in [Compile an Effect (Direct3D 11)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-programming-guide-effects-compile).

### `ppData`

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the buffer that contains the include directives. This pointer remains valid until you call[ID3DInclude::Close](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nf-d3dcommon-id3dinclude-close).

### `pBytes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the number of bytes that **Open** returns in *ppData*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The user-implemented method must return S_OK. If **Open** fails when it reads the #include file, the application programming interface (API) that caused **Open** to be called fails. This failure can occur in one of the following situations:

* The high-level shader language (HLSL) shader fails one of the **D3D10CompileShader***** functions.
* The effect fails one of the **D3D10CreateEffect***** functions.

## See also

[ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude)

[ID3DInclude::Close](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nf-d3dcommon-id3dinclude-close)