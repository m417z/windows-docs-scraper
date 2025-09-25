# APO_CONNECTION_PROPERTY structure

## Description

Contains the dynamically changing connection properties.

## Members

### `pBuffer`

A pointer to the connection buffer. Endpoints use this buffer to read and write
audio data.

### `u32ValidFrameCount`

The number of valid frames in the connection buffer. An APO uses the valid frame count to determine the amount of data to read and process in the input buffer. An APO sets the valid frame count
after writing data into its output connection.

### `u32BufferFlags`

The connection flags for this buffer. This indicates the validity status of the APOs. For more information about these flags, see [APO_BUFFER_FLAGS](https://learn.microsoft.com/windows/desktop/api/audioapotypes/ne-audioapotypes-apo_buffer_flags).

### `u32Signature`

A tag that identifies a valid **APO_CONNECTION_PROPERTY** structure. A valid structure is marked as **APO_CONNECTION_PROPERTY_SIGNATURE**. If the value of this field is equal to **APO_CONNECTION_PROPERTY_V2_SIGNATURE**, the structure can be safely typecast to a [APO_CONNECTION_PROPERTY_V2](https://learn.microsoft.com/windows/win32/api/audioapotypes/ns-audioapotypes-apo_connection_property_v2).

## Remarks

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.