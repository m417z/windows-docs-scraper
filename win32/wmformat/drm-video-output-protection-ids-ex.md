# DRM\_VIDEO\_OUTPUT\_PROTECTION\_IDS\_EX structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_VIDEO\_OUTPUT\_PROTECTION\_IDS\_EX** structure holds an array of **DRM\_VIDEO\_OUTPUT\_PROTECTION** structures.

## Members

**dwVersion**

Version number.

**cEntries**

Number of elements in the array referenced by **rgVop**.

**rgVop**

Address of an array of **DRM\_VIDEO\_OUTPUT\_PROTECTION\_EX** structures. **DRM\_VIDEO\_OUTPUT\_PROTECTION\_EX** is a type defined as [**DRM\_OUTPUT\_PROTECTION\_EX**](https://learn.microsoft.com/windows/win32/wmformat/drm-output-protection-ex).

## Remarks

None.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**DRM\_AUDIO\_OUTPUT\_PROTECTION\_IDS\_EX**](https://learn.microsoft.com/windows/win32/wmformat/drm-audio-output-protection-ids-ex)

[**DRM\_VIDEO\_OUTPUT\_PROTECTION\_IDS**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-video-output-protection-ids)

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

