# _WWAN_AUTH_PROTOCOL enumeration

## Description

The WWAN_AUTH_PROTOCOL enumeration lists the different types of authentication protocols that are
supported by the MB device.

## Constants

### `WwanAuthProtocolNone`

No authentication protocol.

### `WwanAuthProtocolPap`

Unencrypted password authentication.

### `WwanAuthProtocolChap`

Use the Challenge Handshake Authentication Protocol (CHAP).

### `WwanAuthProtocolMsChapV2`

Use the Microsoft Challenge Handshake Authentication Protocol (CHAP) v2.0.

### `WwanAuthProtocolAuto`

### `WwanAuthProtocolMax`

The total number of supported authentication protocols.

## Remarks

This enumeration applies only to GSM devices. The MB Service specifies
**WwanAuthProtocolNone** as the authentication type for CDMA-based devices.

## See also

[WWAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context)

[WWAN_SET_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_state)