# CHANNEL_FLAGS enumeration

## Description

Defines values for how data is sent on the channel.

## Constants

### `CHANNEL_FLAGS_LEGACY:0x1`

Reserved.

### `CHANNEL_FLAGS_UNCOMPRESSED:0x2`

Data sent on the channel is not compressed. Use this option if the data is already compressed.

## See also

[IRDPSRAPIVirtualChannelManager::CreateVirtualChannel](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapivirtualchannelmanager-createvirtualchannel)