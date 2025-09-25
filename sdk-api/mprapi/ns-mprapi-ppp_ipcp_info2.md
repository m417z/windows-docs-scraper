# PPP_IPCP_INFO2 structure

## Description

The
**PPP_IPCP_INFO2** structure contains the result of a PPP Internet Protocol (IP) negotiation.

## Members

### `dwError`

Specifies the result of the PPP control protocol negotiation. A value of zero indicates success. A nonzero value indicates failure, and is the actual fatal error that occurred during the control protocol negotiation.

### `wszAddress`

Specifies a Unicode string that holds the local computer's IP address for the connection. This string has the form *a***.***b***.***c***.***d*; for example, "10.102.235.84".

The
**PPP_IPCP_INFO2** structures provides address information from the perspective of the server. For example, if a remote access client is connecting to a RAS server, this member holds the IP address of the server.

### `wszRemoteAddress`

Specifies a Unicode string that holds the IP address of the remote computer. This string has the form *a***.***b***.***c***.***d*. If the address is not available, this member specifies an empty string.

The
**PPP_IPCP_INFO2** structures provides address information from the perspective of the server. For example, if a remote access client is connecting to a RAS server, this member holds the IP address of the client.

### `dwOptions`

Specifies IPCP options for the local computer. Currently, the only option is PPP_IPCP_VJ. This option indicates that IP datagrams sent by the local computer are compressed using Van Jacobson compression.

### `dwRemoteOptions`

Specifies IPCP options for the remote peer. Currently, the only option is PPP_IPCP_VJ. This option indicates that IP datagrams sent by the remote peer (that is, received by the local computer) are compressed using Van Jacobson compression.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[PPP_IPCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ipcp_info)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)