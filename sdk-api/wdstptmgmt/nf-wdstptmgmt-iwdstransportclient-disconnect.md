# IWdsTransportClient::Disconnect

## Description

Disconnects the WDS client from the session and specifies what action the client should take upon disconnection.

## Parameters

### `DisconnectionType` [in]

A value of the [WDSTRANSPORT_DISCONNECT_TYPE](https://learn.microsoft.com/windows/win32/api/wdstptmgmt/ne-wdstptmgmt-wdstransport_disconnect_type) enumeration that specifies what action the WDS client should take when disconnected.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportClient](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportclient)

[WDSTRANSPORT_DISCONNECT_TYPE](https://learn.microsoft.com/windows/win32/api/wdstptmgmt/ne-wdstptmgmt-wdstransport_disconnect_type)