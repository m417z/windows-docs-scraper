# PPP_INFO_3 structure

## Description

The
**PPP_INFO_3** structure is used to report the results of the various Point-to-Point (PPP) projection operations for a connection.

## Members

### `nbf`

A
[PPP_NBFCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_nbfcp_info) structure that contains PPP NetBEUI Framer (NBF) projection information.

### `ip`

A
[PPP_IPCP_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ipcp_info2) structure that contains PPP Internet Protocol (IP) projection information.

### `ipv6`

A
[PPP_IPV6_CP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ipv6_cp_info) structure that contains IPv6 control protocol projection information.

### `ccp`

A
[PPP_CCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ccp_info) structure that contains Compression Control Protocol (CCP) projection information.

### `lcp`

A
[PPP_LCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_lcp_info) structure that contains PPP Link Control Protocol (LCP) projection information.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[PPP_INFO_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info_2)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)