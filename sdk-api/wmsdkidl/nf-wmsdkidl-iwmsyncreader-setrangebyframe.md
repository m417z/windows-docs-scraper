# IWMSyncReader::SetRangeByFrame

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetRangeByFrame** method configures the synchronous reader to read a portion of the file specified by a starting video frame number and a number of frames to read.

## Parameters

### `wStreamNum` [in]

Stream number.

### `qwFrameNumber` [in]

Frame number at which to begin playback. The first frame in a file is number 1.

### `cFramesToRead` [in]

Count of frames to read. Pass 0 to continue playback to the end of the file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *cFramesToRead* contains a negative number. |

## Remarks

If the call is successful, all streams are synchronized to the same position based on the presentation time of the selected frame. Subsequent calls to [GetNextSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getnextsample) will retrieve samples for all active streams, not just the stream specified in the call to **SetRangeByFrame**. If you want to receive only samples for a single video stream by frame, you must call [SetStreamsSelected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setstreamsselected) and pass the desired stream number prior to calling **GetNextSample**.

To use **SetRangeByFrame**, the file in the synchronous reader must be indexed by frame numbers. You can configure the indexer object to index by frame numbers with a call to [IWMIndexer2::Configure](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmindexer2-configure). Then make a call to [IWMIndexer::StartIndexing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmindexer-startindexing) to index the file with the new settings.

When you set a range for compressed sample delivery using a starting frame number, the synchronous reader will deliver samples starting at the first key frame before the specified frame. If you want to identify the presentation time of a frame, use [IWMSyncReader2::SetRangeByFrameEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader2-setrangebyframeex).

Passing a negative number results in an error.

You can call **SetRangeByFrame** at any time after a file has been loaded in the synchronous reader.

## See also

[IWMIndexer Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmindexer)

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)

[IWMSyncReader2::SetRangeByFrameEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader2-setrangebyframeex)

[IWMSyncReader::SetRange](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setrange)