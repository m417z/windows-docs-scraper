# WM_INDIVIDUALIZE_STATUS structure (Drmexternals.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM\_INDIVIDUALIZE\_STATUS** structure records the status of the [*individualization*](https://learn.microsoft.com/windows/win32/wmformat/wmformat-glossary) process.

## Members

**hr**

**HRESULT** return code.

**enIndiStatus**

Value from the [**DRM\_INDIVIDUALIZATION\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drm-individualization-status) enumeration type.

**pszIndiRespUrl**

Pointer to a null-terminated string containing the individualization response URL.

**dwHTTPRequest**

**DWORD** that indicates the number of HTTP round trips to the individualization service that have been completed..

**enHTTPStatus**

Value from the [**DRM\_HTTP\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drm-http-status) enumeration type.

**dwHTTPReadProgress**

**DWORD** containing the number of bytes downloaded until now..

**dwHTTPReadTotal**

**DWORD** containing the total number of bytes to be downloaded. Use this value and **dwHTTPReadProgress** to display a user interface indicating how much of the download has completed and how much remains to be done.

## Remarks

This structure is filled in by the DRM run-time components and is sent to applications in the *pValue* parameter of the applications [**IWMStatusCallback::OnStatus**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method when the event equals WMT\_INDIVIDUALIZE. The application receives this event multiple times during the download process.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Version<br> | Windows Media Format 7 SDK, or later versions of the SDK<br> |
| Header<br> | Drmexternals.h |

## See also

[**DRM\_HTTP\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drm-http-status)

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/structures)

