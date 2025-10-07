# DRM\_OUTPUT\_PROTECTION\_EX structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_OUTPUT\_PROTECTION\_EX** structure holds information about an output protection technology. This structure extends **DRM\_OUTPUT\_PROTECTION** by adding a version number.

## Members

**dwVersion**

Version number.

**guidId**

GUID identifying the output protection technology.

**dwConfigData**

Configuration data for the technology.

## Remarks

**DRM\_AUDIO\_OUTPUT\_PROTECTION\_EX** and **DRM\_VIDEO\_OUTPUT\_PROTECTION\_EX** are both defined as **DRM\_OUTPUT\_PROTECTION** in **typedef** statements.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**DRM\_OUTPUT\_PROTECTION**](https://learn.microsoft.com/windows/win32/wmformat/drm-output-protection)

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

