# PPP_IPXCP_INFO structure

## Description

The
**PPP_IPXCP_INFO** structure contains the result of a PPP Internetwork Packet Exchange (IPX) projection operation.

## Members

### `dwError`

Specifies the result of the PPP control protocol negotiation. A value of zero indicates success. A nonzero value indicates failure, and is the actual fatal error that occurred during the control protocol negotiation.

### `wszAddress`

Specifies a Unicode string that holds the client's IPX address on the RAS connection. This address string has the form *net***.***node*, for example, "1234ABCD.12AB34CD56EF".

## Remarks

The
**PPP_IPXCP_INFO** structure can be used only when administrating computers that are running 32-bit Windows Server 2003 or an earlier operating system. Windows 2000 64-bit Edition does not support the IPX protocol.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)