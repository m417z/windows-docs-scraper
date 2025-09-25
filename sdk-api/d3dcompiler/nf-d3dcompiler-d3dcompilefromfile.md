# D3DCompileFromFile function

## Description

**Note** You can use this API to develop your Windows Store apps, but you can't use it in apps that you submit to the Windows Store. Refer to the section, "Compiling shaders for UWP", in the remarks for [D3DCompile2](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile2).

Compiles Microsoft High Level Shader Language (HLSL) code into bytecode for a given target.

## Parameters

### `pFileName` [in]

A pointer to a constant null-terminated string that contains the name of the file that contains the shader code.

### `pDefines` [in, optional]

An optional array of [D3D_SHADER_MACRO](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ns-d3dcommon-d3d_shader_macro) structures that define shader macros. Each macro definition contains a name and a null-terminated definition. If not used, set to **NULL**. The last structure in the array serves as a terminator and must have all members set to **NULL**.

### `pInclude` [in, optional]

 An optional pointer to an [ID3DInclude](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3dinclude) interface that the compiler uses to handle include files. If you set this parameter to **NULL** and the shader contains a #include, a compile error occurs. You can pass the **D3D_COMPILE_STANDARD_FILE_INCLUDE** macro, which is a pointer to a default include handler. This default include handler includes files that are relative to the current directory.

```
#define D3D_COMPILE_STANDARD_FILE_INCLUDE ((ID3DInclude*)(UINT_PTR)1)

```

### `pEntrypoint` [in]

A pointer to a constant null-terminated string that contains the name of the shader entry point function where shader execution begins. When you compile an effect, **D3DCompileFromFile** ignores *pEntrypoint*; we recommend that you set *pEntrypoint* to **NULL** because it is good programming practice to set a pointer parameter to **NULL** if the called function will not use it.

### `pTarget` [in]

A pointer to a constant null-terminated string that specifies the shader target or set of shader features to compile against. The shader target can be a shader model (for example, shader model 2, shader model 3, shader model 4, or shader model 5 and later). The target can also be an effect type (for example, fx_4_1). For info about the targets that various profiles support, see [Specifying Compiler Targets](https://learn.microsoft.com/windows/desktop/direct3dhlsl/specifying-compiler-targets).

### `Flags1` [in]

A combination of shader [compile options](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants) that are combined by using a bitwise **OR** operation. The resulting value specifies how the compiler compiles the HLSL code.

### `Flags2` [in]

A combination of effect [compile options](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-effect-constants) that are combined by using a bitwise **OR** operation. The resulting value specifies how the compiler compiles the effect. When you compile a shader and not an effect file, **D3DCompileFromFile** ignores *Flags2*; we recommend that you set *Flags2* to zero because it is good programming practice to set a nonpointer parameter to zero if the called function will not use it.

### `ppCode` [out]

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the compiled code.

### `ppErrorMsgs` [out, optional]

An optional pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access compiler error messages, or **NULL** if there are no errors.

## Return value

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**Note** The D3dcompiler_44.dll or later version of the file contains the **D3DCompileFromFile** compiler function.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)