# WMT_VERSION enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_VERSION** enumeration type defines the versions of the Windows Media Format SDK. Every profile you create will have an associated version identified by one of these enumerations. The version associated with a profile dictates the types of data allowed. For example, data unit extensions were introduced with version 8. A profile defined as version 7 cannot include data unit extensions. Under most circumstances, you will create profiles for the most current version.

## Constants

### `WMT_VER_4_0:0x40000`

Compatible with version 4 of the Windows Media Format SDK.

### `WMT_VER_7_0:0x70000`

Compatible with the Windows Media Format 7 SDK.

### `WMT_VER_8_0:0x80000`

Compatible with the Windows Media Format 8.2 SDK.

### `WMT_VER_9_0:0x90000`

Compatible with the Windows Media Format 9 Series SDK, and with the Windows Media Format 9.5 SDK.

## Remarks

The version assigned to a profile does not directly relate to the codecs used in the profile's individual streams. However, it is recommended that you use codecs of the same version as the profile. Unless you have specific requirements to the contrary, you should always use the latest version.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)