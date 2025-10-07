# DRM_LICENSE_STATE_CATEGORY enumeration (Wmdrmsdk.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_LICENSE\_STATE\_CATEGORY** enumeration type specifies the type of license restriction that is described by a [**DRM\_LICENSE\_STATE\_DATA**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-license-state-data) structure.

## Constants

**WM\_DRM\_LICENSE\_STATE\_NORIGHT**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is not allowed.

**WM\_DRM\_LICENSE\_STATE\_UNLIM**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed without restriction.

**WM\_DRM\_LICENSE\_STATE\_COUNT**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed, but only a set number of times.

**WM\_DRM\_LICENSE\_STATE\_FROM**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed after a set date.

**WM\_DRM\_LICENSE\_STATE\_UNTIL**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed until a set date.

**WM\_DRM\_LICENSE\_STATE\_FROM\_UNTIL**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed between two set dates.

**WM\_DRM\_LICENSE\_STATE\_COUNT\_FROM**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed, but only a set number of times after a set date.

**WM\_DRM\_LICENSE\_STATE\_COUNT\_UNTIL**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed, but only a set number of times until a set date.

**WM\_DRM\_LICENSE\_STATE\_COUNT\_FROM\_UNTIL**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed, but only a set number of times between two set dates.

**WM\_DRM\_LICENSE\_STATE\_EXPIRATION\_AFTER\_FIRSTUSE**

Specifies that the action for which the **DRM\_LICENSE\_STATE\_DATA** was received is allowed for a set amount of time beginning with the first use of the action.

## Remarks

None.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/drm-enumeration-types)

