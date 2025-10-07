# DRM_HTTP_STATUS enumeration (Drmexternals.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_HTTP\_STATUS** enumeration type defines a range of states for a [*DRM*](https://learn.microsoft.com/windows/win32/wmformat/wmformat-glossary) request.

## Constants

**HTTP\_NOTINITIATED**

The HTTP operations have not been initiated.

**HTTP\_CONNECTING**

The connection is being established.

**HTTP\_REQUESTING**

Data is being requested.

**HTTP\_RECEIVING**

Data is being received.

**HTTP\_COMPLETED**

The HTTP operations are complete.

## Remarks

This enumeration is used by the [**WM\_INDIVIDUALIZE\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/wm-individualize-status) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Version<br> | Windows Media Format 7 SDK, or later versions of the SDK<br> |
| Header<br> | Drmexternals.h |

## See also

[**DRM\_INDIVIDUALIZATION\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drm-individualization-status)

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/enumeration-types)

