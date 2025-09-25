# IWTSProtocolConnection::CreateVirtualChannel

## Description

[**IWTSProtocolConnection::CreateVirtualChannel** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::CreateVirtualChannel](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-createvirtualchannel).]

Creates a static or dynamic virtual channel.

## Parameters

### `szEndpointName` [in]

A string value that contains the endpoint data that uniquely identifies the connection.

### `bStatic` [in]

A Boolean value that specifies whether the virtual channel is static or dynamic. A value of **TRUE** specifies a static channel.

### `RequestedPriority` [in]

An integer that contains the priority.

### `phChannel` [out]

A pointer to the channel handle.

## Remarks

Virtual channels are software extensions that can be created to enhance a Remote Desktop Services application. Examples include support for additional hardware or additions to the functionality provided by a given protocol. For more information, see [Remote Desktop Services Virtual
Channels](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-virtual-channels).

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)