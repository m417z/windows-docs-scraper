# RILIMSSYSTEMTYPE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

The RILIMSSYSTEMTYPE enumeration has the following values.

## Constants

### `RIL_IMSSYSTEMTYPE_UNKNOWN`

### `RIL_IMSSYSTEMTYPE_WIFI`

### `RIL_IMSSYSTEMTYPE_LTE`

### `RIL_IMSSYSTEMTYPE_MAX`

## Syntax

```cpp
enum RILIMSSYSTEMTYPE {
  RIL_IMSSYSTEMTYPE_UNKNOWN  = 0x00000000,
  RIL_IMSSYSTEMTYPE_WIFI     = 0x00000001,
  RIL_IMSSYSTEMTYPE_LTE      = 0x00000002,
  RIL_IMSSYSTEMTYPE_MAX      = RIL_IMSSYSTEMTYPE_LTE

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))