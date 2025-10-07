# DRM\_ATTR\_DATATYPE enumeration

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_ATTR\_DATATYPE** enumeration defines the data types used for DRM attributes and properties.

## Constants

**DRM\_TYPE\_DWORD**

The property is a 4-byte **DWORD** value.

**DRM\_TYPE\_STRING**

The property is a null-terminated Unicode string.

**DRM\_TYPE\_BINARY**

The property is an array of bytes.

**DRM\_TYPE\_BOOL**

The property is a 4-byte Boolean value.

**DRM\_TYPE\_QWORD**

The property is an 8-byte **QWORD** value.

**DRM\_TYPE\_WORD**

The property is a 2-byte **WORD** value.

**DRM\_TYPE\_GUID**

The property is a 128-bit (6-byte) GUID value.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/drm-enumeration-types)

