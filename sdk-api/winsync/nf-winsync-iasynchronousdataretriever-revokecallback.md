# IAsynchronousDataRetriever::RevokeCallback

## Description

Indicates that the **IAsynchronousDataRetriever** object must no longer use the specified callback interface and must release any references to it.

## Parameters

### `pDataRetrieverCallback` [in]

The callback interface to release.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes.** |  |

## See also

[IAsynchronousDataRetriever Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iasynchronousdataretriever)