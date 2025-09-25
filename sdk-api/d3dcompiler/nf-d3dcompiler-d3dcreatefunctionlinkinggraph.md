# D3DCreateFunctionLinkingGraph function

## Description

Creates a function-linking-graph interface.

**Note** This function is part of the HLSL shader linking technology that you can use on all Direct3D 11 platforms to create precompiled HLSL functions, package them into libraries, and link them into full shaders at run time.

## Parameters

### `uFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved

### `ppFunctionLinkingGraph` [out]

Type: **[ID3D11FunctionLinkingGraph](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionlinkinggraph)****

A pointer to a variable that receives a pointer to the [ID3D11FunctionLinkingGraph](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionlinkinggraph) interface that is used for constructing shaders that consist of a sequence of precompiled function calls.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**Note** The D3dcompiler_47.dll or later version of the DLL contains the **D3DCreateFunctionLinkingGraph** function.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)

[ID3D11FunctionLinkingGraph](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionlinkinggraph)