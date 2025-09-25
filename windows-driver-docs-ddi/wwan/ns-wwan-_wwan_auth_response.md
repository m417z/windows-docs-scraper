# _WWAN_AUTH_RESPONSE structure

## Description

The WWAN_AUTH_RESPONSE structure represents an authentication challenge response.

## Members

### `AuthMethod`

The authentication challenge method used.

### `u`

The container union for the different authentication challenge methods.

### `u.AuthSim`

The response from the SIM authentication method. If **AuthMethod** is set to *WwanAuthSim*, use this member.

### `u.AuthAka`

The response from the AKA authentication method. If **AuthMethod** is set to *WwanAuthAka,* use this member.

### `u.AuthAkap`

The response from the AKA' authentication method. If **AuthMethod** is set to *WwanAuthAkap,* use this member.

## Remarks

The [NDIS_WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_auth_response) structure uses this structure.

## See also

[NDIS_WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_auth_response)

[WWAN_AUTH_AKAP_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_akap_response)

[WWAN_AUTH_AKA_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_aka_response)

[WWAN_AUTH_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_auth_method)

[WWAN_AUTH_SIM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_sim_response)