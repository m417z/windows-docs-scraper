# _BRB_L2CA_UPDATE_CHANNEL structure

## Description

The _BRB_L2CA_UPDATE_CHANNEL structure describes an update to the link characteristics of an open
L2CAP channel to a remote device or to ascertain when certain channel attributes have changed.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The Bluetooth address of the remote device.

### `ChannelHandle`

The L2CAP channel handle that was returned by Bluetooth driver stack in response to an earlier
[BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85)) or
[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) request.

### `NewChannelFlags`

 A combination of flag values that specify the updated requirements for the channel. This member
should be set to CF_ROLE_EITHER.

### `FailedChannelFlags`

The flag or flags in the
**NewChannelFlags** member that the Bluetooth driver stack was not able to honor. This member contains
information only if the BRB call failed.

## Remarks

To retrieve the current settings of a L2CAP channel, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_UPDATE_CHANNEL](https://learn.microsoft.com/previous-versions/ff536620(v=vs.85)) request.

The profile driver can then determine when certain channel attributes have changed. Additionally, if
the CF_LINK_PASSIVE_MODE flag is not set, the BRB will attempt to change the current channel settings to
the remote device.

The primary use of **BRB_L2CA_UPDATE_CHANNEL** is to determine when authentication or encryption has been
enabled for a connection.

In some cases, L2CAP connections can be established without the profile driver specifying that
authentication is required, but authentication will happen automatically due to choices made by the user.
In this case, a period of time passes between when the connection is established and when authentication
and encryption begin working. Calls to **BRB_L2CA_UPDATE_CHANNEL** are blocked until authentication and
encryption are complete.

By building and sending a **BRB_L2CA_UPDATE_CHANNEL** request, profile drivers can avoid using the
connection prior to authentication.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85))

[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85))

[BRB_L2CA_UPDATE_CHANNEL](https://learn.microsoft.com/previous-versions/ff536620(v=vs.85))