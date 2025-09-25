# PDXVAHDSW_SetVideoProcessStreamState callback function

## Description

Sets a state parameter for an input stream on a software Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Parameters

### `hVideoProcessor` [in]

A handle to the software DXVA-HD video processor.

### `StreamNumber` [in]

The zero-based index of the input stream.

### `State` [in]

The state parameter to set, specified as a member of the [DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state) enumeration.

### `DataSize` [in]

The size of the buffer pointed to by *pData*, in bytes.

### `pData` [in]

A pointer to a buffer that contains the state data.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)