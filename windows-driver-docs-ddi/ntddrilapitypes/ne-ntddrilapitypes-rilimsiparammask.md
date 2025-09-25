# RILIMSIPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILIMSIPARAMMASK.

## Constants

### `RIL_PARAM_IMSI_IMSI`

### `RIL_PARAM_IMSI_MCC`

### `RIL_PARAM_IMSI_MNC`

### `RIL_PARAM_IMSI_ALL`

## Syntax

```cpp
enum RILIMSIPARAMMASK {
  RIL_PARAM_IMSI_IMSI  = 0x00000001,
  RIL_PARAM_IMSI_MCC   = 0x00000002,
  RIL_PARAM_IMSI_MNC   = 0x00000004,
  RIL_PARAM_IMSI_ALL   = 0x00000007

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))