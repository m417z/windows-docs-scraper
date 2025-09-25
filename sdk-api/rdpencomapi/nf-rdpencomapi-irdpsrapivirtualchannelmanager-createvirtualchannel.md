# IRDPSRAPIVirtualChannelManager::CreateVirtualChannel

## Description

Creates a virtual channel.

## Parameters

### `bstrChannelName` [in]

Type: **BSTR**

The name of the channel. The maximum length is 8 characters, including the null-terminating character. Legacy channel names are limited to 32 characters.

### `Priority` [in]

Type: **CHANNEL_PRIORITY**

The priority of the channel. This parameter can be one of the following values.

#### CHANNEL_PRIORITY_LO

#### CHANNEL_PRIORITY_MED

#### CHANNEL_PRIORITY_HI

### `ChannelFlags` [in]

Type: **unsigned long**

Flags that determine how data is sent on the channel. This parameter can be 0 or [CHANNEL_FLAGS_UNCOMPRESSED](https://learn.microsoft.com/windows/win32/api/rdpencomapi/ne-rdpencomapi-channel_flags).

### `ppChannel` [out]

Type: **IRDPSRAPIVirtualChannel****

An [IRDPSRAPIVirtualChannel](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapivirtualchannel) interface pointer.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code. The following is a possible value.

## Remarks

When a virtual channel is created, an RDP virtual channel is bound at the RDP stack layer for each opened channel. For a channel to actually be opened between the client and the server, both the client and the server have to bind the channel. The *Priority* parameter is used to assign a priority to the packets send on the channel.

The binding between server and client channels is established based on the channel name.

## See also

[IRDPSRAPIVirtualChannelManager](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapivirtualchannelmanager)