# RILNETWORKCODEPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILNETWORKCODEPARAMMASK.

## Constants

### `RIL_PARAM_NETWORKCODE_EXECUTOR`

### `RIL_PARAM_NETWORKCODE_MCC`

### `RIL_PARAM_NETWORKCODE_MNC`

### `RIL_PARAM_NETWORKCODE_SID`

### `RIL_PARAM_NETWORKCODE_NID`

### `RIL_PARAM_NETWORKCODE_RI`

### `RIL_PARAM_NETWORKCODE_ALL`

## Syntax

```cpp
enum RILNETWORKCODEPARAMMASK {
  RIL_PARAM_NETWORKCODE_EXECUTOR  = 0x00000001,
  RIL_PARAM_NETWORKCODE_MCC       = 0x00000002,
  RIL_PARAM_NETWORKCODE_MNC       = 0x00000004,
  RIL_PARAM_NETWORKCODE_SID       = 0x00000008,
  RIL_PARAM_NETWORKCODE_NID       = 0x00000010,
  RIL_PARAM_NETWORKCODE_RI        = 0x00000020,
  RIL_PARAM_NETWORKCODE_ALL       = 0x0000003F

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))