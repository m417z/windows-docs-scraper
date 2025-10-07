# DRM_INDIVIDUALIZATION_STATUS enumeration (Drmexternals.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_INDIVIDUALIZATION\_STATUS** enumeration type defines the valid states for DRM [*individualization*](https://learn.microsoft.com/windows/win32/wmformat/wmformat-glossary). When an application initiates individualization with a call to [**IWMDRMReader::Individualize**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmdrmreader-individualize), the progress of the individualization request is conveyed to the application through calls to the [**IWMStatusCallback::OnStatus**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method. Individualization status messages will all use the WMT\_INDIVIDUALIZE member of the [**WMT\_STATUS**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Wmsdkidl/ne-wmsdkidl-wmt_status) enumeration type as the *Status* parameter. The status of the individualization is passed to **OnStatus** in the *pValue* parameter.

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

Indicates that the individualization process was canceled as the result of a call to [**IWMDRMReader::CancelIndividualization**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmdrmreader-cancelindividualization).

**INDI\_DOWNLOAD**

Indicates that the security upgrade is being downloaded.

**INDI\_INSTALL**

Indicates that the security upgrade is being installed.

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

[**DRM\_HTTP\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drm-http-status)

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/enumeration-types)

