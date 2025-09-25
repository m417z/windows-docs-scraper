# RILUICCLOCKSTATEPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCLOCKSTATEPARAMMASK.

## Constants

### `RIL_PARAM_UICCLOCKSTATE_UICCLOCK`

### `RIL_PARAM_UICCLOCKSTATE_LOCKSTATE`

### `RIL_PARAM_UICCLOCKSTATE_VERIFYATTEMPTSLEFT`

### `RIL_PARAM_UICCLOCKSTATE_UNBLOCKATTEMPTSLEFT`

### `RIL_PARAM_UICCLOCKSTATE_ALL`

## Syntax

```cpp
enum RILUICCLOCKSTATEPARAMMASK {
  RIL_PARAM_UICCLOCKSTATE_UICCLOCK             = 0x00000001,
  RIL_PARAM_UICCLOCKSTATE_LOCKSTATE            = 0x00000002,
  RIL_PARAM_UICCLOCKSTATE_VERIFYATTEMPTSLEFT   = 0x00000004,
  RIL_PARAM_UICCLOCKSTATE_UNBLOCKATTEMPTSLEFT  = 0x00000008,
  RIL_PARAM_UICCLOCKSTATE_ALL                  = 0x0000000F

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))