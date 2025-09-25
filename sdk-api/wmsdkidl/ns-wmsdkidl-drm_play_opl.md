# DRM_PLAY_OPL structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM_PLAY_OPL** structure holds information about the output protection levels (OPL) specified in a license for play actions.

## Members

### `minOPL`

[DRM_MINIMUM_OUTPUT_PROTECTION_LEVELS](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_minimum_output_protection_levels) structure containing the minimum OPL required to play content in different formats.

### `oplIdReserved`

Reserved for future use.

### `vopi`

[DRM_VIDEO_OUTPUT_PROTECTION_IDS](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_video_output_protection_ids) structure containing the video output protection identifiers that apply to playback of the content.

## See also

[DRM_COPY_OPL](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_copy_opl)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)