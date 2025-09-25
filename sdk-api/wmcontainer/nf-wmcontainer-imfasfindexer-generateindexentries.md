# IMFASFIndexer::GenerateIndexEntries

## Description

Accepts an ASF packet for the file and creates index entries for them.

## Parameters

### `pIASFPacketSample` [in]

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of a media sample that contains the ASF packet.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The argument passed in is **NULL**. |
| **MF_E_NOT_INITIALIZED** | The indexer is not initialized. |

## Remarks

The ASF indexer creates indexes for a file internally. You can get the completed index for all data packets sent to the indexer by committing the index with [IMFASFIndexer::CommitIndex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-commitindex) and then calling [IMFASFIndexer::GetCompletedIndex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getcompletedindex) to write the index entries into a media buffer. To determine the size of the index so you can allocate a buffer large enough to hold the index, call [IMFASFIndexer::GetIndexWriteSpace](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getindexwritespace).

When this method creates index entries, they are immediately available for use by [IMFASFIndexer::GetSeekPositionForValue](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getseekpositionforvalue).

The media sample specified in *pIASFPacketSample* must hold a buffer that contains a single ASF packet. Get the sample from the ASF multiplexer by calling the [IMFASFMultiplexer::GetNextPacket](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-getnextpacket) method.

You cannot use this method while reading an index, only when writing an index.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)