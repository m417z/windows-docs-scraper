# MPR_TRANSPORT_0 structure

## Description

The
**MPR_TRANSPORT_0** structure contains information for a particular transport.

## Members

### `dwTransportId`

A **DWORD** value that identifies the transport protocol type. Supported transport protocol types are listed on [Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers).

### `hTransport`

Handle to the transport.

### `wszTransportName`

A Unicode string that contains the name of the transport.

## See also

[MPR_IFTRANSPORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_iftransport_0)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)