# DRM_LICENSE_STATE_CATEGORY enumeration (Drmexternals.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_LICENSE\_STATE\_CATEGORY** enumeration type defines the categories for DRM [*license*](https://learn.microsoft.com/windows/win32/wmformat/wmformat-glossary) strings that are displayed to the user.

## Constants

**WM\_DRM\_LICENSE\_STATE\_NORIGHT**

Indicates the string will take the form "Playback not permitted."

**WM\_DRM\_LICENSE\_STATE\_UNLIM**

Indicates the string will take the form "Playback unlimited."

**WM\_DRM\_LICENSE\_STATE\_COUNT**

Indicates the string will take the form "Playback valid 5 times."

**WM\_DRM\_LICENSE\_STATE\_FROM**

Indicates the string will take the form "Playback valid from 7/12/00."

**WM\_DRM\_LICENSE\_STATE\_UNTIL**

Indicates the string will take the form "Playback valid until 7/12/00."

**WM\_DRM\_LICENSE\_STATE\_FROM\_UNTIL**

Indicates the string will take the form "Playback valid from 5/12 to 9/12."

**WM\_DRM\_LICENSE\_STATE\_COUNT\_FROM**

Indicates the string will take the form "Playback valid 5 times from 5/12 to 9/12."

**WM\_DRM\_LICENSE\_STATE\_COUNT\_UNTIL**

Indicates the string will take the form "Playback valid 5 times until 7/12/00."

**WM\_DRM\_LICENSE\_STATE\_COUNT\_FROM\_UNTIL**

Indicates the string will take the form "Playback valid 5 times from 5/12 to 9/12."

**WM\_DRM\_LICENSE\_STATE\_EXPIRATION\_AFTER\_FIRSTUSE**

Indicates the string will take the form "Playback valid for 24 hours from first use."

## Remarks

This enumeration indicates the category for each possible output string to be displayed. It is a member of the [**DRM\_LICENSE\_STATE\_DATA**](https://learn.microsoft.com/windows/win32/wmformat/drm-license-state-data) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Version<br> | Windows Media Format 7 SDK, or later versions of the SDK<br> |
| Header<br> | Drmexternals.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/enumeration-types)

