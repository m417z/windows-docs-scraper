# SERVICE_ADDRESS structure

## Description

The
**SERVICE_ADDRESS** structure contains address information for a service. The structure can accommodate many types of interprocess communications (IPC) mechanisms and their address forms, including remote procedure calls (RPC), named pipes, and sockets.

## Members

### `dwAddressType`

Type: **DWORD**

The address family to which the socket address pointed to by **lpAddress** member belongs.

### `dwAddressFlags`

Type: **DWORD**

A set of bit flags that specify properties of the address. The following bit flags are defined.

| Value | Meaning |
| --- | --- |
| **SERVICE_ADDRESS_FLAG_RPC_CN** | If this bit flag is set, the service supports connection-oriented RPC over this transport protocol. |
| **SERVICE_ADDRESS_FLAG_RPC_DG** | If this bit flag is set, the service supports datagram-oriented RPC over this transport protocol. |
| **SERVICE_ADDRESS_FLAG_RPC_NB** | If this bit flag is set, the service supports NetBIOS RPC over this transport protocol. |

### `dwAddressLength`

Type: **DWORD**

The size, in bytes, of the address.

### `dwPrincipalLength`

Type: **DWORD**

Reserved for future use. Must be zero.

### `lpAddress.size_is`

### `lpAddress.size_is.dwAddressLength`

### `lpAddress`

Type: **BYTE***

A pointer to a socket address of the appropriate type.

### `lpPrincipal.size_is`

### `lpPrincipal.size_is.dwPrincipalLength`

### `lpPrincipal`

Type: **BYTE***

Reserved for future use. Must be **NULL**.

## See also

[SERVICE_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_addresses)

[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa)