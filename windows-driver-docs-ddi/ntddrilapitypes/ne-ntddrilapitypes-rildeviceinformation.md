# RILDEVICEINFORMATION enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILDEVICEINFORMATION.

## Constants

### `RIL_DEVICEINFO_MANUFACTURER`

### `RIL_DEVICEINFO_MODEL`

### `RIL_DEVICEINFO_REVISION`

### `RIL_DEVICEINFO_SERIALNUMBER_GW`

### `RIL_DEVICEINFO_SERIALNUMBER_CDMA`

### `RIL_DEVICEINFO_ARG_SMALLEST`

### `RIL_DEVICEINFO_ARG_LARGEST`

### `RIL_DEVICEINFO_MIN`

### `RIL_DEVICEINFO_MAX`

## Syntax

```cpp
enum RILDEVICEINFORMATION {
  RIL_DEVICEINFO_MANUFACTURER       = 0x01,
  RIL_DEVICEINFO_MODEL              = 0x02,
  RIL_DEVICEINFO_REVISION           = 0x03,
  RIL_DEVICEINFO_SERIALNUMBER_GW    = 0x04,
  RIL_DEVICEINFO_SERIALNUMBER_CDMA  = 0x05,
  RIL_DEVICEINFO_ARG_SMALLEST       = RIL_DEVICEINFO_MANUFACTURER,
  RIL_DEVICEINFO_ARG_LARGEST        = RIL_DEVICEINFO_SERIALNUMBER_CDMA

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))