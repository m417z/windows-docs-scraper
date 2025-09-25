# DXVAHD_STREAM_STATE_PRIVATE_IVTC_DATA structure

## Description

Contains inverse telecine (IVTC) statistics from a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Members

### `Enable`

Specifies whether IVTC statistics are enabled. The default state value is **FALSE**. Setting the value to **TRUE** enables IVTC statistics, and resets all of the IVTC statistical data to zero.

### `ITelecineFlags`

If the driver detects that the frames are telecined, and is able to perform inverse telecine, this field contains a member of the [DXVAHD_ITELECINE_CAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_itelecine_caps) enumeration. Otherwise, the value is 0.

### `Frames`

The number of consecutive telecined frames that the device has detected.

### `InputField`

The index of the most recent input field. The value of this member equals the most recent value of the **InputFrameOrField** member of the [DXVAHD_STREAM_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_data) structure.

## Remarks

If the DXVA-HD device supports IVTC statistics, it can detect when the input video contains telecined frames. You can use this information to enable IVTC in the device.

To enable IVTC statistics, do the following:

1. Allocate a **DXVAHD_STREAM_STATE_PRIVATE_IVTC_DATA** structure and set the **Enable** member to **TRUE**.
2. Initialize a [DXVAHD_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_private_data) structure with these values:
   * Set **Guid** to **DXVAHD_STREAM_STATE_PRIVATE_IVTC**.
   * Set **DataSize** to `sizeof(DXVAHD_STREAM_STATE_PRIVATE_IVTC_DATA)`.
   * Set **pData** to point to the **DXVAHD_STREAM_STATE_PRIVATE_IVTC_DATA** structure.
3. Call the [IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate) method. Set the *State* parameter of that method to **DXVAHD_STREAM_STATE_PRIVATE** and the *pData* parameter to the address of the [DXVAHD_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_private_data) structure.

To get the most recent IVTC statistics from the device, call the [IDXVAHD_VideoProcessor::GetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-getvideoprocessstreamstate) method. The state parameter and data buffer are the same.

Typically, an application would use this feature as follows:

1. Enable IVTC statistics.
2. Begin sending interlaced video frames to the DXVA-HD device.
3. At some point, query the device for the current IVTC statistics.
4. If the device detects telecined frames, use a custom frame rate to perform IVTC. For more information, see [DXVAHD_CUSTOM_RATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_custom_rate_data).

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)