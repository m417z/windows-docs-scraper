# WMDRMNET\_POLICY\_MINIMUM\_ENVIRONMENT structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRMNET\_POLICY\_MINIMUM\_ENVIRONMENT** structure contains the minimum security requirements for Windows Media DRM for Network Devices.

## Members

**wMinimumSecurityLevel**

Minimum application security level required.

**dwMinimumAppRevocationListVersion**

Minimum application certificate revocation list version required.

**dwMinimumDeviceRevocationListVersion**

Minimum device certificate revocation list required.

## Remarks

None.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

[**WMDRMNET\_POLICY**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy)

