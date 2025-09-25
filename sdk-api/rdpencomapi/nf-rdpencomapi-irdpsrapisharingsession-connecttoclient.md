# IRDPSRAPISharingSession::ConnectToClient

## Description

Used for reverse connect mode, where the sharer connects to the viewer. In this mode, the sharer sends the invitation file to the viewer out-of-band by using instant messaging (IM) or email. For the sharer to connect to the viewer, the sharer receives a connection string from the viewer out-of-band through IM or email.

## Parameters

### `bstrConnectionString` [in]

Type: **BSTR**

Connection string that the viewer sends to the sharer out-of-band through IM or email.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPISharingSession](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession)

[IRDPSRAPISharingSession2](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession2)