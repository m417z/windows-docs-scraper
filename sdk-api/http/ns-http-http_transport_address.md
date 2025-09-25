# HTTP_TRANSPORT_ADDRESS structure

## Description

The
**HTTP_TRANSPORT_ADDRESS** structure specifies the addresses (local and remote) used for a particular HTTP connection.

## Members

### `pRemoteAddress`

A pointer to the remote IP address associated with this connection. For more information about how to access this address, see the Remarks section.

### `pLocalAddress`

A pointer to the local IP address associated with this connection. For more information about how to access this address, see the Remarks section.

## Remarks

Although the **pRemoteAddress** and **pLocalAddress** members are formally declared as **PSOCKADDR**, they are in fact **PSOCKADDR_IN** or **PSOCKADDR_IN6** types. Inspect the **sa_family** member, which is the same in all three structures, to determine how to access the address. If **sa_family** is equal to AF_INET, then the address is in IPv4 form and can be accessed by casting the members to **PSOCKADDR_IN**, but if **sa_family** equals AF_INET6, the address is in IPv6 form and you must cast them to **PSOCKADDR_IN6** before accessing the address. Both **pLocalAddress** and **pRemoteAddress** are always of the same type; that is they are either both of type **PSOCKADDR_IN** or both of type **PSOCKADDR_IN6**.

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))