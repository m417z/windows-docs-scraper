# AE_CURRENT_POSITION structure

## Description

Reports the current frame position from the device to the clients.

## Members

### `u64DevicePosition`

The device position, in frames.

### `u64StreamPosition`

The stream position, in frames, used to determine the starting point for audio capture and the render device position relative to the stream.

### `u64PaddingFrames`

The amount of padding, in frames, between the current position and the stream fill point.

### `hnsQPCPosition`

A translated quality performance counter (QPC) timer value taken at the time that the **u64DevicePosition** member was checked.

### `f32FramesPerSecond`

The calculated data rate at the point at the time the position was set.

### `Flag`

A value of the [AE_POSITION_FLAGS](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/ne-audioengineendpoint-ae_position_flags) enumeration that indicates the validity of the position information.

## Remarks

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpointRT::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpointrt-getcurrentpadding)

[IAudioInputEndpointRT::GetInputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioinputendpointrt-getinputdatapointer)

[IAudioOutputEndpointRT::GetOutputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudiooutputendpointrt-getoutputdatapointer)