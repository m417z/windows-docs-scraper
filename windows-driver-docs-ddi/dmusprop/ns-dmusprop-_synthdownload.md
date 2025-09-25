# _SYNTHDOWNLOAD structure

## Description

The SYNTHDOWNLOAD structure specifies a handle for downloaded DLS data. It also specifies whether the buffer containing the DLS data can be freed.

## Members

### `DownloadHandle`

Handle to the downloaded DLS data buffer, which the miniport driver generates to uniquely identify the DLS data so that it can be unloaded later.

### `Free`

Specifies whether the client can free the data buffer as soon as the DLS download completes. If **TRUE**, the client can free the buffer when the download completes. If **FALSE**, the client must not free the buffer until it is unloaded. For more information, see the following Remarks section.

## Remarks

When processing a [KSPROPERTY_SYNTH_DLS_DOWNLOAD](https://learn.microsoft.com/previous-versions/ff537396(v=vs.85)) get-property request, the synthesizer miniport driver uses the SYNTHDOWNLOAD structure to pass a handle back to the client. This handle uniquely identifies the downloaded DLS data. The client later specifies this same handle in [KSPROPERTY_SYNTH_DLS_UNLOAD](https://learn.microsoft.com/previous-versions/ff537398(v=vs.85)) set-property request that unloads the DLS data.

If the miniport driver makes its own copy of the DLS data, it sets the *Free* parameter to **TRUE** to indicate that the client can free the buffer containing the DLS data as soon as the KSPROPERTY_SYNTH_DLS_DOWNLOAD property request completes. If the miniport driver continues to use the client's copy of the DLS data, however, it sets *Free* to **FALSE** to indicate that the client should maintain its allocation of the original DLS data buffer until it unloads the data by sending a KSPROPERTY_SYNTH_DLS_UNLOAD property request.

## See also

[KSPROPERTY_SYNTH_DLS_DOWNLOAD](https://learn.microsoft.com/previous-versions/ff537396(v=vs.85))

[KSPROPERTY_SYNTH_DLS_UNLOAD](https://learn.microsoft.com/previous-versions/ff537398(v=vs.85))