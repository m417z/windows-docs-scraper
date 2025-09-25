# SCHANNEL_ALERT_TOKEN structure

## Description

Generates a [Secure Sockets Layer Protocol](https://learn.microsoft.com/windows/desktop/SecAuthN/secure-sockets-layer-protocol) (SSL) or Transport Layer Security Protocol (TLS) alert to be sent to the target of a call to either the [InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function or the [AcceptSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function.

## Members

### `dwTokenType`

Specifies the type of this structure. Set the value of this member to **SCHANNEL_ALERT**.

### `dwAlertType`

Specifies the alert type. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **TLS1_ALERT_WARNING**<br><br>1 | The message is a warning. |
| **TLS1_ALERT_FATAL**<br><br>2 | The message is a fatal error. The connection is closed immediately. |

### `dwAlertNumber`

One of the alert messages defined by the TLS protocol specification. For descriptions of the defined messages, see [RFC 5246](http://tools.ietf.org/html/rfc5246#section-7.2), [RFC 4346](http://tools.ietf.org/html/rfc4346#section-7.2), or [RFC 2246](http://tools.ietf.org/html/rfc2246#section-7.2). This member must be one of the following values.

#### TLS1_ALERT_CLOSE_NOTIFY (0)

#### TLS1_ALERT_UNEXPECTED_MESSAGE (10)

#### TLS1_ALERT_BAD_RECORD_MAC (20)

#### TLS1_ALERT_DECRYPTION_FAILED (21)

#### TLS1_ALERT_RECORD_OVERFLOW (22)

#### TLS1_ALERT_DECOMPRESSION_FAIL (30)

#### TLS1_ALERT_HANDSHAKE_FAILURE (40)

#### TLS1_ALERT_BAD_CERTIFICATE (42)

#### TLS1_ALERT_UNSUPPORTED_CERT (43)

#### TLS1_ALERT_CERTIFICATE_REVOKED (44)

#### TLS1_ALERT_CERTIFICATE_EXPIRED (45)

#### TLS1_ALERT_CERTIFICATE_UNKNOWN (46)

#### TLS1_ALERT_ILLEGAL_PARAMETER (47)

#### TLS1_ALERT_UNKNOWN_CA (48)

#### TLS1_ALERT_ACCESS_DENIED (49)

#### TLS1_ALERT_DECODE_ERROR (50)

#### TLS1_ALERT_DECRYPT_ERROR (51)

#### TLS1_ALERT_EXPORT_RESTRICTION (60)

#### TLS1_ALERT_PROTOCOL_VERSION (70)

#### TLS1_ALERT_INSUFFIENT_SECURITY (71)

#### TLS1_ALERT_INTERNAL_ERROR (80)

#### TLS1_ALERT_USER_CANCELED (90)

#### TLS1_ALERT_NO_RENEGOTIATION (100)

#### TLS1_ALERT_UNSUPPORTED_EXT (110)

## Remarks

Add an alert message to a client context by using this structure as the value of the *pInput* parameter in a call to the [ApplyControlToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-applycontroltoken) function.