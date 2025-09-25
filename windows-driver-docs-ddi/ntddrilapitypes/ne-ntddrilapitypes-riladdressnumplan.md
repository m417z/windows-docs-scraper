# RILADDRESSNUMPLAN enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILADDRESSNUMPLAN.

## Constants

### `RIL_NUMPLAN_UNKNOWN`

### `RIL_NUMPLAN_TELEPHONE`

### `RIL_NUMPLAN_DATA`

### `RIL_NUMPLAN_TELEX`

### `RIL_NUMPLAN_NATIONAL`

### `RIL_NUMPLAN_PRIVATE`

### `RIL_NUMPLAN_ERMES`

### `RIL_NUMPLAN_MAX`

## Syntax

```cpp
enum RILADDRESSNUMPLAN {
  RIL_NUMPLAN_UNKNOWN    = 0x00000000,
  RIL_NUMPLAN_TELEPHONE  = 0x00000001,
  RIL_NUMPLAN_DATA       = 0x00000002,
  RIL_NUMPLAN_TELEX      = 0x00000003,
  RIL_NUMPLAN_NATIONAL   = 0x00000004,
  RIL_NUMPLAN_PRIVATE    = 0x00000005,
  RIL_NUMPLAN_ERMES      = 0x00000006

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))