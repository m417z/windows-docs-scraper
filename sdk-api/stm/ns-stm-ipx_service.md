# IPX_SERVICE structure

## Description

The
**IPX_SERVICE** structure contains information about an IPX service, and identifies the interface and protocol through which this information was obtained.

## Members

### `InterfaceIndex`

Contains the index of the interface through which the service information was obtained.

### `Protocol`

Contains the identifier of the protocol that obtained the service information. Static services are viewed as services obtained through the IPX_PROTOCOL_STATIC protocol.

### `Server`

#### - Service

Specifies an
[IPX_SERVER_ENTRY](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_server_entry) structure.

## See also

[IPX Service Table Management](https://learn.microsoft.com/windows/desktop/RRAS/ipx-service-table-management)

[IPX_SERVER_ENTRY](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-ipx_server_entry)

[Service Table Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/service-table-management-structures)