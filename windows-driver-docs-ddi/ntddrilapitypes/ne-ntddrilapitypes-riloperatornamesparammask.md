# RILOPERATORNAMESPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILOPERATORNAMESPARAMMASK.

## Constants

### `RIL_PARAM_ON_LONGNAME`

### `RIL_PARAM_ON_SHORTNAME`

### `RIL_PARAM_ON_NUMNAME`

### `RIL_PARAM_ON_COUNTRY_CODE`

### `RIL_PARAM_ON_SYSTEMTYPE`

### `RIL_PARAM_ON_ALL`

## Syntax

```cpp
enum RILOPERATORNAMESPARAMMASK {
  RIL_PARAM_ON_LONGNAME      = 0x00000001,
  RIL_PARAM_ON_SHORTNAME     = 0x00000002,
  RIL_PARAM_ON_NUMNAME       = 0x00000004,
  RIL_PARAM_ON_COUNTRY_CODE  = 0x00000008,
  RIL_PARAM_ON_SYSTEMTYPE    = 0x00000010,
  RIL_PARAM_ON_ALL           = 0x0000001F

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))