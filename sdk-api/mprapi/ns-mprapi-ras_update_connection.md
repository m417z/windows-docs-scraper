# RAS_UPDATE_CONNECTION structure

## Description

The [RAS_UPDATE_CONNECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd408110(v=vs.85)) structure is used to update an active RAS connection.

## Members

### `Header`

A [MPRAPI_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_object_header) structure that specifies the version of the [RAS_UPDATE_CONNECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd408110(v=vs.85)) structure.

**Note** The **revision** member of **Header** must be **0x01** and **type** must be **MPRAPI_OBJECT_TYPE_UPDATE_CONNECTION_OBJECT**.

### `dwIfIndex`

A value that specifies the new interface index of the Virtual Private Network (VPN) endpoint.

### `wszLocalEndpointAddress`

A null-terminated Unicode string that contains the new IP address of the local computer in the connection. This string is of the form "a.b.c.d".

### `wszRemoteEndpointAddress`

A null-terminated Unicode string that contains the new IP address of the remote computer in the connection. This string is of the form "a.b.d.c".

## See also

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)