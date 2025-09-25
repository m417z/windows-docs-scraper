# WMT_RIGHTS enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_RIGHTS** enumeration type defines the rights that may be specified in a DRM license.

## Constants

### `WMT_RIGHT_PLAYBACK:0x1`

Specifies the right to play content without restriction.

### `WMT_RIGHT_COPY_TO_NON_SDMI_DEVICE:0x2`

Specifies the right to copy content to a device not compliant with the [Secure Digital Music Initiative (SDMI)](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary).

### `WMT_RIGHT_COPY_TO_CD:0x8`

Specifies the right to copy content to a CD.

### `WMT_RIGHT_COPY_TO_SDMI_DEVICE:0x10`

Specifies the right to copy content to a device compliant with the Secure Digital Music Initiative (SDMI).

### `WMT_RIGHT_ONE_TIME:0x20`

Specifies the right to play content one time only.

### `WMT_RIGHT_SAVE_STREAM_PROTECTED:0x40`

Specifies the right to save content from a server.

### `WMT_RIGHT_COPY:0x80`

Specifies the right to copy content. Windows Media DRM 10 regulates the devices to which the content can be copied by using output protection levels (OPLs).

### `WMT_RIGHT_COLLABORATIVE_PLAY:0x100`

Specifies the right to play content as part of an online scenario where multiple participants can contribute songs from their collection to a shared playlist.

### `WMT_RIGHT_SDMI_TRIGGER:0x10000`

Reserved for future use. Do not use.

### `WMT_RIGHT_SDMI_NOMORECOPIES:0x20000`

Reserved for future use. Do not use.

## Remarks

These values are bit flags, so one or more can be set by combining them with the bitwise **OR** operator.

When using Windows Media DRM 10, **WMT_RIGHT_COPY_TO_NON_SDMI_DEVICE**, **WMT_RIGHT_COPY_TO_SDMI_DEVICE**, and **WMT_RIGHT_COPY_TO_CD** are superseded by **WMT_RIGHT_COPY**. Limitations on the devices to which the content may be copied are specified by using output protection levels (OPLs).

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd757720(v=vs.85))