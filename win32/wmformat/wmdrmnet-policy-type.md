# WMDRMNET\_POLICY\_TYPE enumeration

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRMNET\_POLICY\_TYPE** enumeration type lists the types of policies that are available for Windows Media DRM for Network Devices operations.

## Constants

**WMDRMNET\_POLICY\_TYPE\_UNDEFINED**

Undefined policy types are not supported.

**WMDRMNET\_POLICY\_TYPE\_TRANSCRYPTPLAY**

The policy governs the ability to convert content protected by Windows Media DRM into protected Windows Media DRM for Network Devices data and play it back on a networked device.

## Remarks

None.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/drm-enumeration-types)

[**WMDRMNET\_POLICY**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy)

