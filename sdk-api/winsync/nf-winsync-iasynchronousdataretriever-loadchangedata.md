# IAsynchronousDataRetriever::LoadChangeData

## Description

Retrieves item data for a change.

## Parameters

### `pLoadChangeContext` [in]

Metadata that describes the change for which data should be retrieved.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes.** | See Remarks. |

## Remarks

When **LoadChangeData** is called, the provider must take one of the following actions:

* Return a success code from the method and later call [IDataRetrieverCallback::LoadChangeDataComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-idataretrievercallback-loadchangedatacomplete) to report that asynchronous processing finished successfully.
* Return a success code from the method and later call [IDataRetrieverCallback::LoadChangeDataError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-idataretrievercallback-loadchangedataerror) to report that an error occurred during asynchronous processing.
* Return an error code from the method. In this case, [IDataRetrieverCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-idataretrievercallback) methods should not be called.

## See also

[IAsynchronousDataRetriever Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iasynchronousdataretriever)

[IDataRetrieverCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-idataretrievercallback)