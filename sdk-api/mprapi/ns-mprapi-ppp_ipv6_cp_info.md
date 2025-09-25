# PPP_IPV6_CP_INFO structure

## Description

The **PPP_IPV6_CP_INFO** structure contains the result of an IPv6 control protocol negotiation.

## Members

### `dwVersion`

The version of the **PPP_IPV6_CP_INFO** structure used.

### `dwSize`

The size, in bytes, of this **PPP_IPV6_CP_INFO** structure.

### `dwError`

Specifies the result of the PPP control protocol negotiation. A value of zero indicates success. A nonzero value indicates failure, and is the actual fatal error that occurred during the control protocol negotiation.

### `bInterfaceIdentifier`

Specifies the 64 bit interface identifier of the IPv6 server interface.

### `bRemoteInterfaceIdentifier`

Specifies the 64 bit interface identifier of the IPv6 client interface.

### `dwOptions`

Reserved. Must be set to 0.

### `dwRemoteOptions`

Reserved. Must be set to 0.

### `bPrefix`

Specifies the address prefix of the IPv6 client interface.

### `dwPrefixLength`

The length, in bits, of the address prefix.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)