# RILADDRESSPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILADDRESSPARAMMASK enumeration.

## Constants

### `RIL_PARAM_A_NONE`

### `RIL_PARAM_A_TYPE`

### `RIL_PARAM_A_NUMPLAN`

### `RIL_PARAM_A_ADDRESS`

### `RIL_PARAM_A_ALL`

## Syntax

```cpp
enum RILADDRESSPARAMMASK {
  RIL_PARAM_A_NONE     = 0x00000000,
  RIL_PARAM_A_TYPE     = 0x00000001,
  RIL_PARAM_A_NUMPLAN  = 0x00000002,
  RIL_PARAM_A_ADDRESS  = 0x00000004,
  RIL_PARAM_A_ALL      = 0x00000007

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))