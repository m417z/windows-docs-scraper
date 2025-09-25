# RasGetProjectionInfoEx function

## Description

The **RasGetProjectionInfoEx** function obtains information about Point-to-Point Protocol (PPP) or Internet Key Exchange version 2 (IKEv2) remote access projection operations for all RAS connections on the local client.

## Parameters

### `hrasconn` [in]

A handle to the RAS connection for which the tunnel endpoints are to be changed. This can be a handle returned by the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) function.

### `pRasProjection` [in, out]

A pointer to a [RAS_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-ras_projection_info) structure that receives the projection information for the RAS connections.

### `lpdwSize` [in, out]

A pointer, in input, that specifies the size, in bytes, of the buffer pointed to by pRasProjection. On output, this variable receives the size, in bytes, of the buffer needed to store the number of [RAS_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-ras_projection_info) structures pointed to by
*pRasProjection*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_TOO_SMALL** | The buffer pointed to by *pRasProjection* is not large enough to contain the requested information. |
| **ERROR_INVALID_HANDLE** | The *hrasconn* parameter is not a valid handle. |
| **ERROR_INVALID_PARAMETER** | The function was called with an invalid parameter. |
| **ERROR_INVALID_SIZE** | The *dwSize* member of the structure pointed to by *pRasProjection* specifies an invalid size. |
| **ERROR_PROTOCOL_NOT_CONFIGURED** | The control protocol for which information was requested neither succeeded nor failed, because the connection's phone-book entry did not require that an attempt to negotiate the protocol be made. |

## Remarks

Remote access projection is the process whereby a remote access server and a remote client negotiate network protocol-specific information. A remote access server uses this network protocol-specific information to represent a remote client on the network.

Remote access projection information is not available until the operating system has executed the [RASCS_Projected](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) state on the remote access connection. If
**RasGetProjectionInfoEx** is called prior to the **RASCS_Projected** state, it returns **ERROR_PROJECTION_NOT_COMPLETE**.

## See also

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)