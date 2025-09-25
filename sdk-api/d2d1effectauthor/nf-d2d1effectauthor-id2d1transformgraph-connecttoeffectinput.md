# ID2D1TransformGraph::ConnectToEffectInput

## Description

Connects a transform node inside the graph to the corresponding effect input of the encapsulating effect.

## Parameters

### `toEffectInputIndex`

Type: **UINT32**

The effect input to which the transform node will be bound.

### `node` [in]

Type: **[ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode)***

The node to which the connection will be made.

### `toNodeInputIndex`

Type: **UINT32**

The node input that will be connected.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred |
| D2DERR_NOT_FOUND = (HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) | Direct2D could not locate the specified node. |

## See also

[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)