# IEnumClockVector::Next

## Description

Returns the next elements in the clock vector, if they are available.

## Parameters

### `cClockVectorElements` [in]

The number of clock vector elements to retrieve in the range of zero to 1000.

### `ppiClockVectorElements` [out]

Returns the next *pcFetched* clock vector elements.

### `pcFetched` [in, out]

Returns the number of clock vector elements that were retrieved. This value can be **NULL** if *cClockVectorElements* is 1; otherwise, it cannot be **NULL**.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | If there are no more elements to retrieve. |
| **E_POINTER** |  |

## See also

[IEnumClockVector Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumclockvector)