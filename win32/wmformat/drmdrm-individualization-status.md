# DRM_INDIVIDUALIZATION_STATUS enumeration (Wmdrmsdk.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_INDIVIDUALIZATION\_STATUS** enumeration type defines the valid states for DRM individualization.

## Constants

**INDI\_UNDEFINED**

This value is reserved for future use.

**INDI\_BEGIN**

Indicates the start of the individualization process.

**INDI\_SUCCEED**

Indicates that the individualization process has been completed.

**INDI\_FAIL**

Indicates that the individualization process failed.

**INDI\_CANCEL**

Indicates that the individualization process was canceled by the application.

**INDI\_DOWNLOAD**

Indicates that the security upgrade is being downloaded.

**INDI\_INSTALL**

Indicates that the security upgrade is being installed.

## Remarks

This enumeration is used by the [**WM\_INDIVIDUALIZE\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drmwm-individualize-status) structure.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/drm-enumeration-types)

