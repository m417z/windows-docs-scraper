# _WWAN_AUTH_SIM_RESPONSE structure

## Description

The WWAN_AUTH_SIM_RESPONSE structure represents a response to a SIM authentication challenge.

## Members

### `n`

The number of responses.

### `Kc1`

Encryption key 1 of 64 bit. This member represents a multi-byte value in little-endian format.

### `Kc2`

Encryption key 2 of 64 bit. This member represents a multi-byte value in little-endian format.

### `Kc3`

Encryption key 3 of 64 bit. This member represents a multi-byte value in little-endian format.

### `Sres1`

Response 1 of 32 bit. This member represents a multi-byte value in little-endian format.

### `Sres2`

Response 2 of 32 bit. This member represents a multi-byte value in little-endian format.

### `Sres3`

Response 3 of 32 bit. This member represents a multi-byte value in little-endian format.

## Remarks

The **n** member can be either **2** or **3**, according to RFC 4186. If it is set to **2**, use the **Sres1**/**Kc1** and **Sres2**/**Kc2** members. If it is set to **3**,use **Sres1**/**Kc1**, **Sres2**/**Kc2**, and **Sres3**/**Kc3** members.

The [WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_response) structure uses this structure.

## See also

[WWAN_AUTH_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_auth_response)