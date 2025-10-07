# CBCreateClientInstance function

Creates an instance of the Remote Desktop Connection Broker RPC client.

## Parameters

*Version* \[in\]

Specifies the version of the Remote Desktop Connection Broker client interface being requested. This must be the following value.

1

Version 1 of the Remote Desktop Connection Broker client.

*ppCbClient* \[out\]

The address of an [**IConnectionBrokerClient**](https://learn.microsoft.com/windows/win32/termserv/iconnectionbrokerclient) interface pointer that receives the Remote Desktop Connection Broker client object.

## Return value

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | Cbclient.h |
| Library<br> | Cbclient.lib |
| DLL<br> | Cbclient.dll |

