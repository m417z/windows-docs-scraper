# D3DCompile function

## Description

Compile HLSL code or an effect file into bytecode for a given target.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to uncompiled shader data; either ASCII HLSL code or a compiled effect.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pSrcData*.

### `pSourceName` [in, optional]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

 You can use this parameter for strings that specify error messages. If not used, set to **NULL**.

### `pDefines` [in, optional]

Type: **const [D3D_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro)***

An optional array of [D3D_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro) structures that define shader macros. Each macro definition contains a name and a null-terminated definition. If not used, set to **NULL**. The last structure in the array serves as a terminator and must have all members set to **NULL**.

### `pInclude` [in, optional]

Type: **[ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude)***

Optional. A pointer to an [ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude) for handling include files. Setting this to **NULL** will cause a compile error if a shader contains a #include. You can pass the **D3D_COMPILE_STANDARD_FILE_INCLUDE** macro, which is a pointer to a default include handler. This default include handler includes files that are relative to the current directory and files that are relative to the directory of the initial source file. When you use **D3D_COMPILE_STANDARD_FILE_INCLUDE**, you must specify the source file name in the *pSourceName* parameter; the compiler will derive the initial relative directory from *pSourceName*.

```cpp
#define D3D_COMPILE_STANDARD_FILE_INCLUDE ((ID3DInclude*)(UINT_PTR)1)

```

### `pEntrypoint` [in, optional]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the shader entry point function where shader execution begins. When you compile using a fx profile (for example, fx_4_0, fx_5_0, and so on), **D3DCompile** ignores *pEntrypoint*. In this case, we recommend that you set *pEntrypoint* to **NULL** because it is good programming practice to set a pointer parameter to **NULL** if the called function will not use it. For all other shader profiles, a valid *pEntrypoint* is required.

### `pTarget` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that specifies the shader target or set of shader features to compile against. The shader target can be shader model 2, shader model 3, shader model 4, or shader model 5. The target can also be an effect type (for example, fx_4_1). For info about the targets that various profiles support, see [Specifying Compiler Targets](https://learn.microsoft.com/windows/desktop/direct3dhlsl/specifying-compiler-targets).

### `Flags1` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags defined by [D3D compile constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants).

### `Flags2` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags defined by [D3D compile effect constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-effect-constants). When you compile a shader and not an effect file, **D3DCompile** ignores *Flags2*; we recommend that you set *Flags2* to zero because it is good programming practice to set a nonpointer parameter to zero if the called function will not use it.

### `ppCode` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the compiled code.

### `ppErrorMsgs` [out, optional]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access compiler error messages, or **NULL** if there are no errors.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The difference between **D3DCompile** and [D3DCompile2](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile2) is that the latter method takes some optional parameters that can be used to control some aspects of how bytecode is generated. If this extra flexibility is not required, there is no performance gain from using **D3DCompile2**.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)