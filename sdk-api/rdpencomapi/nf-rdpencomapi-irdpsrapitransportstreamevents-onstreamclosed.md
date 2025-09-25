# IRDPSRAPITransportStreamEvents::OnStreamClosed

## Description

Notifies the Remote Desktop Protocol (RDP) stack that the connection was closed.

## Parameters

### `hrReason` [in]

Type: **HRESULT**

An **HRESULT** value that specifies if the stream was closed normally or due to an error. Contains **S_OK** if the stream was closed normally or an error code otherwise.

## See also

[IRDPSRAPITransportStreamEvents](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapitransportstreamevents)