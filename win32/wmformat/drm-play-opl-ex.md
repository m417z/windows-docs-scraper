# DRM\_PLAY\_OPL\_EX structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_PLAY\_OPL\_EX** structure holds information about the output protection levels (OPLs) specified in a license for play actions.

## Members

**dwVersion**

Version number.

**minOPL**

[**DRM\_MINIMUM\_OUTPUT\_PROTECTION\_LEVELS**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-minimum-output-protection-levels) structure containing the minimum OPL required to play content in different formats.

**oplIdReserved**

Reserved for future use.

**vopi**

[**DRM\_VIDEO\_OUTPUT\_PROTECTION\_IDS**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-video-output-protection-ids) structure containing the video output protection identifiers that apply to playback of the content.

## Remarks

This structure is identical to the **DRM\_PLAY\_OPL** structure, except that it includes a version number.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**DRM\_PLAY\_OPL**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-play-opl)

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

