# RILUICCFILELOCKSTATUSPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCFILELOCKSTATUSPARAMMASK.

## Constants

### `RIL_PARAM_UFLS_ACCESSCONDITION`

### `RIL_PARAM_UFLS_PINREFERENCE`

### `RIL_PARAM_UFLS_ALL`

## Syntax

```cpp
enum RILUICCFILELOCKSTATUSPARAMMASK {
  RIL_PARAM_UFLS_ACCESSCONDITION  = 0x00000001,
  RIL_PARAM_UFLS_PINREFERENCE     = 0x00000002,
  RIL_PARAM_UFLS_ALL              = 0x00000003

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))