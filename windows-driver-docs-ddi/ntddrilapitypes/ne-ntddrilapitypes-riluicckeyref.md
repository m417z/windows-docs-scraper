# RILUICCKEYREF enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCAPPTYPE.

## Constants

### `RIL_UICCKEYREF_ALW`

### `RIL_UICCKEYREF_PIN1`

### `RIL_UICCKEYREF_UPIN`

### `RIL_UICCKEYREF_PIN2`

### `RIL_UICCKEYREF_NEV`

## Syntax

```cpp
enum RILUICCKEYREF {
  RIL_UICCKEYREF_ALW   = 0x00,
  RIL_UICCKEYREF_PIN1  = 0x01,
  RIL_UICCKEYREF_UPIN  = 0x10,
  RIL_UICCKEYREF_PIN2  = 0x81,
  RIL_UICCKEYREF_NEV   = 0xff

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))