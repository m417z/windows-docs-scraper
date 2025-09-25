# SECURELOCKCODE enumeration

## Description

Deprecated. This enumeration is used by the [BASEBROWSERDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-basebrowserdatalh) structure to indicate the base browser's lock icon status.

## Constants

### `SECURELOCK_NOCHANGE:-1`

No change in security encryption status.

### `SECURELOCK_SET_UNSECURE:0`

There is no security encryption present.

### `SECURELOCK_SET_MIXED`

There are multiple security encryption methods present.

### `SECURELOCK_SET_SECUREUNKNOWNBIT`

The security encryption level is not known.

### `SECURELOCK_SET_SECURE40BIT`

There is 40-bit security encryption present.

### `SECURELOCK_SET_SECURE56BIT`

There is 56-bit security encryption present.

### `SECURELOCK_SET_FORTEZZA`

There is Fortezza security encryption present.

### `SECURELOCK_SET_SECURE128BIT`

There is 128-bit security encryption present.

### `SECURELOCK_FIRSTSUGGEST`

Suggest a security encryption setting.

### `SECURELOCK_SUGGEST_UNSECURE`

No security encryption has been suggested.

### `SECURELOCK_SUGGEST_MIXED`

Mixed security encryption methods have been suggested.

### `SECURELOCK_SUGGEST_SECUREUNKNOWNBIT`

An unknown security encryption method has been suggested.

### `SECURELOCK_SUGGEST_SECURE40BIT`

A 40-bit security encryption has been suggested.

### `SECURELOCK_SUGGEST_SECURE56BIT`

A 56-bit security encryption has been suggested.

### `SECURELOCK_SUGGEST_FORTEZZA`

A Fortezza security encryption has been suggested.

### `SECURELOCK_SUGGEST_SECURE128BIT`

A 128-bit security encryption has been suggested.