# IWMSyncReader2::SetRangeByFrameEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetRangeByFrameEx** method configures the synchronous reader to read a portion of the file specified by a starting video frame number and a number of frames to read. This method also retrieves the presentation time of the requested frame number.

## Parameters

### `wStreamNum` [in]

Stream number.

### `qwFrameNumber` [in]

Frame number at which to begin playback. The first frame in a file is number 1.

### `cFramesToRead` [in]

Count of frames to read. Pass 0 to continue playback to the end of the file.

### `pcnsStartTime` [out]

Start time in 100-nanosecond units.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

By getting the presentation time of the requested frame number, you can avoid problems caused by seeking to a delta frame. The synchronous reader begins delivering samples at key frame boundaries. You can ignore frames until you reach the presentation time of your target frame.

The file must be frame-indexed. If the call is successful, all streams are synchronized to the same position based on time.

## See also

[IWMSyncReader2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader2)

[IWMSyncReader::SetRangeByFrame](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setrangebyframe)