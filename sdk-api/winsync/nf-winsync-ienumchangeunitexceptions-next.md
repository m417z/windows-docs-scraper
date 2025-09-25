# IEnumChangeUnitExceptions::Next

## Description

Returns the next elements in the change unit exception set, if they are available.

## Parameters

### `cExceptions` [in]

The number of change unit exceptions to retrieve in the range of zero to 1000.

### `ppChangeUnitException` [out]

Returns the next *pcFetched* change unit exceptions.

### `pcFetched` [in, out]

Returns the number of change unit exceptions that are retrieved. This value can be **NULL** only if *cExceptions* is 1.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | If there are no more change unit exceptions to retrieve. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## See also

[IEnumChangeUnitExceptions Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumchangeunitexceptions)