# _WWAN_CONTEXT_STATE structure

## Description

The WWAN_CONTEXT_STATE structure represents the Packet Data Protocol (PDP) context state of the MB
device.

## Members

### `uNwError`

A network-specific error. The following table shows the connection failure values as documented in
the
*3GPP TS 24.008 Specification*.

| 3GPP 24.008 cause code | Interpretation of cause code |
| --- | --- |
| 8 - Operator determined barring | Packet data service is blocked by the operator. |
| 26 - Insufficient resources | Context cannot be activated because of insufficient resources on network. |
| 27 - Missing or unknown Access Point Name (APN) | No APN or unknown APN is provided in the activation request. |
| 29 , 30, 31 - User authentication failed | Wrong user name or password provided in the activation request. |
| 32 - Service option not supported | GPRS is not supported by the network. |
| 33 - Requested service option is not subscribed | Requested service (GPRS) is not subscribed by the user. |
| 34 - Service option is temporarily out of order | Packet data service is temporarily out of order. User must retry later. |
| 43 - Unknown Packet Data Protocol (PDP) context | No APN or unknown APN is provided in the activation request. |

### `ConnectionId`

The MB Service specifies a value for this member at the time of the connect request by using
OID_WWAN_CONNECT. Miniport drivers must copy this value and use it when they notify the MB Service on
subsequent connection state changes.

### `ActivationState`

The current activation state of the device.

### `VoiceCallState`

The current voice call state of the device.

### `IPType`

A value from the WWAN_IP_TYPE enumeration that specifies the type of IP.

### `ConnectionMedia`

The media type for an established context/session.

### `AccessString`

The selected APN/DNN for an established context/session.

### `Snssai`

A [**WWAN_SINGLE_NSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai) structure representing a single Network Slice Selection Assistance Information (NSSAI).

### `FoundMatchingConnectionId`

Only valid if the status is WWAN_STATUS_SESSION_ALREADY_EXISTS.

### `TrafficParameters`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. Only valid if the status is WWAN_STATUS_DESSOCIATION_NEEDED_FOR_APPLICATION.
The first 4 bytes are the offset to the DataBuffer containing the raw data of MBIM_TLV_TYPE_TRAFFIC_PARAMETERS, in bytes, calculated from the beginning of WWAN_SET_CONTEXT_STATE. The second 4 bytes are the size of the raw data of MBIM_TLV_TYPE_TRAFFIC_PARAMETERS, in bytes.

## Remarks

*Set* OID requests as well as unsolicited status events use the
**uNwError** member. If there is no network specific error or the network specific error is not known,
miniport drivers should set this member to 0.

The following points provide guidelines on returning network specific error in different
scenarios:

* If a set request fails, miniport drivers should return the network specific error code. In this
  case, the miniport driver should set the
  **uStatus** member of the NDIS_WWAN_CONTEXT_STATE structure to WWAN_STATUS_FAILURE, or a more
  specific error like WWAN_STAUS_INVALID_ACCESS_STRING or WWAN_STATUS_INVALID_USER_NAME_PWD, and set the
  **uNwError** member to the network specific error code.
* Whenever the device context activation state changes because of network initiated context deactivate
  then unsolicited status events should include the network specific error. In this case, the miniport
  driver should set the
  **uStatus** member of the NDIS_WWAN_CONTEXT_STATE structure to WWAN_STATUS_SUCCESS, and set the
  **uNwError** member to the network specific error code.

Miniport drivers can provide additional error codes as defined by the GSM standards specification of
context activation error codes returned by the network. For example, miniport drivers can communicate the
3GPP specification TS 24.008 context activation error codes, such as error code 8 (Operator determined
barring), to the MB Service through the
**uNwError** member. There is no standard available for CDMA-based network specific error codes.
CDMA-based devices and networks can return network specific error code information using the
**uNwError** member.

In case of response to the NDIS_WWAN_SET_CONTEXT_STATE, use this member to provide additional error
codes returned by the network.

## See also

[NDIS_WWAN_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_context_state)

[WWAN_ACTIVATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_activation_state)

[WWAN_VOICE_CALL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_voice_call_state)