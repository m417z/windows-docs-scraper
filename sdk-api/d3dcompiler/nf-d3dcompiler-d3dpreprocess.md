# D3DPreprocess function

## Description

Preprocesses uncompiled HLSL code.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to uncompiled shader data; either ASCII HLSL code or a compiled effect.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pSrcData*.

### `pSourceName` [in, optional]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

 The name of the file that contains the uncompiled HLSL code.

### `pDefines` [in, optional]

Type: **const [D3D_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)***

 An array of NULL-terminated macro definitions (see [D3D_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)).

### `pInclude` [in, optional]

Type: **[ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude)***

 A pointer to an [ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude) for handling include files. Setting this to **NULL** will cause a compile error if a shader contains a #include. You can pass the **D3D_COMPILE_STANDARD_FILE_INCLUDE** macro, which is a pointer to a default include handler. This default include handler includes files that are relative to the current directory and files that are relative to the directory of the initial source file. When you use **D3D_COMPILE_STANDARD_FILE_INCLUDE**, you must specify the source file name in the *pSourceName* parameter; the compiler will derive the initial relative directory from *pSourceName*.

```cpp
#define D3D_COMPILE_STANDARD_FILE_INCLUDE ((ID3DInclude*)(UINT_PTR)1)

```

### `ppCodeText` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the preprocessed code.

### `ppErrorMsgs` [out, optional]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

 A pointer to an [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) that contains compiler error messages, or **NULL** if there were no errors.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**D3DPreprocess** outputs [#line](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-appendix-pre-line) directives and preserves line numbering of source input so that output line numbering can be properly related to the input source.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)