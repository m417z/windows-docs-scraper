# _BRB_SCO_GET_SYSTEM_INFO structure

## Description

The _BRB_SCO_GET_SYSTEM_INFO structure describes information about the local system's support for SCO
connections.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `Features`

A flag or combination of flags that indicates what SCO features the system supports. Possible
values include:

SCO_FEATURE_ESCO_LINKS

SCO_FEATURE_SCO_LINKS

### `MaxChannels`

The maximum number of active SCO channels that the system supports. This member is set to 0xFFFF
if there is no limit or if the limit is unknown.

### `TransferUnit`

The minimum data transfer speed per each request, in milliseconds . Set to 0xFFFF if this value is
variable or unknown.

### `PacketTypes`

A flag or combination of flags that indicates the type of SCO data packets that the local system
supports. These SCO packet types are defined by the Bluetooth SIG. See the Bluetooth specification for
more information about these flags. Possible values include:

SCO_HV1

SCO_HV2

SCO_HV3

SCO_EV3

SCO_EV4

SCO_EV5

### `DataFormats`

A flag or combination of flags the indicates the voice-encoding data formats supported by the
local system. Possible values include:

SCO_DATA_FORMAT_A_LAW_LOG

SCO_DATA_FORMAT_CVSD

SCO_DATA_FORMAT_MU_LAW_LOG

SCO_DATA_FORMAT_TRANSPARENT

### `Reserved`

Reserved for future use. Do not use.

## Remarks

To get the local system's support for SCO connections, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_GET_SYSTEM_INFO](https://learn.microsoft.com/previous-versions/ff536625(v=vs.85)) request.

Higher-level profile drivers can build and send a **BRB_SCO_GET_SYSTEM_INFO** request to determine whether
the local Bluetooth driver stack supports SCO connections, the maximum number of SCO channels that the
system supports, and other useful information for opening a SCO connection to a remote device.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_SCO_GET_SYSTEM_INFO](https://learn.microsoft.com/previous-versions/ff536625(v=vs.85))