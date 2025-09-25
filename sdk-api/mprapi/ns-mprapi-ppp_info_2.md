# PPP_INFO_2 structure

## Description

The
**PPP_INFO_2** structure is used to report the results of the various Point-to-Point (PPP) projection operations for a connection.

## Members

### `nbf`

A
[PPP_NBFCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_nbfcp_info) structure that contains PPP NetBEUI Framer (NBF) projection information.

### `ip`

A
[PPP_IPCP_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ipcp_info2) structure that contains PPP Internet Protocol (IP) projection information.

### `ipx`

A
[PPP_IPXCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ipxcp_info) structure that contains PPP Internetwork Packet Exchange (IPX) projection information.

### `at`

A
[PPP_ATCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_atcp_info) structure that contains PPP AppleTalk projection information.

### `ccp`

A
[PPP_CCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_ccp_info) structure that contains Compression Control Protocol (CCP) projection information.

### `lcp`

A
[PPP_LCP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_lcp_info) structure that contains PPP Link Control Protocol (LCP) projection information.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[PPP_INFO_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info_3)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)