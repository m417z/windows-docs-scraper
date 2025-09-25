# PPP_IPCP_INFO structure

## Description

The
**PPP_IPCP_INFO** structure contains the result of a PPP Internet Protocol (IP) negotiation.

## Members

### `dwError`

Specifies the result of the PPP control protocol negotiation. A value of zero indicates success. A nonzero value indicates failure, and is the actual fatal error that occurred during the control protocol negotiation.

### `wszAddress`

Specifies a Unicode string that holds the local computer's IP address for the connection. This string has the form *a***.***b***.***c***.***d*; for example, "10.102.235.84".

The
**PPP_IPCP_INFO** structures provides address information from the perspective of the server. For example, if a remote access client is connecting to a RAS server, this member holds the IP address of the server.

### `wszRemoteAddress`

Specifies a Unicode string that holds the IP address of the remote computer. This string has the form *a***.***b***.***c***.***d*. If the address is not available, this member is an empty string.

The
**PPP_IPCP_INFO** structures provides address information from the perspective of the server. For example, if a remote access client is connecting to a RAS server, this member holds the IP address of the client.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[PPP_IPCP_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ipcp_info2)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)