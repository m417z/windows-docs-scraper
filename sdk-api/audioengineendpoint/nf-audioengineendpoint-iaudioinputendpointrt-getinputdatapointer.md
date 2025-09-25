# IAudioInputEndpointRT::GetInputDataPointer

## Description

The **GetInputDataPointer** method gets a pointer to the buffer from which data will be read by the audio engine.

## Parameters

### `pConnectionProperty` [in, out]

 A pointer to an [APO_CONNECTION_PROPERTY](https://learn.microsoft.com/windows/desktop/api/audioapotypes/ns-audioapotypes-apo_connection_property) structure.

The caller sets the member values as follows:

* **pBuffer** is set to **NULL**.
* **u32ValidFrameCount** contains the number of frames that need to be
  in the retrieved data pointer. The endpoint object must not cache this
  information. The audio engine can change this number depending on
  its processing needs.
* **u32BufferFlags** is set to **BUFFER_INVALID**.

If this call completes successfully, the endpoint must set the member values as follows:

* **pBuffer** points to valid memory where the data has been read. This could include silence depending on the flags that were set in the **u32BufferFlags** member.
* **u32ValidFrameCount** is unchanged.
* **u32BufferFlags** is set to **BUFFER_VALID** if the data pointer contains valid data or to **BUFFER_SILENT** if the data
  pointer contains only silent data. The data in the buffer does
  not actually need to be silence, but the buffer specified in **pBuffer** must be capable of holding all the frames of
  silence contained in **u32ValidFrameCount** to match the required frame count.

### `pAeTimeStamp` [in, out]

A pointer to an [AE_CURRENT_POSITION](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/ns-audioengineendpoint-ae_current_position) structure that contains the time stamp of the data that is captured in the buffer.
This parameter is optional.

## Remarks

This method returns a pointer from the endpoint to the buffer *pConnectionProperty*->**pBuffer**, which
contains data that needs to be passed into the engine as input.
The data and the buffer pointer must remain valid until the
[IAudioInputEndpointRT::ReleaseInputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioinputendpointrt-releaseinputdatapointer) method is called. The endpoint object must set the requested amount of information and insert silence if no
valid data exists.
The buffer pointer, *pConnectionProperty*->**pBuffer**, returned by the endpoint object must be frame aligned.
Endpoints do not support the extra space, which may be available in
the [APO_CONNECTION_PROPERTY](https://learn.microsoft.com/windows/desktop/api/audioapotypes/ns-audioapotypes-apo_connection_property) associated with the connection properties
passed in the *pConnectionProperty* parameter.

Passing zero in the **u32ValidFrameCount** member is a valid request. In this case,
the input pointer must be valid but the endpoint does not read from it. The *pConnectionProperty*->**u32ValidFrameCount** value must be less than or equal to the maximum frame count supported by the endpoint. To get the supported number of frames, call the [IAudioEndpoint::GetFramesPerPacket](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioendpoint-getframesperpacket) method.

This method can be called from a real-time processing thread. The
implementation of this method must not block, access
paged memory, or call any blocking system routines.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioInputEndpointRT](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioinputendpointrt)