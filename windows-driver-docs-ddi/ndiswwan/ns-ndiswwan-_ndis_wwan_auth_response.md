# _NDIS_WWAN_AUTH_RESPONSE structure

## Description

The NDIS_WWAN_AUTH_RESPONSE structure represents a response from one of the authentication methods.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_AUTH_RESPONSE structure. The
MB service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_AUTH_RESPONSE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_AUTH_RESPONSE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the response received for authentication challenge operation. The miniport driver returns one of the following WWAN_STATUS values as appropriate.

| WWAN_STATUS_VALUE | Description |
| --- | --- |
| WWAN_STATUS_AUTH_INCORRECT_AUTN | If the transmitted challenge has an incorrect AUTN, the response for the AKA and AKA' challenges will have this error code. This value applies only to the AKA and AKA' authentication methods. |
| WWAN_STATUS_AUTH_SYNC_FAILURE | If the transmitted challenge has a synchronization failure, the response for the AKA and AKA' challenges will have this error code and will have AUTS. This value applies only to the AKA and AKA' authentication methods. |
| WWAN_STATUS_AUTH_AMF_NOT_SET | If the transmitted challenge is not computed with the AMF separation bit set to 1, the response for AKA' should have this error code. This value applies only to the AKA' authentication method. |

### `AuthResponse`

A formatted [WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_response) object that represents the challenge posed by one of the authentication methods. This member (within WWAN_AUTH_RESPONSE) should be set even when **uStatus** is other than WWAN_STATUS_SUCCESS.

## Remarks

The [NDIS_STATUS_WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-auth-response) NDIS status notification uses this structure.

## See also

[NDIS_STATUS_WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-auth-response)

[WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_response)