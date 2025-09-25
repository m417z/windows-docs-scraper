# ID2D1TransformGraph::SetPassthroughGraph

## Description

Uses the specified input as the effect output.

## Parameters

### `effectInputIndex`

The index of the input to the effect.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred |
| D2DERR_NOT_FOUND = (HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) | Direct2D could not locate the specified node. |

## See also

[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)