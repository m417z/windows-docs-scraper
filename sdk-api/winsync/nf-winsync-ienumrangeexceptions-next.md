# IEnumRangeExceptions::Next

## Description

Returns the next elements in the change unit exception set, if they are available.

## Parameters

### `cExceptions` [in]

The number of range exception elements to retrieve in the range from zero to 1000.

### `ppRangeException` [out]

Returns the next *pcFetched* range exceptions.

### `pcFetched` [in, out]

Returns the number of range exceptions returned. This value can be **NULL** only if *cExceptions* is 1.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | There are no more elements to retrieve. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## See also

[IEnumRangeExceptions Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumrangeexceptions)