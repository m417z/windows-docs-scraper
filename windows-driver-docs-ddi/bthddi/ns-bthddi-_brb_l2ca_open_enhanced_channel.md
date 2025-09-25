# _BRB_L2CA_OPEN_ENHANCED_CHANNEL structure

## Description

The _BRB_L2CA_OPEN_ENHANCED_CHANNEL structure is used to open an enhanced L2CAP channel to a remote device, or send a response for accepting/rejecting an incoming enhanced L2CAP connection request that was initiated by a remote device.

## Members

### `Hdr`

A [BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information about the current BRB.

### `ChannelHandle`

Handle used to identify the connection upon a successful connect. When sending a **BRB_L2CA_OPEN_CHANNEL**, this will be filled in when the BRB completes. When sending a **BRB_L2CA_OPEN_CHANNEL_RESPONSE** request, this must be filled in by the server before sending down the BRB. The value assigned should be `INDICATION_PARAMETERS::ConnectionHandle` which was passed in during the IndicationRemoteConnect.

### `Response`

Used only with **BRB_L2CA_OPEN_CHANNEL_RESPONSE**. One of the CONNECT_RSP_RESULT_Xxx values is used.

If the BRB returns with a status of STATUS_REQUEST_NOT_ACCEPTED, then *Response* will contain the negative response from the remote host.

### `ResponseStatus`

If *Response* is equal to CONNECT_RSP_RESULT_PENDING, then this field is valid. One of the CONNECT_RSP_STATUS_XXX values is used.

### `Psm`

The Protocol/Service Multiplexer (PSM) that the channel uses to connect to the remote device. When used with a **BRB_L2CA_OPEN_ENHANCED_CHANNEL** request, this member is set as an input field. When used with a **BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE** request, this member is used as an output field.

### `ChannelFlags`

Flags that specify the requirements for the channel to be opened. Valid flag values are listed in the following table:

| Flag | Description |
| ---- | ----------- |
| CF_LINK_AUTHENTICATED | The link must be authenticated. |
| CF_LINK_ENCRYPTED | The link must be encrypted. Setting this flag also sets the CF_LINK_AUTHENTICATED flag. |
| CF_LINK_SUPPRESS_PIN | The profile driver indicates its preference that users not be prompted for a PIN. |

### `BtAddress`

The Bluetooth address of the device for which the connection is intended.

### `ConfigOut`

The substructure that contains parameter settings for a **BRB_L2CA_OPEN_ENHANCED_CHANNEL** BRB sent to a remote device.

### `ConfigOut.Flags`

Flags that specify the requirements for the channel to be opened. Valid flag values are listed in the following table:

| Flag | Description |
| ---- | ----------- |
| CF_LINK_AUTHENTICATED | The link must be authenticated. |
| CF_LINK_ENCRYPTED | The link must be encrypted. Setting this flag also sets the CF_LINK_AUTHENTICATED flag. |
| CF_LINK_SUPPRESS_PIN | The profile driver indicates its preference that users not be prompted for a PIN. |
| CFG_ENHANCED | Specifies that the ModeConfig structure is valid. |
| CFG_FCS | Specifies that the Fcs value is valid. |

### `ConfigOut.Mtu`

The range of message transfer units (MTUs) that is used to negotiate the size of the outbound half of channel.

### `ConfigOut.FlushTO`

The range of possible values to be used for the flush timeout for the outbound half of the channel.

### `ConfigOut.Flow`

Reserved for future use. Do not use.

### `ConfigOut.LinkTO`

The Link Manager link timeout.

### `ConfigOut.NumExtraOptions`

The number of array items that are contained in the **ExtraOptions** member. This value should be zero for most clients.

### `ConfigOut.ExtraOptions`

Extra options. This value should be zero for most clients.

### `ConfigOut.LocalQos`

Reserved for future use. Do not use.

### `ConfigOut.LocalQos.ServiceType`

Reserved for future use. Do not use.

### `ConfigOut.LocalQos.Latency`

Reserved for future use. Do not use.

### `ConfigOut.ModeConfig`

Specifies the type of L2CAP channel being opened. This structure is valid only if CFG_ENHANCED flag is specified.

### `ConfigOut.ModeConfig.Flags`

Specifies the type of L2CAP channel mode requested.

| Flag | Description |
| ---- | ----------- |
| CM_BASIC | Open a basic mode channel. |
| CM_RETRANSMISSION_AND_FLOW | Open an enhanced retransmission mode channel. |
| CM_STREAMING | Open a streaming mode channel. |

### `ConfigOut.ModeConfig.RetransmissionAndFlow`

Specifies the options for
CM_RETRANSMISSION_AND_FLOW and CM_STREAMING modes. This structure must be zero if only CM_BASIC is specified in the **Flags** member.

The **Mode** submember of **RetransmissionAndFlow** should be set to 0. Use the **ModeConfig** submember of **RetransmissionAndFlow** to specify the type of channel to open.

### `ConfigOut.Fcs`

Specifies whether FCS should be used for the enhanced L2CAP channel. This value is valid only if CM_RETRANSMISSION_AND_FLOW or CM_STREAMING flag is specified in the **Flags** member.

### `ConfigOut.ExtendedFlowSpec`

Not supported.

### `ConfigOut.ExtendedWindowSize`

Not supported.

### `ConfigIn`

The substructure that contains parameter settings to validate incoming **BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE** BRBs that are sent from a remote device.

### `ConfigIn.Flags`

Flags that specify the requirements for the channel to be opened. Valid flag values are listed in the following table:

| Flag | Description |
| ---- | ----------- |
| CF_LINK_AUTHENTICATED | The link must be authenticated. |
| CF_LINK_ENCRYPTED | The link must be encrypted. Setting this flag also sets the CF_LINK_AUTHENTICATED flag. |
| CF_LINK_SUPPRESS_PIN | The profile driver indicates its preference that users not be prompted for a PIN. |

### `ConfigIn.Mtu`

The range of message transfer units (MTUs) that is used to negotiate the size of the inbound half of channel.

### `ConfigIn.FlushTO`

The range of possible values to be used for the flush timeout for the inbound half of the channel.

### `CallbackFlags`

A flag that specifies which events should generate a callback routine to notify the profile driver that the event has occurred. Valid flag values are contained in the following table.

| Flag | Description |
| --- | --- |
| CALLBACK_CONFIG_EXTRA_IN | If set, the callback routine will be called when the configuration request for the remote device contains extra options. If not set, the extra configuration options will be rejected as unknown options. This flag is used with **BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE** BRBs. |
| CALLBACK_CONFIG_EXTRA_OUT | If set, the callback routine will be called when the remote device rejects an extra configuration option from a **BRB_L2CA_OPEN_ENHANCED_CHANNEL** request. If not set and the remote device rejects the configuration request due to an extra option, the connection will be closed. |
| CALLBACK_CONFIG_QOS | If set, the callback routine will be called when a remote device sends a configuration request that contains a QOS value. If this flag is not set and the remote device either sends QOS parameters in a configuration request or rejects the profile driver's requested QOS parameters, the connection is disconnected. |
| CALLBACK_DISCONNECT | If set, the callback routine will be called when a remote device disconnects from the enhanced L2CAP channel. |
| CALLBACK_RECV_PACKET | If set, the callback routine will be called when the profile driver receives an incoming enhanced L2CAP packet. |

### `Callback`

The [Enhanced L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback_enhanced) implemented by the profile driver, that the Bluetooth driver stack should call to notify the profile driver about any changes to the enhanced L2CAP connection.

### `CallbackContext`

The context to pass to the callback function specified in the **Callback** member. The profile driver defines this value.

### `ReferenceObject`

A pointer to an object to pass to [ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject) and [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) for which to maintain a reference count.

### `OutResults`

A [CHANNEL_CONFIG_RESULTS_ENHANCED](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_results_enhanced) structure that contains configuration parameters negotiated for the outbound request.

### `InResults`

A CHANNEL_CONFIG_RESULTS_ENHANCED structure that contains configuration parameters negotiated for the inbound request.

### `IncomingQueueDepth`

Specifies the incoming queue length in message transfer units (MTUs).

### `Reserved`

Reserved member. Do not use.

#### Response

This member is used as an input parameter for a **BRB_L2CA_OPEN_ENHANCED_CHANNEL** request and an output parameter for the **BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE** request.

For a **BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE** request, this member holds a flag that indicates the profile driver's response to the remote device. Valid flag values are contained in the following table.

| Flag | Description |
| ---- | ----------- |
| CONNECT_RSP_RESULT_NO_RESOURCES | The profile driver refused the connection due to a lack of resources. |
| CONNECT_RSP_RESULT_PENDING | The profile driver is currently busy and cannot accept the connection. Try again later. |
| CONNECT_RSP_RESULT_PSM_NEG | The profile driver refused the connection because the PSM is not supported. |
| CONNECT_RSP_RESULT_SECURITY_BLOCK | The profile driver refused the connection for security reasons. |
| CONNECT_RSP_RESULT_SUCCESS | The profile driver accepted the connection. |

For the **BRB_L2CA_OPEN_ENHANCED_CHANNEL** BRB, this member contains the response from the remote device to which the profile driver attempted to connect. Valid flag values are contained in the following table.

|Flag|Description|
|--- |--- |
|CONNECT_RSP_RESULT_NO_RESOURCES|The remote device refused the connection due to a lack of resources.|
|CONNECT_RSP_RESULT_PSM_NEG|The remote device refused the connection.|
|CONNECT_RSP_RESULT_SECURITY_BLOCK|The remote device refused the connection for security reasons.|
|CONNECT_RSP_RESULT_SUCCESS|The remote device accepted the connection.|

#### ResponseStatus

If during a call to the BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE BRB the Response member is set to CONNECT_RSP_RESULT_PENDING, this member is valid and contains one of the following values:

- CONNECT_RSP_STATUS_AUTHENTICATION_PENDING
- CONNECT_RSP_STATUS_AUTHORIZATION_PENDING
- CONNECT_RSP_STATUS_NO_INFORMATION

## Remarks

Profile drivers can use `CM_BASIC | CM_RETRANSMISSION_AND_FLOW`, or `CM_BASIC | CM_STREAMING` modes for the **Flags** member. This indicates to open an enhanced retransmission mode, or streaming mode channel if possible, and if not fall back to basic mode channel.
A value of `CM_RETRANSMISSION_AND_FLOW | CM_STREAMING` is not supported.