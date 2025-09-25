# IWMSyncReader2::SetRangeByTimecode

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetRangeByTimecode** method sets a starting and ending time, based on SMPTE time codes, for playback of a file.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `pStart` [in]

Pointer to a [WMT_TIMECODE_EXTENSION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_timecode_extension_data) structure containing the starting time code.

### `pEnd` [in]

Pointer to a **WMT_TIMECODE_EXTENSION_DATA** structure containing the ending time code.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

For the method to succeed, the file must be indexed by SMPTE time code.

If the call is successful, all streams are synchronized to the same position based on presentation time.

## See also

[IWMSyncReader2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader2)