# _NDIS_WWAN_AUTH_CHALLENGE structure

## Description

The NDIS_WWAN_AUTH_CHALLENGE structure represents an authentication challenge used by one of the authentication methods.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_AUTH_CHALLENGE structure. The
MB service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_AUTH_CHALLENGE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_AUTH_CHALLENGE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `AuthChallenge`

A formatted [WWAN_AUTH_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_challenge) object that represents the challenge posed by one of the authentication methods.

## See also

[WWAN_AUTH_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_challenge)