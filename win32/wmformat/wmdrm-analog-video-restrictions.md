# WMDRM\_ANALOG\_VIDEO\_RESTRICTIONS structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM\_ANALOG\_VIDEO\_RESTRICTIONS** structure holds information about a restriction for playing back content as analog video.

## Members

**guidRestrictionID**

Restriction identifier.

**dwRestrictionData**

Restriction data.

## Remarks

This structure is received when you call [**IWMDRMLicense::GetAnalogVideoRestrictionLevels**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmlicense-getanalogvideorestrictionlevels).

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

[**WMDRM\_ANALOG\_VIDEO\_RESTRICTIONS\_EX**](https://learn.microsoft.com/windows/win32/wmformat/wmdrm-analog-video-restrictions-ex)

