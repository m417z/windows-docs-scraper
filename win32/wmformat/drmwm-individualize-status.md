# WM_INDIVIDUALIZE_STATUS structure (Wmdrmsdk.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM\_INDIVIDUALIZE\_STATUS** structure holds information about a pending individualization process.

## Members

**hr**

**HRESULT** return code.

**enIndiStatus**

Value from the [**DRM\_INDIVIDUALIZATION\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-individualization-status) enumeration type that indicates the current status of the individualization process.

**pszIndiRespUrl**

Pointer to a null-terminated string containing the individualization response URL.

**dwHTTPRequest**

The number of HTTP round trips to the individualization service that have been completed.

**enHTTPStatus**

Value from the [**DRM\_HTTP\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-http-status) enumeration type.

**dwHTTPReadProgress**

The number of bytes downloaded.

**dwHTTPReadTotal**

The total number of bytes to be downloaded. You can use this value and **dwHTTPReadProgress** to display a user interface indicating how much of the download has completed and how much remains to be done.

## Remarks

This structure is received when you call the [**IWMDRMIndividualizationStatus::GetStatus**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmindividualizationstatus-getstatus) method. It contains the status of the pending individualization process at the time of the call.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

