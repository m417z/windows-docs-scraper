# IRDPSRAPITransportStream::ReadBuffer

## Description

Called by the Remote Desktop Protocol (RDP) stack to read the contents of a stream buffer.

## Parameters

### `pBuffer` [in]

Type: **[IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer)***

An [IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer) interface pointer that represents the buffer to read.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPITransportStream](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstream)