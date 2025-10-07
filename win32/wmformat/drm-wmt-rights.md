# WMT\_RIGHTS enumeration

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT\_RIGHTS** enumeration type defines the rights that may be specified in a DRM license.

## Constants

**WMT\_RIGHT\_PLAYBACK**

Specifies the right to play content without restriction.

**WMT\_RIGHT\_COPY\_TO\_NON\_SDMI\_DEVICE**

Specifies the right to copy content to a device not compliant with the Secure Digital Music Initiative (SDMI).

**WMT\_RIGHT\_COPY\_TO\_CD**

Specifies the right to copy content to a CD.

**WMT\_RIGHT\_COPY\_TO\_SDMI\_DEVICE**

Specifies the right to copy content to a device compliant with the SDMI.

**WMT\_RIGHT\_ONE\_TIME**

Specifies the right to play content one time only.

**WMT\_RIGHT\_SAVE\_STREAM\_PROTECTED**

Specifies the right to save content from a server.

**WMT\_RIGHT\_COPY**

Specifies the right to copy content. Windows Media DRM 10 regulates the devices to which the content can be copied by using output protection levels (OPLs).

**WMT\_RIGHT\_COLLABORATIVE\_PLAY**

Specifies the right to play content as part of an online scenario where multiple participants can contribute songs from their collection to a shared playlist.

**WMT\_RIGHT\_SDMI\_TRIGGER**

Reserved for future use. Do not use.

**WMT\_RIGHT\_SDMI\_NOMORECOPIES**

Reserved for future use. Do not use.

## Remarks

These values are bit flags, so one or more can be set by combining them with the bitwise **OR** operator.

When using Windows Media DRM 10, **WMT\_RIGHT\_COPY\_TO\_NON\_SDMI\_DEVICE**, **WMT\_RIGHT\_COPY\_TO\_SDMI\_DEVICE**, and **WMT\_RIGHT\_COPY\_TO\_CD** are superseded by **WMT\_RIGHT\_COPY**. Limitations on the devices to which the content may be copied are specified by using output protection levels (OPLs).

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/drm-enumeration-types)

