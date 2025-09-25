# _BRB_SCO_GET_CHANNEL_INFO structure

## Description

The _BRB_SCO_GET_CHANNEL_INFO structure describes the settings and statistics of a SCO
channel.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The Bluetooth address of the remote device.

### `ChannelHandle`

The handle to the SCO channel to query.

### `InfoFlags`

A flag that determines if baseband information is available for the SCO channel. The following
flag is defined:

| Flag | Description |
| --- | --- |
| SCO_INFO_BASEBAND_AVAILABLE | If set, baseband settings are available for the SCO channel. |

### `TransmitBandwidth`

The transmission bandwidth of the channel, in bytes per second.

### `ReceiveBandwidth`

The reception bandwidth of the channel, in bytes per second.

### `MaxLatency`

A value that represents the upper limit of the sum of the synchronous interval and the size of the
SCO window, in milliseconds. Possible values are listed in the following table.

| Values | Description |
| --- | --- |
| 0x0000 to 0x0003 | Reserved for future use. |
| 0x0004 to 0xFFFE | The range of latency values for the channel. |
| 0xFFFF | The channel doesn't have a preferred **MaxLatency** setting. |

### `PacketType`

A flag or combination of flags that indicates the type of data packets that the SCO channel
supports. These SCO packet types are defined by the Bluetooth SIG. See the Bluetooth specification for
more information about these flags. Possible values include:

SCO_HV1

SCO_HV2

SCO_HV3

SCO_EV3

SCO_EV4

SCO_EV5

### `ContentFormat`

The audio voice setting for the channel. Use the following definitions to decode this member:

SCO_VS_AIR_CODING_DATA

SCO_VS_AIR_CODING_FORMAT_ALAW

SCO_VS_AIR_CODING_FORMAT_CVSD

SCO_VS_AIR_CODING_FORMAT_MASK

SCO_VS_AIR_CODING_FORMAT_MULAW

SCO_VS_IN_CODING_ALAW

SCO_VS_IN_CODING_LINEAR

SCO_VS_IN_CODING_MASK

SCO_VS_IN_CODING_MULAW

SCO_VS_IN_DATA_FORMAT_1C

SCO_VS_IN_DATA_FORMAT_2C

SCO_VS_IN_DATA_FORMAT_MASK

SCO_VS_IN_DATA_FORMAT_SM

SCO_VS_IN_DATA_FORMAT_US

SCO_VS_IN_SAMPLE_SIZE_8BIT

SCO_VS_IN_SAMPLE_SIZE_16BIT

SCO_VS_IN_SAMPLE_SIZE_MASK

SCO_VS_PCM_BIT_POS_MASK

SCO_VS_SETTING_DEFAULT

### `Reserved`

Reserved for future use. Do not use.

### `RetransmissionEffort`

A
[SCO_RETRANSMISSION_EFFORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_retransmission_effort) value that
determines the channel's retransmission policies.

### `ChannelFlags`

Flags that specify how the channel was opened. Valid flag values are listed in the following
table.

| Flag | Description |
| --- | --- |
| SCO_CF_LINK_AUTHENTICATED | The link must be authenticated. |
| SCO_CF_LINK_ENCRYPTED | The link must be encrypted. Setting this flag also sets the SCO_CF_LINK_AUTHENTICATED flag. |
| SCO_CF_LINK_SUPPRESS_PIN | The profile driver indicates its preference that users not be prompted for a PIN. |

### `HciConnectionHandle`

The host controller interface's connection handle for the SCO connection.

### `LinkType`

The
[SCO_LINK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_link_type) that is associated with the host
controller interface.

### `BasebandInfo`

A
[BASEBAND_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_baseband_channel_info) structure that
contains information for the SCO connection. This information is only available for links established
using the 1.2 Bluetooth Synchronous Commands.

## Remarks

To get the settings and statistics of a SCO channel, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_GET_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_channel_info) request.

## See also

[BASEBAND_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_baseband_channel_info)

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_SCO_GET_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_channel_info)

[SCO_LINK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_link_type)

[SCO_RETRANSMISSION_EFFORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_retransmission_effort)