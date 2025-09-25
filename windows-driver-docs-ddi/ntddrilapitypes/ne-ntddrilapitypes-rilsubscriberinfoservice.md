# RILSUBSCRIBERINFOSERVICE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILSUBSCRIBERINFOSERVICE.

## Constants

### `RIL_SERVICE_UNKNOWN`

### `RIL_SERVICE_VOICE`

### `RIL_SERVICE_FAX`

### `RIL_SERVICE_OTHER`

### `RIL_SERVICE_MAX`

## Syntax

```cpp
enum RILSUBSCRIBERINFOSERVICE {
  RIL_SERVICE_UNKNOWN  = 0x01,
  RIL_SERVICE_VOICE    = 0x02,
  RIL_SERVICE_FAX      = 0x03,
  RIL_SERVICE_OTHER    = 0x04

};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))