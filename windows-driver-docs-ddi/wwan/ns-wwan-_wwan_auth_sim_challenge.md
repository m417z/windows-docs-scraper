# _WWAN_AUTH_SIM_CHALLENGE structure

## Description

The WWAN_AUTH_SIM_CHALLENGE structure represents an authentication challenge using the SIM method.

## Members

### `n`

The number of random number challenges.

### `Rand1`

The first 128-bit random number challenge value. This member represents a multi-byte value in little-endian format.

### `Rand2`

The second 128-bit random number challenge value. This member represents a multi-byte value in little-endian format.

### `Rand3`

The third 128-bit random number challenge value. This member represents a multi-byte value in little-endian format.

## Remarks

The **n** member can be either **2** or **3**, according to RFC 4186. If it is set to **2**, use the **Rand1** and **Rand2** members. If it is set to **3**, then the **Rand1**, **Rand2**, and **Rand3** members.

The [WWAN_AUTH_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_challenge) structure uses this structure.

## See also

[WWAN_AUTH_CHALLENGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_challenge)