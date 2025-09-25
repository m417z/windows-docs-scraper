# WMT_WEBSTREAM_FORMAT structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_WEBSTREAM_FORMAT** structure contains information about a Web stream. This structure is used as the **pbFormat** member of the [WM_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_media_type) structure for Web streams.

## Members

### `cbSize`

**WORD** containing the size of the structure, in bytes.

### `cbSampleHeaderFixedData`

**WORD** containing the size of Web stream sample header, in bytes.

### `wVersion`

**WORD** containing the version number. Set to 1 for streams created with the Windows Media Format 9 Series SDK.

### `wReserved`

**WORD**. Reserved.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)