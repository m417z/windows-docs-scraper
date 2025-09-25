# RDPENCOMAPI_CONSTANTS enumeration

## Description

Defines values for some of the constants used in this API.

## Constants

### `CONST_MAX_CHANNEL_MESSAGE_SIZE:1024`

Maximum message size, in bytes.

### `CONST_MAX_CHANNEL_NAME_LEN:8`

Maximum length (including the null terminator) of a channel name, in characters.

Note that the legacy channel names are limited to 32 characters.

### `CONST_MAX_LEGACY_CHANNEL_MESSAGE_SIZE:409600`

Maximum message size for a legacy channel, in bytes.

Use this constant if **CHANNEL_FLAGS_LEGACY** is set.

### `CONST_ATTENDEE_ID_EVERYONE:-1`

Indicates all attendees.

### `CONST_ATTENDEE_ID_HOST:0`

Identifies the host. Used to send a virtual channel message to the host.

### `CONST_CONN_INTERVAL:50`

Not used.

### `CONST_ATTENDEE_ID_DEFAULT:0xffffffff`

The default value for the [IRDPSRAPIAttendee](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiattendee)::[Id](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiattendee-get_id) property.

**Windows Server 2012 R2, Windows 8.1, Windows Server 2012, Windows 8, Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This enumeration value is not supported before Windows 10 and Windows Server 2016.