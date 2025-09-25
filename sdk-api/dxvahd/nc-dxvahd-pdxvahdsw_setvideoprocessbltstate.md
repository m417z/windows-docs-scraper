# PDXVAHDSW_SetVideoProcessBltState callback function

## Description

Sets a state parameter for blit operations by a software Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Parameters

### `hVideoProcessor` [in]

A handle to the software DXVA-HD video processor.

### `State` [in]

The state parameter to set, specified as a member of the [DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state) enumeration.

### `DataSize` [in]

The size of the buffer pointed to by *pData*, in bytes.

### `pData` [in]

A pointer to a buffer that contains the state data.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)