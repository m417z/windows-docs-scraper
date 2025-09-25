# RILSUBSCRIBERINFOPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILSUBSCRIBERINFOPARAMMASK.

## Constants

### `RIL_PARAM_SI_ADDRESS`

### `RIL_PARAM_SI_DESCRIPTION`

### `RIL_PARAM_SI_SERVICE`

### `RIL_PARAM_SI_ALL`

## Syntax

```cpp
enum RILSUBSCRIBERINFOPARAMMASK {
  RIL_PARAM_SI_ADDRESS      = 0x00000001,
  RIL_PARAM_SI_DESCRIPTION  = 0x00000002,
  RIL_PARAM_SI_SERVICE      = 0x00000004,
  RIL_PARAM_SI_ALL          = 0x00000007

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))