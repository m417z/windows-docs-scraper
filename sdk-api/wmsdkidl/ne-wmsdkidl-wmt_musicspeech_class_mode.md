# WMT_MUSICSPEECH_CLASS_MODE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_MUSICSPEECH_CLASS_MODE** enumeration type defines the types of compression supported by the Windows Media Audio 9 Voice codec.

## Constants

### `WMT_MS_CLASS_MUSIC:0`

Not currently supported. Do not use.

### `WMT_MS_CLASS_SPEECH:1`

Compression optimized for speech.

### `WMT_MS_CLASS_MIXED:2`

Compression optimized for a mixture of music and speech.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)