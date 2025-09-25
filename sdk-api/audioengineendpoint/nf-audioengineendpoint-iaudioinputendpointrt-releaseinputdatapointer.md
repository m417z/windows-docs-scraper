# IAudioInputEndpointRT::ReleaseInputDataPointer

## Description

The **ReleaseInputDataPointer** method releases the acquired data pointer.

## Parameters

### `u32FrameCount` [in]

The number of frames that have been
consumed by the audio engine. This count might not
be the same as the value returned by the [IAudioInputEndpointRT::GetInputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioinputendpointrt-getinputdatapointer) method in the *pConnectionProperty*->**u32ValidFrameCount** member.

### `pDataPointer` [in]

The pointer to the buffer retrieved by the [GetInputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioinputendpointrt-getinputdatapointer) method received in the *pConnectionProperty*->**pBuffer** member.

## Remarks

**ReleaseInputDataPointer** notifies the endpoint that the audio engine no longer requires the input data pointer and also indicates the number of frames used during the session.
For example, an endpoint, which represents a looped buffer, is connected to the input of the
audio engine and can advance its read
pointer by using the actual frame count.
If **u32FrameCount** is zero, this indicates that the client did not use any data
from the specified input buffer. The **u32FrameCount** must be less than or equal to the maximum frame count supported by the endpoint. To get the supported number of frames, the audio engine calls the [IAudioEndpoint::GetFramesPerPacket](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-getframesperpacket) method.

This method can be called from a real-time processing thread. The implementation of this method must not block, access paged memory, or call any blocking system routines.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioInputEndpointRT](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioinputendpointrt)