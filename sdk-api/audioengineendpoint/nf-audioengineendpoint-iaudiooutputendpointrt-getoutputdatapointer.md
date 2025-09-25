# IAudioOutputEndpointRT::GetOutputDataPointer

## Description

The **GetOutputDataPointer** method returns a pointer to the output buffer in which data will be written by the audio engine.

## Parameters

### `u32FrameCount` [in]

The number of frames in the output buffer pointed to by the data pointer that is returned by this method. The endpoint must not
cache this information because this can be changed by the audio engine depending on its processing requirements. For more information, see Remarks.

### `pAeTimeStamp` [in]

A pointer to an [AE_CURRENT_POSITION](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/ns-audioengineendpoint-ae_current_position) structure that specifies the time stamp of the data that is rendered. This parameter is optional.

## Return value

A pointer to the buffer to which data will be written.

## Remarks

This method returns a pointer to a buffer in which the audio engine writes data.
The data is not valid until the [IAudioOutputEndpointRT::ReleaseOutputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudiooutputendpointrt-releaseoutputdatapointer) method is called.
The returned pointer must be frame-aligned.

The frame count passed in **u32FrameCount** must be less than or equal to the maximum number of frames supported by the endpoint. To get the maximum frame count that the endpoint can support, the audio engine calls the [IAudioEndpoint::GetFramesPerPacket](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-getframesperpacket) method.

This method can be called from a real-time processing thread. The
implementation of this method must not block, access
paged memory, or call any blocking system routines.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioOutputEndpointRT](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiooutputendpointrt)