# IRDPSRAPIVirtualChannel::SetAccess

## Description

Enables the channel for an attendee.

## Parameters

### `lAttendeeId` [in]

Type: **long**

The identifier of the attendee.

### `AccessType` [in]

Type: **CHANNEL_ACCESS_ENUM**

The type of access granted. This parameter can be one of the following values.

#### CHANNEL_ACCESS_ENUM_NONE

#### CHANNEL_ACCESS_ENUM_SENDRECEIVE

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## Remarks

This method must be called for each attendee that will receive data over the channel.

## See also

[IRDPSRAPIVirtualChannel](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapivirtualchannel)