# NET_FW_AUTHENTICATE_TYPE enumeration

## Description

The **NET_FW_AUTHENTICATE_TYPE** enumerated type specifies the type of authentication which must occur in order for traffic to be allowed..

## Constants

### `NET_FW_AUTHENTICATE_NONE:0`

No security check is performed.

### `NET_FW_AUTHENTICATE_NO_ENCAPSULATION`

The traffic is allowed if it is IPsec-protected with authentication and no encapsulation protection. This means that the peer is authenticated, but there is no integrity protection on the data.

### `NET_FW_AUTHENTICATE_WITH_INTEGRITY`

The traffic is allowed if it is IPsec-protected with authentication and integrity protection.

### `NET_FW_AUTHENTICATE_AND_NEGOTIATE_ENCRYPTION`

The traffic is allowed if its is IPsec-protected with authentication and integrity protection. In addition, negotiation of encryption protections on subsequent packets is requested.

### `NET_FW_AUTHENTICATE_AND_ENCRYPT`

The traffic is allowed if it is IPsec-protected with authentication, integrity and encryption protection since the very first packet.

## See also

[INetFwRule3::SecureFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwrule3-get_secureflags)