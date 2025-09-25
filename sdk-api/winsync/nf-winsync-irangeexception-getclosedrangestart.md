# IRangeException::GetClosedRangeStart

## Description

Gets the lower bound of the range of item IDs to exclude.

## Parameters

### `pbClosedRangeStart` [in, out]

Returns the lower bound of the range of item IDs to exclude.

### `pcbIdSize` [in, out]

Specifies the number of bytes in *pbClosedRangeStart*. Returns the number of bytes to retrieve the ID when *pbClosedRangeStart* is too small, or returns the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | When *pbClosedRangeStart* is too small. In this case, the required number of bytes is returned in *pcbIdSize*. |

## See also

[IRangeException Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irangeexception)