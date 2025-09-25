# APO_BUFFER_FLAGS enumeration

## Description

Defines the buffer validation flags for the [APO_CONNECTION_PROPERTY](https://learn.microsoft.com/windows/desktop/api/audioapotypes/ns-audioapotypes-apo_connection_property) structure associated with each APO connection.

## Constants

### `BUFFER_INVALID`

There is no valid data in the connection
buffer. The buffer pointer is valid and the buffer is capable of holding the amount of valid audio data specified in the [APO_CONNECTION_PROPERTY](https://learn.microsoft.com/windows/desktop/api/audioapotypes/ns-audioapotypes-apo_connection_property) structure.
While processing audio data, the audio engine marks every connection as BUFFER_INVALID before calling [IAudioOutputEndpoint::GetOutputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudiooutputendpointrt-getoutputdatapointer) or
[IAudioInputEndpointRT::GetInputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioinputendpointrt-getinputdatapointer).

### `BUFFER_VALID`

The connection buffer contains valid data. This is the operational state of the connection buffer. The APO sets this flag after it
starts writing valid data into the buffer.
Capture endpoints should set this flag in the [GetInputDataPointer](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nf-audioengineendpoint-iaudioinputendpointrt-getinputdatapointer) method upon successful completion of the call.

### `BUFFER_SILENT`

The connection buffer must be treated as if it contains silence.
If the endpoint receives an input connection buffer that is identified as BUFFER_SILENT, then the endpoint can assume the data represents silence. When capturing, the endpoint can also set this flag, if necessary for a capture buffer.

## Remarks

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.