# IDataRetrieverCallback::LoadChangeDataComplete

## Description

Indicates that [IAsynchronousDataRetriever::LoadChangeData](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iasynchronousdataretriever-loadchangedata) has finished successfully.

## Parameters

### `pUnkData` [in]

An object that can be used to access the data that was loaded by **LoadChangeData**.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IDataRetrieverCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-idataretrievercallback)