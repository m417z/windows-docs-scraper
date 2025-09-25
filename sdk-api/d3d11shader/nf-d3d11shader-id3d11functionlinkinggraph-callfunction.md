# ID3D11FunctionLinkingGraph::CallFunction

## Description

Creates a call-function linking node to use in the function-linking-graph.

## Parameters

### `pModuleInstanceNamespace` [in, optional]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The optional namespace for the function, or **NULL** if no namespace is needed.

### `pModuleWithFunctionPrototype` [in]

Type: **[ID3D11Module](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11module)***

A pointer to the [ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance) interface for the library module that contains the function prototype.

### `pFunctionName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the function.

### `ppCallNode` [out]

Type: **[ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode)****

A pointer to a variable that receives a pointer to the [ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode) interface that represents the function in the function-linking-graph.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11FunctionLinkingGraph](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionlinkinggraph)