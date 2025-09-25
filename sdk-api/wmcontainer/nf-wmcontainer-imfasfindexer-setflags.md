# IMFASFIndexer::SetFlags

## Description

Sets indexer options.

## Parameters

### `dwFlags` [in]

Bitwise OR of zero or more flags from the [MFASF_INDEXER_FLAGS](https://learn.microsoft.com/windows/win32/api/wmcontainer/ne-wmcontainer-mfasf_indexer_flags) enumeration specifying the indexer options to use.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The indexer object was initialized before setting flags for it. For more information, see Remarks. |

## Remarks

**IMFASFIndexer::SetFlags** must be called before [IMFASFIndexer::Initialize](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-initialize). Attempting to call **SetFlags** after **Initialize** will return MF_E_INVALIDREQUEST as a result.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)