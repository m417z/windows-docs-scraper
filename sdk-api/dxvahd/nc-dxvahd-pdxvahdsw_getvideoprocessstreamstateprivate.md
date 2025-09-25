# PDXVAHDSW_GetVideoProcessStreamStatePrivate callback function

## Description

Gets a private stream state from a software Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Parameters

### `hVideoProcessor` [in]

A handle to the software DXVA-HD video processor.

### `StreamNumber` [in]

The zero-based index of the input stream.

### `pData` [in, out]

A pointer to a [DXVAHD_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_private_data) structure. On input, the **Guid** member specifies the private state to query. On output, the structure contains the state information.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_VideoProcessor::GetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-getvideoprocessstreamstate)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)