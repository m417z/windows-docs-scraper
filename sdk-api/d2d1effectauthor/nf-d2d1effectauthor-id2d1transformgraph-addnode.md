# ID2D1TransformGraph::AddNode

## Description

Adds the provided node to the transform graph.

## Parameters

### `node` [in]

Type: **[ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode)***

The node that will be added to the transform graph.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |

## Remarks

This adds a transform node to the transform graph. A node must be added to the transform graph before it can be interconnected in any way.

A transform graph cannot be directly added to another transform graph.
Only interfaces derived from [ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode) can be added to the transform graph.

## See also

[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)