# IRDPSRAPIVirtualChannel::SendData

## Description

Sends data on the channel.

## Parameters

### `bstrData` [in]

Type: **BSTR**

The buffer to be sent in a packet on the channel. The maximum size of the data is CONST_MAX_MESSAGE_SIZE bytes.

### `lAttendeeId` [in]

Type: **long**

The attendee that should receive the data. To send the data to all attendees, use CONST_ATTENDEE_ID_EVERYONE.

### `ChannelSendFlags` [in]

Type: **unsigned long**

The channel flags. This parameter can be 0 or the following value.

#### CHANNEL_FLAGS_UNCOMPRESSED

The data should not be compressed before it is sent because it is in a format that is already compressed.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPIVirtualChannel](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapivirtualchannel)