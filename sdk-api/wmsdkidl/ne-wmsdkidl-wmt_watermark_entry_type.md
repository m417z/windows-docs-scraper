# WMT_WATERMARK_ENTRY_TYPE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_WATERMARK_ENTRY_TYPE** enumeration type identifies the types of watermarking systems. Each watermarking system is a DirectX media object (DMO) that embeds some sort of digital watermark in digital media content.

## Constants

### `WMT_WMETYPE_AUDIO:1`

Identifies a watermarking DMO for audio.

### `WMT_WMETYPE_VIDEO:2`

Identifies a watermarking DMO for video.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)

[Watermarking Support](https://learn.microsoft.com/windows/desktop/wmformat/watermarking-support)