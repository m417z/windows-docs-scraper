# RILUICCLOCKSTATELOCKSTATE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCLOCKSTATELOCKSTATE.

## Constants

### `RIL_UICCLOCKSTATE_NONE`

None of the other state bits are set.

### `RIL_UICCLOCKSTATE_VERIFIED`

Lock is verified.

### `RIL_UICCLOCKSTATE_ENABLED`

Lock is enabled.

### `RIL_UICCLOCKSTATE_BLOCKED`

Lock is blocked.

### `RIL_UICCLOCKSTATE_ALL`

## Syntax

```cpp
enum RILUICCLOCKSTATELOCKSTATE {
  RIL_UICCLOCKSTATE_NONE = 0,
  RIL_UICCLOCKSTATE_VERIFIED = 0x1,
  RIL_UICCLOCKSTATE_ENABLED = 0x2,
  RIL_UICCLOCKSTATE_BLOCKED = 0x4,
  RIL_UICCLOCKSTATE_ALL = 0x7
};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))