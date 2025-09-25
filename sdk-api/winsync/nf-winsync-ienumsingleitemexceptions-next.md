# IEnumSingleItemExceptions::Next

## Description

Returns the next elements in the single-item exception set, if they are available.

## Parameters

### `cExceptions` [in]

The number of single-item exceptions to retrieve in the range from zero to 1000.

### `ppSingleItemException` [out]

Returns the next *pcFetched* single-item exceptions.

### `pcFetched` [in, out]

Returns the number of single-item exceptions returned. This value can be **NULL** only if *cExceptions* is 1.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | There are no more single-item exceptions to retrieve. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## See also

[IEnumSingleItemExceptions Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumsingleitemexceptions)