# IRDPSRAPITransportStreamEvents::OnWriteCompleted

## Description

Notifies the Remote Desktop Protocol (RDP) stack that a write operation has completed. The RDP stack resumes ownership of the stream buffer and uses it for subsequent operations.

## Parameters

### `pBuffer` [in]

Type: **[IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer)***

An [IRDPSRAPITransportStreamBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreambuffer) interface pointer that represents the stream buffer that was written.

## See also

[IRDPSRAPITransportStreamEvents](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreamevents)

[WriteBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapitransportstream-writebuffer)