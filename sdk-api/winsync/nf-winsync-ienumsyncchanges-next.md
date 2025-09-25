# IEnumSyncChanges::Next

## Description

Returns the next item change.

## Parameters

### `cChanges` [in]

The number of changes to fetch. The only valid value is 1.

### `ppChange` [out]

Returns the next item change.

### `pcFetched` [in, out]

Returns the number of changes that are fetched.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** |  |
| **E_POINTER** |  |

## See also

[IEnumSyncChanges Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumsyncchanges)