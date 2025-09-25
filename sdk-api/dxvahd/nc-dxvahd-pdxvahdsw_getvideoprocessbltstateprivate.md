# PDXVAHDSW_GetVideoProcessBltStatePrivate callback function

## Description

Gets a private blit state from a software Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Parameters

### `hVideoProcessor` [in]

A handle to the software DXVA-HD video processor.

### `pData` [in, out]

A pointer to a [DXVAHD_BLT_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_private_data) structure. On input, the **Guid** member specifies the private state to query. On output, the structure contains the state information.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_VideoProcessor::GetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-getvideoprocessbltstate)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)