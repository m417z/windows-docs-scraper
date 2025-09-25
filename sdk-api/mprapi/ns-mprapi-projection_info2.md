# PROJECTION_INFO2 structure

## Description

Used in the [RAS_CONNECTION_4](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_4) structure as a placeholder for the [PPP_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_projection_info2) and [IKEV2_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_projection_info2) structures.

## Members

### `projectionInfoType`

A value that specifies if the projection is for a Point-to-Point (PPP) or an Internet Key Exchange version 2 (IKEv2) based tunnel. The following values are supported.

| Value | Meaning |
| --- | --- |
| **MPRAPI_PPP_PROJECTION_INFO_TYPE** | The data is a [PPP_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_projection_info2) structure. |
| **MPRAPI_IKEV2_PROJECTION_INFO_TYPE** | The data is a [IKEV2_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_projection_info2) structure. |

### `PppProjectionInfo`

A [PPP_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_projection_info2) structure that is used for a PPP based tunnel.

### `Ikev2ProjectionInfo`

A [IKEV2_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_projection_info2) structure that is used for an IKEv2 based tunnel.