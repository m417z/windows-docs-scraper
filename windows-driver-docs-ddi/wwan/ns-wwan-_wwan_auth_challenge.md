# _WWAN_AUTH_CHALLENGE structure

## Description

The WWAN_AUTH_CHALLENGE structure represents an authentication challenge for a specific method.

## Members

### `AuthMethod`

The authentication challenge method.

### `u`

The container union for the different authentication challenge methods.

### `u.AuthSim`

The challenge that uses the SIM authentication method. If **AuthMethod** is set to *WwanAuthSim*, use this member.

### `u.AuthAka`

The challenge that uses the AKA authentication method. If **AuthMethod** is set to *WwanAuthAka*, use this member.

### `u.AuthAkap`

The challenge that uses the AKA' authentication method. If **AuthMethod** is set to *WwanAuthAkap,* use this member.

## See also

[WWAN_AUTH_AKAP_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_akap_challenge)

[WWAN_AUTH_AKA_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_aka_challenge)

[WWAN_AUTH_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_auth_method)

[WWAN_AUTH_SIM_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_sim_challenge)