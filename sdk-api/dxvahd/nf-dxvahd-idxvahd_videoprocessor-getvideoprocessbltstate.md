# IDXVAHD_VideoProcessor::GetVideoProcessBltState

## Description

Gets the value of a state parameter for blit operations performed by a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `State` [in]

The state parameter to query, specified as a member of the [DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state) enumeration.

### `DataSize` [in]

The size, in bytes, of the buffer pointed to by *pData*.

### `pData` [out]

A pointer to a buffer allocated by the caller. The method copies the state data into the buffer. The buffer must be large enough to hold the data structure that corresponds to the state parameter. For more information, see [DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_VideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_videoprocessor)