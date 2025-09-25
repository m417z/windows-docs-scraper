# WM_LEAKY_BUCKET_PAIR structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_LEAKY_BUCKET_PAIR** structure describes the buffering requirements for a VBR file. This structure is used with the [ASFLeakyBucketPairs](https://learn.microsoft.com/windows/desktop/wmformat/asfleakybucketpairs) attribute.

## Members

### `dwBitrate`

Bit rate, in bits per second.

### `msBufferWindow`

Size of the buffer window, in milliseconds.

## Remarks

The **ASFLeakyBucketPairs** attribute gives a list of bit rates and corresponding buffer windows. For each bit rate, the **msBufferWindow** member indicates how much content the reader object will buffer before it begins playback. The size of the buffer in bytes equals **msBufferWindow** x **dwBitrate** / 8000.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)