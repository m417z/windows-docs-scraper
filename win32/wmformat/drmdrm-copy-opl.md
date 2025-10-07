# DRM\_COPY\_OPL structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_COPY\_OPL** structure holds information about the output protection levels (OPLs) specified in a license for copy actions.

## Members

**wMinimumCopyLevel**

Minimum OPL for copy actions.

**oplIdIncludes**

[**DRM\_OPL\_OUTPUT\_IDS**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-opl-output-ids) structure containing the identifiers of technologies to allow. This member is used for output technologies that are assigned OPLs lower than the minimum copy level, but to which the content may be copied.

**oplIdExcludes**

[**DRM\_OPL\_OUTPUT\_IDS**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-opl-output-ids) structure containing the output identifiers of technologies to restrict. This member is used for output technologies that are assigned OPLs that exceed the minimum copy level, but that the license issuer does not grant rights for copying to.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**DRM\_PLAY\_OPL**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-play-opl)

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

