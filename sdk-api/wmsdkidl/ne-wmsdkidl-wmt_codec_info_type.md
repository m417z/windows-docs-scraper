# WMT_CODEC_INFO_TYPE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_CODEC_INFO_TYPE** enumeration type defines the broad categories of codecs supported by this SDK.

## Constants

### `WMT_CODECINFO_AUDIO:0`

Audio codec.

### `WMT_CODECINFO_VIDEO:1`

Video codec.

### `WMT_CODECINFO_UNKNOWN:0xffffffff`

Codec of an unknown type.

## Remarks

This type is used when adding or retrieving the codecs used in a file using [IWMHeaderInfo2::GetCodecInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo2-getcodecinfo) and [IWMHeaderInfo3::AddCodecInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-addcodecinfo). When enumerating codecs with the methods of **IWMCodecInfo**, **IWMCodecInfo2**, and **IWMCodecInfo3**, you do not use this type. Those methods use the major media type GUIDs instead.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)