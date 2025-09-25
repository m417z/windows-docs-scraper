# ID2D1TransformGraph::SetOutputNode

## Description

Sets the output node for the transform graph.

## Parameters

### `node` [in]

Type: **[ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode)***

The node that will be considered the output of the transform node.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred |
| D2DERR_NOT_FOUND = (HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) | Direct2D could not locate the specified node. |

## Remarks

The node must already exist in the graph; otherwise, the call fails with **D2DERR_NOT_FOUND**.

## See also

[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)