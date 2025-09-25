# ID3D11FunctionLinkingGraph::PassValueWithSwizzle

## Description

Passes a value with swizzle from a source linking node to a destination linking node.

## Parameters

### `pSrcNode` [in]

Type: **[ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode)***

A pointer to the [ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode) interface for the source linking node.

### `SrcParameterIndex` [in]

Type: **INT**

The zero-based index of the source parameter.

### `pSrcSwizzle` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the source swizzle.

### `pDstNode` [in]

Type: **[ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode)***

A pointer to the [ID3D11LinkingNode](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linkingnode) interface for the destination linking node.

### `DstParameterIndex` [in]

Type: **INT**

The zero-based index of the destination parameter.

### `pDstSwizzle` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the destination swizzle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11FunctionLinkingGraph](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11functionlinkinggraph)