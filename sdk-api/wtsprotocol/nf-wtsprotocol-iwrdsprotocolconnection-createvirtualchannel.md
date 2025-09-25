# IWRdsProtocolConnection::CreateVirtualChannel

## Description

Requests that the protocol create a virtual channel.

## Parameters

### `szEndpointName` [in]

A null-terminated string that contains the endpoint data that uniquely identifies the connection.

### `bStatic` [in]

Specifies whether the virtual channel is static or dynamic.

#### TRUE

The channel is static.

#### FALSE

The channel is dynamic.

### `RequestedPriority` [in]

Specifies the requested priority for the channel.

### `phChannel` [out]

A pointer to a **ULONG** value that receives the handle for the channel created.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Virtual channels are software extensions that can be created to enhance a Remote Desktop Services application. Examples include support for additional hardware or additions to the functionality provided by a given protocol. For more information, see [Remote Desktop Services Virtual
Channels](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-virtual-channels).

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)