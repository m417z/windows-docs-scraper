# IPSEC_TRANSFORM_TYPE enumeration

## Description

The **IPSEC_TRANSFORM_TYPE** enumerated type indicates the type of an IPsec security association (SA) transform.

## Constants

### `IPSEC_TRANSFORM_AH:1`

Specifies Authentication Header (AH) transform.

### `IPSEC_TRANSFORM_ESP_AUTH`

Specifies Encapsulating Security Payload (ESP) authentication-only transform.

### `IPSEC_TRANSFORM_ESP_CIPHER`

Specifies ESP cipher transform.

### `IPSEC_TRANSFORM_ESP_AUTH_AND_CIPHER`

Specifies ESP authentication and cipher transform.

### `IPSEC_TRANSFORM_ESP_AUTH_FW`

Specifies that the first packet should be sent twice: once with ESP/AH encapsulation, and once in clear text. The entire session is then sent in clear text.

The initial packet will allow the existing firewall rules to apply to the connection. The subsequent clear text data stream allows intermediaries to modify the stream.

**Note** Available only on Windows Server 2008 R2, Windows 7, or later.

### `IPSEC_TRANSFORM_TYPE_MAX`

Maximum value for testing only.

## See also

[WFP Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)