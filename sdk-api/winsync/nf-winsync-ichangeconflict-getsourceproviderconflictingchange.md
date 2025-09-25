# IChangeConflict::GetSourceProviderConflictingChange

## Description

Gets the change metadata from the source provider.

## Parameters

### `ppConflictingChange` [out]

Returns the change metadata from the source provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INTERNAL_ERROR** | The change from the source provider does not exist. |

## See also

[IChangeConflict Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeconflict)