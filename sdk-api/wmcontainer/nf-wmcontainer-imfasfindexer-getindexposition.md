# IMFASFIndexer::GetIndexPosition

## Description

Retrieves the offset of the index object from the start of the content.

## Parameters

### `pIContentInfo` [in]

Pointer to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface of the ContentInfo object that describes the content.

### `pcbIndexOffset` [out]

Receives the offset of the index relative to the beginning of the content described by the ContentInfo object. This is the position relative to the beginning of the ASF file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pIContentInfo* is **NULL** or *pcbIndexOffset* is **NULL** |

## Remarks

The index continues from the offset retrieved by this method to the end of the file.

You must call [IMFASFIndexer::Initialize](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-initialize) to set up the indexer before calling this method.

If the index is retrieved by using more than one call to [IMFASFIndexer::GetCompletedIndex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getcompletedindex), the position of individual index portions is equal to the index offset plus the offset of the portion within the index.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)