# _BRB_SCO_OPEN_CHANNEL structure

## Description

The _BRB_SCO_OPEN_CHANNEL structure describes a SCO channel to open to a remote device, or a response
from the profile driver accepting or rejecting an incoming SCO connection request that was initiated by a
remote device.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The Bluetooth address of the remote device to open a SCO channel to.

### `TransmitBandwidth`

The transmission bandwidth, in bytes per second, to be assigned to the SCO channel.

### `ReceiveBandwidth`

The reception bandwidth, in bytes per second, to be assigned to the SCO channel.

### `MaxLatency`

A value that represents, in milliseconds, the upper limit of the sum of the synchronous interval
and the size of the (e)SCO window. Possible values are listed in the following table.

|  |  |
| --- | --- |
| **Values** | **Description** |
| 0x0000 to 0x0003 | Reserved for future use. |
| 0x0004 to 0xFFFE | The range of possible **MaxLatency** values for the channel. |
| 0xFFFF | The channel doesn't have a preferred **MaxLatency** setting. |

### `PacketType`

A flag or combination of flags that indicate the type of data packets that the SCO connection
supports. These SCO packet types are defined by the Bluetooth SIG. See the Bluetooth specification for
more information about these flags. Possible values include:

#### SCO_HV1

#### SCO_HV2

#### SCO_HV3

#### SCO_EV3

#### SCO_EV4

#### SCO_EV5

### `ContentFormat`

The audio voice settings for the channel. Use the following definitions to encode this member:

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
[SCO_RETRANSMISSION_EFFORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_retransmission_effort) enumeration value that determines the retransmission policies for the
channel.

### `ChannelFlags`

Flags that specify the requirements for the channel to be opened. Valid flag values are listed in
the following table:

|  |  |
| --- | --- |
| **Flag** | **Description** |
| SCO_CF_LINK_AUTHENTICATED | The link must be authenticated. |
| SCO_CF_LINK_ENCRYPTED | The link must be encrypted. Setting this flag also sets the SCO_CF_LINK_AUTHENTICATED flag. |
| SCO_CF_LINK_SUPPRESS_PIN | The profile driver indicates its preference that users not be prompted for a PIN. |

### `CallbackFlags`

A flag that specifies when the function assigned to the
**Callback** member should be sent to the client. Currently, there is only one valid flag:

|  |  |
| --- | --- |
| **Flag** | **Description** |
| SCO_CALLBACK_DISCONNECT | The profile driver should be notified when the remote device is disconnected. |

### `Callback`

The
[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback) implemented by
the profile driver, that the Bluetooth driver stack should call to notify the profile driver about any
changes to the SCO connection.

### `CallbackContext`

The context to pass to the callback function specified in the
**Callback** member. The profile driver defines this value.

### `ReferenceObject`

A pointer to an object to pass to
[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject) and
[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) for which to
maintain a reference count of.

### `ChannelHandle`

A handle to identify the SCO channel, if the open channel request completes successfully.

### `Response`

A flag that indicates whether the local server will accept or reject an incoming SCO connection.
This member is used only when building and sending a **BRB_SCO_OPEN_CHANNEL_RESPONSE** request. Valid flag
values are listed in the following table.

| Flag | Description |
| --- | --- |
| SCO_CONNECT_RSP_RESPONSE_SUCCESS | The local server accepts the SCO connection request. |
| SCO_CONNECT_RSP_RESPONSE_NO_RESOURCES | The local server rejects the SCO connection request due to a lack of resources. |
| SCO_CONNECT_RSP_RESPONSE_SECURITY_BLOCK | The local server rejects the SCO connection request because the request does not meet security requirements. |
| SCO_CONNECT_RSP_RESPONSE_BAD_BD_ADDR | The local server rejects the SCO connection request because it does not accept connections from the specified Bluetooth device address. |

## Remarks

To open a SCO channel, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536626(v=vs.85)) request.

If the asynchronous connectionless link to the remote device does not exist prior to the request, the
Bluetooth driver stack creates one before it creates the SCO channel.

To accept or reject an incoming SCO connection request initiated by a remote device, profile drivers
should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_OPEN_CHANNEL_RESPONSE](https://social.msdn.microsoft.com/Forums/0a9a4323-d046-4d27-9d22-4974dbab30a4/home?forum=windows-bluetooth-sco-brbscoopenchannelresponse) request.

A profile driver should build and send a **BRB_SCO_OPEN_CHANNEL_RESPONSE** request when the Bluetooth
driver stack calls the profile driver's
[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback) and passes
**ScoIndicationRemoteConnect** in the callback function's
*Indication* parameter.

The profile driver specifies whether the connection should be accepted by storing an appropriate value
in the
**Response** member of this structure. In this context, the local system is the server.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536626(v=vs.85))

[BRB_SCO_OPEN_CHANNEL_RESPONSE](https://social.msdn.microsoft.com/Forums/0a9a4323-d046-4d27-9d22-4974dbab30a4/home?forum=windows-bluetooth-sco-brbscoopenchannelresponse)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)

[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback)

[SCO_RETRANSMISSION_EFFORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_retransmission_effort)