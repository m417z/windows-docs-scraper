# _BRB_L2CA_OPEN_CHANNEL structure

## Description

The _BRB_L2CA_OPEN_CHANNEL structure describes a L2CAP channel to open to a remote device, or a response from the profile driver accepting or rejecting an incoming L2CAP connection request that was initiated by a remote device.

## Members

### `Hdr`

A [BRB\_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information about the current BRB.

### `ChannelHandle`

Handle used to identify the connection upon a successful connect. When sending a **BRB_L2CA_OPEN_CHANNEL**, this will be filled in when the BRB completes. When sending a **BRB_L2CA_OPEN_CHANNEL_RESPONSE**, this must be filled in by the server before sending down the BRB. The value assigned should be `INDICATION_PARAMETERS::ConnectionHandle` which was passed in during IndicationRemoteConnect.

### `Response`

Used only with **BRB_L2CA_OPEN_CHANNEL_RESPONSE**. One of the CONNECT_RSP_RESULT_Xxx values is used.

If the BRB returns with a status of STATUS_REQUEST_NOT_ACCEPTED, then *Response* will contain the negative response from the remote host.

### `ResponseStatus`

If *Response* is equal to CONNECT_RSP_RESULT_PENDING, then this field is valid. One of the CONNECT_RSP_STATUS_XXX values is used.

### `Psm`

The Protocol/Service Multiplexer (PSM) that the channel uses to connect to the remote device. When used with a **BRB_L2CA_OPEN_CHANNEL** request, this member is set as an input field. When used with a **BRB_L2CA_OPEN_CHANNEL_RESPONSE** request, this member is used as an output field.

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

The substructure that contains parameter settings for a **BRB_L2CA_OPEN_CHANNEL** BRB sent to a remote device.

### `ConfigOut.Flags`

Flags that specify the requirements for the channel to be opened. Valid flag values are listed in the following table:

| Flag | Description |
| ---- | ----------- |
| CF_LINK_AUTHENTICATED | The link must be authenticated. |
| CF_LINK_ENCRYPTED | The link must be encrypted. Setting this flag also sets the CF_LINK_AUTHENTICATED flag. |
| CF_LINK_SUPPRESS_PIN | The profile driver indicates its preference that users not be prompted for a PIN. |

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

The number of array items that are contained in the **ExtraOptions** member. This value should be zero for most clients.

### `ConfigOut.LocalQos`

Reserved for future use. Do not use.

### `ConfigOut.LocalQos.ServiceType`

Reserved for future use. Do not use.

### `ConfigOut.LocalQos.Latency`

Reserved for future use. Do not use.

### `ConfigIn`

The substructure that contains parameter settings to validate incoming **BRB_L2CA_OPEN_CHANNEL_RESPONSE** BRBs that are sent from a remote device.

### `ConfigIn.Flags`

Flags that specify the requirements for the channel to be opened. Valid flag values are listed in the following table:

| Flag | Description|
| ---- | ---------- |
| CF_LINK_AUTHENTICATED | The link must be authenticated. |
| CF_LINK_ENCRYPTED | The link must be encrypted. Setting this flag also sets the CF_LINK_AUTHENTICATED flag. |
| CF_LINK_SUPPRESS_PIN | The profile driver indicates its preference that users not be prompted for a PIN. |

### `ConfigIn.Mtu`

The range of message transfer units (MTUs) that is used to negotiate the size of the outbound half of channel.

### `ConfigIn.FlushTO`

The range of possible values to be used for the flush timeout for the outbound half of the channel.

### `CallbackFlags`

A flag that specifies which events should generate a callback routine to notify the profile driver that the event has occurred. Valid flag values are contained in the following table.

| Flag | Description|
| ---- | ---------- |
| CALLBACK_CONFIG_EXTRA_IN | If set, the callback routine will be called when the configuration request for the remote device contains extra options. If not set, the extra configuration options will be rejected as unknown options. This flag is used with BRB_L2CA_OPEN_CHANNEL_RESPONSE BRBs. |
| CALLBACK_CONFIG_EXTRA_OUT | If set, the callback routine will be called when the remote device rejects an extra configuration option from a BRB_L2CA_OPEN_CHANNEL request. If not set and the remote device rejects the configuration request due to an extra option, the connection will be closed. |
| CALLBACK_CONFIG_QOS | If set, the callback routine will be called when a remote device sends a configuration request that contains a QOS value. If this flag is not set and the remote device either sends QOS parameters in a configuration request or rejects the profile driver's requested QOS parameters, the connection is disconnected. |
| CALLBACK_DISCONNECT | If set, the callback routine will be called when a remote device disconnects from the L2CAP channel. |
| CALLBACK_RECV_PACKET | If set, the callback routine will be called when the profile driver receives an incoming L2CAP packet. |

### `Callback`

The [L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback) implemented by the profile driver, that the Bluetooth driver stack should call to notify the profile driver about any changes to the L2CAP connection.

### `CallbackContext`

The context to pass to the callback function specified in the **Callback** member. The profile driver defines this value.

### `ReferenceObject`

A pointer to an object to pass to [ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject) and [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) for which to maintain a reference count of.

### `OutResults`

A [CHANNEL\_CONFIG\_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_results) structure that contains configuration parameters for the outbound request.

### `InResults`

A CHANNEL_CONFIG_RESULTS structure that contains configuration parameters for the inbound request.

### `IncomingQueueDepth`

Specifies the incoming queue length in message transfer units (MTUs).

#### Response

This member is used as an input parameter for a **BRB_L2CA_OPEN_CHANNEL_RESPONSE** request and an output parameter for the **BRB_L2CA_OPEN_CHANNEL** request.

For a **BRB_L2CA_OPEN_CHANNEL_RESPONSE** request, this member holds a flag that indicates the profile driver's response to the remote device. Valid flag values are contained in the following table.

| Flag | Description |
| ---- | ----------- |
| CONNECT_RSP_RESULT_NO_RESOURCES | The profile driver refused the connection due to a lack of resources. |
| CONNECT_RSP_RESULT_PENDING | The profile driver is currently busy and cannot accept the connection. Try again later. |
| CONNECT_RSP_RESULT_PSM_NEG | The profile driver refused the connection because the PSM is not supported. |
| CONNECT_RSP_RESULT_SECURITY_BLOCK | The profile driver refused the connection for security reasons. |
| CONNECT_RSP_RESULT_SUCCESS | The profile driver accepted the connection. |

For the **BRB_L2CA_OPEN_CHANNEL** BRB, this member contains the response from the remote device to which the profile driver attempted to connect. Valid flag values are contained in the following table.

| Flag | Description |
| ---- | ----------- |
| CONNECT_RSP_RESULT_NO_RESOURCES | The remote device refused the connection due to a lack of resources. |
| CONNECT_RSP_RESULT_PSM_NEG | The remote device refused the connection. |
| CONNECT_RSP_RESULT_SECURITY_BLOCK | The remote device refused the connection for security reasons. |
| CONNECT_RSP_RESULT_SUCCESS | The remote device accepted the connection. |

#### ResponseStatus

If during a call to the **BRB_L2CA_OPEN_CHANNEL_RESPONSE** BRB the *Response* member is set to `CONNECT_RSP_RESULT_PENDING`, this member is valid and contains one of the following values:

- CONNECT_RSP_STATUS_AUTHENTICATION_PENDING
- CONNECT_RSP_STATUS_AUTHORIZATION_PENDING
- CONNECT_RSP_STATUS_NO_INFORMATION

## Remarks

To open a L2CAP channel, profile drivers should [build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a [BRB\_L2CA\_OPEN\_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85)) request.

Profile drivers that act as clients specify a destination address, a PSM, and a variety of configuration parameters.

If the **BRB_L2CA_OPEN_CHANNEL** request completes successfully, a variety of information about the newly created connection is available in the **OutResults** and **InResults** members. **OutResults** specifies the parameters for the outbound half of the channel, and **InResults** specifies the parameters for the inbound half of the channel.

Several of the configuration parameters passed in this structure, such as the **Mtu** member, are ranges used for negotiation with the remote radio. Clients should provide as wide a range as possible to increase the chances of successful channel negotiation. Specifying a minimum MTU size greater than the basic Bluetooth minimum MTU size should only be done when absolutely necessary. If negotiation fails, the connection will fail.

Profile drivers must allocate the memory to store the array that is stored in the **ExtraOptions** member and should not free this memory until the callback function defined in the **Callback** member returns with an **IndicationFreeExtraOptions** notification [INDICATION\_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_indication_code) value passed in its *Indication* parameter.

The **IncomingQueueDepth** member of the _BRB_L2CA_OPEN_CHANNEL structure specifies the maximum number of MTUs that the Bluetooth driver stack will receive and queue on the connection before it begins to discard them. Setting this value to a very small number increases the chances of data loss, while setting it to a very large number can increase memory usage. Setting this member to 10 is an effective compromise.

To accept or reject an incoming L2CAP connection request initiated by a remote device, profile drivers should [build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a [ BRB\_L2CA\_OPEN\_CHANNEL\_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) request.

A profile driver should build and send a **BRB_L2CA_OPEN_CHANNEL_RESPONSE** request when the Bluetooth driver stack calls the profile driver's [L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback) and passes **IndicationRemoteConnect** in the callback function's *Indication* parameter.

Based on the value of the **Response** member of this structure, the Bluetooth driver stack will then accept or reject the connection request.

The profile driver specifies whether the connection should be accepted by storing an appropriate value in the **Response** member of this structure.

Upon receiving the CONNECT_RSP_RESULT_PENDING response, the connecting client should reset its connection timer and wait for an updated connection response message. Profile drivers calling the **BRB_L2CA_OPEN_CHANNEL_RESPONSE** BRB where the **Response** member is set to CONNECT_RSP_RESULT_PENDING should promptly issue an additional **BRB_L2CA_OPEN_CHANNEL_RESPONSE** BRB with an updated connection value. The updated value can be any of the status codes described in the **Response** member, including resending a CONNECT_RSP_RESULT_PENDING value.

Profile drivers must allocate the memory to store the array that is stored in the **ExtraOptions** member and should not free this memory until the callback function that is defined in the **Callback** member returns with an **IndicationFreeExtraOptions** notification **INDICATION_CODE** value passed in its *Indication* parameter.

## See also

[BRB\_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB\_L2CA\_OPEN\_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85))

[BRB\_L2CA\_OPEN\_CHANNEL\_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85))

[BRB\_L2CA\_REGISTER\_SERVER](https://learn.microsoft.com/previous-versions/ff536618(v=vs.85))

[CHANNEL\_CONFIG\_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_results)

[INDICATION\_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_indication_code)

[INDICATION\_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters)

[L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback)

[L2CAP\_CONFIG\_OPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_l2cap_config_option)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)