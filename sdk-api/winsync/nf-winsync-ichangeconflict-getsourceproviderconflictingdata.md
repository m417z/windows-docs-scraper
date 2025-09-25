# IChangeConflict::GetSourceProviderConflictingData

## Description

Gets an object that can be used to retrieve item data for the change item from the source replica.

## Parameters

### `ppConflictingData` [out]

Returns an object that can be used to retrieve item data for the change item from the source replica.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INTERNAL_ERROR** | An internal error has occurred. |
| **Provider-specified error codes.** | The provider cannot load the data for the change. |

## Remarks

The object that is returned in *ppConflictingData* can be an [ISynchronousDataRetriever](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever) object or a provider-specific object.

## See also

[IChangeConflict Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeconflict)

[ISynchronousDataRetriever Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever)