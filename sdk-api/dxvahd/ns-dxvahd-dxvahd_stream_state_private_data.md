# DXVAHD_STREAM_STATE_PRIVATE_DATA structure

## Description

Contains data for a private stream state, for a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) input stream.

## Members

### `Guid`

A GUID that identifies the private stream state. The following GUID is defined.

| Value | Meaning |
| --- | --- |
| **DXVAHD_STREAM_STATE_PRIVATE_IVTC** | Retrieves statistics about inverse telecine. The state data (**pData**) is a [DXVAHD_STREAM_STATE_PRIVATE_IVTC_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_stream_state_private_ivtc_data) structure. |

A device can define additional GUIDs for use with custom stream states. The interpretation of the data is then defined by the device.

### `DataSize`

The size, in bytes, of the buffer pointed to by the **pData** member.

### `pData`

A pointer to a buffer that contains the private state data. The DXVA-HD runtime passes this buffer directly to the device, without validation.

## Remarks

Use this structure for proprietary or device-specific state parameters.

The caller allocates the **pData** array. Set the **DataSize** member to the size of the array in bytes. When retrieving the state data, you can set the **pData** member to **NULL** to get the size of the data. The device will return the size in the **DataSize** member.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)