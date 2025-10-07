# WMDRMNET\_POLICY\_TRANSCRYPTPLAY structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRMNET\_POLICY\_TRANSCRYPTPLAY** structure holds the policy information for playing content using Windows Media DRM for Network Devices.

## Members

**globals**

Global policy structure.

**playOPLs**

Output protection levels for playback. **WMDRMNET\_POLICY\_PLAY\_OPL** is a type defined as [**DRM\_PLAY\_OPL\_EX**](https://learn.microsoft.com/windows/win32/wmformat/drm-play-opl-ex).

## Remarks

None.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

[**WMDRMNET\_POLICY**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy)

