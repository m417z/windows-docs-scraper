# _WWAN_AUTH_METHOD enumeration

## Description

The WWAN_AUTH_METHOD enumeration lists supported authentication methods.

## Constants

### `WwanAuthSim`

Authenticate using the SIM method.

### `WwanAuthAka`

Authenticate using the AKA method.

### `WwanAuthAkaPrime`

Authenticate using the AKA' (AKA Prime) method.

### `WwanAuthMethodMax`

This value is reserved. Do not use.

## Remarks

The [WWAN_AUTH_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_challenge) and [WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_response) structures use this enumeration.

## See also

[WWAN_AUTH_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_challenge)

[WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_response)