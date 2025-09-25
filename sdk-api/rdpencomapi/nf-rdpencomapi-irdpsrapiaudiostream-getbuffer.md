# IRDPSRAPIAudioStream::GetBuffer

## Description

Gets audio data from the buffer.
This method locks an internal buffer and returns a pointer to a specific location in that buffer. It does not allocate a copy of the buffer for the caller. To release the buffer after the last call to this method, call the [FreeBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiaudiostream-freebuffer) method.

## Parameters

### `ppbData` [out]

A pointer to the current location in the buffer.

### `pcbData` [out]

The size in bytes of the available data in the buffer.

### `pTimestamp` [out]

The time-based location of the location pointer.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[FreeBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiaudiostream-freebuffer)

[IRDPSRAPIAudioStream](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiaudiostream)