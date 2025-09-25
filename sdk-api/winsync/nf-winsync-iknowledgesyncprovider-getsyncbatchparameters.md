# IKnowledgeSyncProvider::GetSyncBatchParameters

## Description

Gets the requested number of item changes that will be included in change batches, and the current knowledge for the synchronization scope.

## Parameters

### `ppSyncKnowledge` [out]

Returns the current knowledge for the synchronization scope, or a newly created knowledge object if no current knowledge exists.

### `pdwRequestedBatchSize` [out]

Returns the requested number of item changes that will be included in change batches returned by the source provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes** |  |

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)