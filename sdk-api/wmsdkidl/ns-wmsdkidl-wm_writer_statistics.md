# WM_WRITER_STATISTICS structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_WRITER_STATISTICS** structure describes the performance of a writing operation.

## Members

### `qwSampleCount`

**QWORD** containing the sample count.

### `qwByteCount`

**QWORD** containing the byte count.

### `qwDroppedSampleCount`

**QWORD** containing the dropped sample count.

### `qwDroppedByteCount`

**QWORD** containing the dropped byte count.

### `dwCurrentBitrate`

**DWORD** containing the current bit rate.

### `dwAverageBitrate`

**DWORD** containing the average bit rate.

### `dwExpectedBitrate`

**DWORD** containing the expected bit rate.

### `dwCurrentSampleRate`

**DWORD** containing the current sample rate.

### `dwAverageSampleRate`

**DWORD** containing the average sample rate.

### `dwExpectedSampleRate`

**DWORD** containing the expected sample rate.

## Remarks

Sample rates are specified in kilohertz. For instance, a sample rate of 8 indicates 8000 samples per second.

## See also

[IWMWriterAdvanced::GetStatistics](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getstatistics)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)