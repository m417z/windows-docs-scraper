# IMFASFIndexer::GetFlags

## Description

Retrieves the flags that indicate the selected indexer options.

## Parameters

### `pdwFlags` [out]

Receives a bitwise OR of zero or more flags from the [MFASF_INDEXER_FLAGS](https://learn.microsoft.com/windows/win32/api/wmcontainer/ne-wmcontainer-mfasf_indexer_flags) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pdwFlags* is **NULL**. |

## Remarks

You must call this method before initializing the indexer object with [IMFASFIndexer::Initialize](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-initialize).

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)