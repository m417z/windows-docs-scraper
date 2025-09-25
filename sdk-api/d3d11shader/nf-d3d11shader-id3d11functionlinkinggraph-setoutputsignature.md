# ID3D11FunctionLinkingGraph::SetOutputSignature

## Description

Sets the output signature of the function-linking-graph.

## Parameters

### `pOutputParameters` [in]

Type: **const [D3D11_PARAMETER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_parameter_desc)***

An array of [D3D11_PARAMETER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_parameter_desc) structures for the parameters of the output signature.

### `cOutputParameters` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of output parameters in the *pOutputParameters* array.

### `ppOutputNode` [out]

Type: **[ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode)****

A pointer to a variable that receives a pointer to the [ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode) interface that represents the output signature of the function-linking-graph.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11FunctionLinkingGraph](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionlinkinggraph)