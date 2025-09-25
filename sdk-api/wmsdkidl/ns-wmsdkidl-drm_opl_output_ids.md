# DRM_OPL_OUTPUT_IDS structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM_OPL_OUTPUT_IDS** structure holds a number of output protection level (OPL) output identifiers.

## Members

### `cIds`

Number of identifiers in the array referenced by **rgIds**.

### `rgIds`

Address of an array of GUIDs. Each member of the array contains an OPL output identifier.

## Remarks

This structure is used as a member of the [DRM_COPY_OPL](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_copy_opl) and [DRM_PLAY_OPL](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_play_opl) structures to identify groups of output identifiers.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)