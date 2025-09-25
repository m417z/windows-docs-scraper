# IProviderConverter::Initialize

## Description

When implemented by a derived class, initializes the **IProviderConverter** object with the **ISyncProvider** object to be converted to **IKnowledgeSyncProvider**.

## Parameters

### `pISyncProvider` [in]

The **ISyncProvider** object to be converted.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Converter-determined error codes.** |  |

## See also

[IProviderConverter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iproviderconverter)