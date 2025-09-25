# ID2D1TransformGraph::RemoveNode

## Description

Removes the provided node from the transform graph.

## Parameters

### `node` [in]

Type: **[ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode)***

The node that will be removed from the transform graph.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred |
| D2DERR_NOT_FOUND = (HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) | Direct2D could not locate the specified node. |

## Remarks

The node must already exist in the graph; otherwise, the call fails with **D2DERR_NOT_FOUND**.

Any connections to this node will be removed when the node is removed.

After the node is removed, it cannot be used by the interface until it has been added to the graph by [AddNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transformgraph-addnode).

## See also

[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)