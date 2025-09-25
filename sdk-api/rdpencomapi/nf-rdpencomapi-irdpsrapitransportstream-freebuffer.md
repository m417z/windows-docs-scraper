# IRDPSRAPITransportStream::FreeBuffer

## Description

Called by the Remote Desktop Protocol (RDP) stack to return a stream buffer to the stream.

## Parameters

### `pBuffer` [in]

Type: **IRDPSRAPITransportStreamBuffer***

An [IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer) interface pointer that represents the buffer to free.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPITransportStream](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstream)