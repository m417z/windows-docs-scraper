# IEnumSyncChangeUnits::Next

## Description

Returns the next change unit.

## Parameters

### `cChanges` [in]

The number of change units to fetch. The only valid value is 1.

### `ppChangeUnit` [out]

Returns the next change unit object.

### `pcFetched` [in, out]

Returns the number of change units that are fetched.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** |  |
| **E_POINTER** |  |

## Remarks

This method currently only supports retrieval of a single change unit. Therefore, *cChanges* must be 1. Otherwise, the call will fail.

## See also

[IEnumSyncChangeUnits Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumsyncchangeunits)