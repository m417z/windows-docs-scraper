# RILREGSTAT enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILREGSTAT.

## Constants

### `RIL_REGSTAT_UNKNOWN`

### `RIL_REGSTAT_UNREGISTERED`

### `RIL_REGSTAT_HOME`

### `RIL_REGSTAT_ATTEMPTING`

### `RIL_REGSTAT_DENIED`

### `RIL_REGSTAT_ROAMING`

### `RIL_REGSTAT_ROAMING_DOMESTIC`

### `RIL_REGSTAT_MAX`

### `RIL_REGSTAT_ROAMING_INTL`

## Syntax

```cpp
enum RILREGSTAT  {
  RIL_REGSTAT_UNKNOWN       = 0x00000000,
  RIL_REGSTAT_UNREGISTERED  = 0x00000001,
  RIL_REGSTAT_HOME          = 0x00000002,
  RIL_REGSTAT_ATTEMPTING    = 0x00000003,
  RIL_REGSTAT_DENIED        = 0x00000004,
  RIL_REGSTAT_ROAMING       = 0x00000005,
  RIL_REGSTAT_ROAMING_INTL  = 0x00000006

};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))