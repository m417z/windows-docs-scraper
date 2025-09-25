# PROJECTION_INFO structure

## Description

The **PROJECTION_INFO** structure is used in the [RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structure as a placeholder for the [PPP_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_projection_info) and [IKEV2_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_projection_info) structures.

## Members

### `projectionInfoType`

A value that specifies if the projection is for a Point-to-Point (PPP) or an Internet Key Exchange version 2 (IKEv2) based tunnel. The following values are supported:

| Value | Meaning |
| --- | --- |
| **MPRAPI_PPP_PROJECTION_INFO_TYPE** | Data is a [PPP_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_projection_info) structure. |
| **MPRAPI_IKEV2_PROJECTION_INFO_TYPE** | Data is a [IKEV2_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_projection_info) structure. |

### `PppProjectionInfo`

A [PPP_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_projection_info) structure that is used for a PPP based tunnel.

### `Ikev2ProjectionInfo`

A [IKEV2_PROJECTION_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_projection_info) structure that is used for an IKEv2 based tunnel.

## See also

[RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)