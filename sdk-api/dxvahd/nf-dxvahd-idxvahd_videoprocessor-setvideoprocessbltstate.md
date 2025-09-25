# IDXVAHD_VideoProcessor::SetVideoProcessBltState

## Description

Sets a state parameter for a blit operation by a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `State` [in]

The state parameter to set, specified as a member of the [DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state) enumeration.

### `DataSize` [in]

The size, in bytes, of the buffer pointed to by *pData*.

### `pData` [in]

A pointer to a buffer that contains the state data. The meaning of the data depends on the *State* parameter. Each state has a corresponding data structure; for more information, see [DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state). The caller allocates the buffer and fills in the parameter data before calling this method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_VideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_videoprocessor)