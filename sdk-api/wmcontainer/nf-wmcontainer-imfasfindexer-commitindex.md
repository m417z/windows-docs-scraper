# IMFASFIndexer::CommitIndex

## Description

Adds information about a new index to the ContentInfo object associated with ASF content. You must call this method before copying the index to the content so that the index will be readable by the indexer later.

## Parameters

### `pIContentInfo` [in]

Pointer to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface of the ContentInfo object that describes the content.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The caller made an invalid request. For more information, see Remarks. |

## Remarks

For the index to function properly, you must call this method after all ASF packets in the file have been passed to the indexer by using the [IMFASFIndexer::GenerateIndexEntries](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-generateindexentries) method. After you call this method, you must retrieve the indexes by calling [GetCompletedIndex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getcompletedindex) and write them to the appropriate location in the file. Finally, you must generate a new ASF header by calling the [IMFASFContentInfo::GenerateHeader](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-generateheader) method of the ASF ContentInfo object.

 An application must use the **CommitIndex** method only when writing a new index otherwise **CommitIndex** may return MF_E_INVALIDREQUEST as a result. For example, MF_E_INVALIDREQUEST is returned if the application has flags other than MFASF_INDEXER_WRITE_NEW_INDEX set on the indexer object. **CommitIndex** can also return MFASF_INDEXER_WRITE_NEW_INDEX if the index entries have already been committed through an earlier **CommitIndex** call.

You cannot use this method in an index reading scenario. You can only use this method when writing indexes.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)

[MFCreateASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-mfcreateasfindexer)