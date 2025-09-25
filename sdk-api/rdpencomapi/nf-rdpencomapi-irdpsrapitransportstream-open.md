# IRDPSRAPITransportStream::Open

## Description

Called by the Remote Desktop Protocol (RDP) stack to start the stream and indicate that the RDP stack is ready to receive notifications of events.

## Parameters

### `pCallbacks` [in]

Type: **[IRDPSRAPITransportStreamEvents](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreamevents)***

An [IRDPSRAPITransportStreamEvents](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreamevents) interface pointer that will receive the transport stream events.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPITransportStream](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstream)

[IRDPSRAPITransportStreamEvents](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreamevents)