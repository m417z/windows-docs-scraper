# DXVAHD_BLT_STATE_PRIVATE_DATA structure

## Description

Contains data for a private blit state for Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Guid`

A GUID that identifies the private state. The meaning of this value is defined by the device.

### `DataSize`

The size, in bytes, of the buffer pointed to by the **pData** member.

### `pData`

A pointer to a buffer that contains the private state data. The DXVA-HD runtime passes this buffer directly to the device without validation.

## Remarks

Use this structure for proprietary or device-specific state parameters.

The caller allocates the **pData** array. Set the **DataSize** member to the size of the array in bytes. When retrieving the state data, you can set **pData** to **NULL** to get the size of the data. The device will return the size in the **DataSize** member.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)