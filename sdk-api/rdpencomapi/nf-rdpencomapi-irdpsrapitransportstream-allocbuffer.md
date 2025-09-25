# IRDPSRAPITransportStream::AllocBuffer

## Description

Called by the Remote Desktop Protocol (RDP) stack to allocate a stream buffer.

## Parameters

### `maxPayload` [in]

Type: **long**

The maximum size, in bytes, of the payload that will be placed into the buffer.

### `ppBuffer` [out, retval]

Type: **[IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer)****

The address of an [IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer) interface pointer that receives the buffer object.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPITransportStream](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstream)

[IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer)