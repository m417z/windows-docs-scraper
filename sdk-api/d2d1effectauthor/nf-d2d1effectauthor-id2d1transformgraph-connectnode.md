# ID2D1TransformGraph::ConnectNode

## Description

Connects two nodes inside the transform graph.

## Parameters

### `fromNode` [in]

Type: **[ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode)***

The node from which the connection will be made.

### `toNode` [in]

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

## Remarks

Both nodes must already exist in the graph; otherwise, the call fails with **D2DERR_NOT_FOUND**.

## See also

[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)