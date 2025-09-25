# WMT_IMAGE_TYPE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_IMAGE_TYPE** enumeration type defines the types of images that can be used for banner ads. This type is used as the value of the [BannerImageType](https://learn.microsoft.com/windows/desktop/wmformat/bannerimagetype) attribute.

## Constants

### `WMT_IT_NONE:0`

There is no image. If a [BannerImageData](https://learn.microsoft.com/windows/desktop/wmformat/bannerimagedata) attribute in the file, it will be ignored.

### `WMT_IT_BITMAP:1`

The banner image is an uncompressed bitmap.

### `WMT_IT_JPEG:2`

The banner image uses JPEG encoding.

### `WMT_IT_GIF:3`

The banner image uses GIF encoding.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)