# AUTH_VALIDATION_EX structure

## Description

The **AUTH_VALIDATION_EX** structure is used for enabling clients to bypass Point-to-Point (PPP) authentication during Secure Socket Tunneling Protocol (SSTP) connection establishment.

## Members

### `Header`

A [MPRAPI_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_object_header) structure that specifies the version of the **AUTH_VALIDATION_EX** structure.

**Note** The **revision** member of **Header** must be **0x01** and **type** must be **MPRAPI_OBJECT_TYPE_AUTH_VALIDATION_OBJECT**.

### `hRasConnection`

A handle to the RAS connection for which PPP authentication is being bypassed. This can be a handle returned by the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) function.

### `wszUserName`

A null-terminated Unicode string that contains the name of the user logging on to the connection.

### `wszLogonDomain`

A null-terminated Unicode string that contains the domain on which the connected user is authenticating.

### `AuthInfoSize`

The size, in bytes, of the user authentication information in **AuthInfo**.

### `AuthInfo`

A **BYTE** array that contains the user authentication information required to bypass PPP authentication during SSTP connection negotiation.

## See also

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)