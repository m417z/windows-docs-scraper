# WM_WRITER_STATISTICS_EX structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_WRITER_STATISTICS_EX** structure is used by [IWMWriterAdvanced3::GetStatisticsEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced3-getstatisticsex) to obtain extended writer statistics.

## Members

### `dwBitratePlusOverhead`

**DWORD** containing the bit rate plus any overhead.

### `dwCurrentSampleDropRateInQueue`

**DWORD** containing the current rate at which samples are dropped in the queue in order to reduce demands on the CPU.

### `dwCurrentSampleDropRateInCodec`

**DWORD** containing the current rate at which samples are dropped in the codec. Samples can be dropped when they contain little new data. To prevent this from happening, call [IWMWriterAdvanced2::SetInputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced2-setinputsetting) to set the g_wszFixedFrameRate setting to **TRUE**.

### `dwCurrentSampleDropRateInMultiplexer`

**DWORD** containing the current rate at which samples are dropped in the multiplexer because they arrived late or overflowed the buffer window.

### `dwTotalSampleDropsInQueue`

**DWORD** containing the total number of samples dropped in the queue.

### `dwTotalSampleDropsInCodec`

**DWORD** containing the total number of samples dropped in the codec.

### `dwTotalSampleDropsInMultiplexer`

**DWORD** containing the total number of samples dropped in the multiplexer.

## Remarks

Sample rates are given in kilohertz.

Basic writer statistics are contained within a [WM_WRITER_STATISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_writer_statistics) structure and must be obtained by calling [IWMWriterAdvanced::GetStatistics](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getstatistics).

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)