# RILUICCRECORDTYPE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCRECORDTYPE.

## Constants

### `RIL_UICCRECORDTYPE_UNKNOWN`

### `RIL_UICCRECORDTYPE_TRANSPARENT`

### `RIL_UICCRECORDTYPE_CYCLIC`

### `RIL_UICCRECORDTYPE_LINEAR`

### `RIL_UICCRECORDTYPE_BERTLV`

### `RIL_UICCRECORDTYPE_MASTER`

### `RIL_UICCRECORDTYPE_DEDICATED`

### `RIL_UICCRECORDTYPE_MAX`

## Syntax

```cpp
enum RILUICCRECORDTYPE {
  RIL_UICCRECORDTYPE_UNKNOWN      = 0x00000000,
  RIL_UICCRECORDTYPE_TRANSPARENT  = 0x00000001,
  RIL_UICCRECORDTYPE_CYCLIC       = 0x00000002,
  RIL_UICCRECORDTYPE_LINEAR       = 0x00000003,
  RIL_UICCRECORDTYPE_BERTLV       = 0x00000004,
  RIL_UICCRECORDTYPE_MASTER       = 0x00000005

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))