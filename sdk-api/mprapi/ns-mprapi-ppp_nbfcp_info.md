# PPP_NBFCP_INFO structure

## Description

The
**PPP_NBFCP_INFO** structure contains the result of a PPP NetBEUI Framer (NBF) projection operation.

## Members

### `dwError`

Specifies the result of the PPP control protocol negotiation. A value of zero indicates success. A nonzero value indicates failure, and is the actual fatal error that occurred during the control protocol negotiation.

### `wszWksta`

Specifies a Unicode string that is the local workstation's computer name. This unique computer name is the closest NetBIOS equivalent to a client's NetBEUI address on a remote access connection.

## Remarks

The
**PPP_NBFCP_INFO** structure can be used only when administrating computers that are running an operating system prior to Windows Server 2003 as later operating systems do not support the NetBEUI protocol.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)