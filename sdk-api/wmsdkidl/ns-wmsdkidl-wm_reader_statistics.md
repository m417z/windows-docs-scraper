# WM_READER_STATISTICS structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_READER_STATISTICS** structure describes the performance of a reading operation.

## Members

### `cbSize`

The size of the **WM_READER_STATISTICS** structure, in bytes.

### `dwBandwidth`

**DWORD** containing the bandwidth, in bits per second.

### `cPacketsReceived`

Count of packets received.

### `cPacketsRecovered`

Count of lost packets which were recovered. This value is only relevant during network playback.

### `cPacketsLost`

Count of lost packets which were not recovered. This value is only relevant during network playback.

### `wQuality`

**WORD** containing the quality, which is the percentage of total packets that were received.

## Remarks

You must set the **cbSize** member manually before using this structure. It should always be set to sizeof(**WM_READER_STATISTICS**).

## See also

[IWMReaderAdvanced::GetStatistics](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getstatistics)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)