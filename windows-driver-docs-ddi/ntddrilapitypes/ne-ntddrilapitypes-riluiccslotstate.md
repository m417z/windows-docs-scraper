# RILUICCSLOTSTATE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCSLOTSTATE.

## Constants

### `RIL_UICCSLOT_OFF_EMPTY`

### `RIL_UICCSLOT_OFF`

### `RIL_UICCSLOT_EMPTY`

### `RIL_UICCSLOT_NOT_READY`

### `RIL_UICCSLOT_ACTIVE`

### `RIL_UICCSLOT_ERROR`

### `RIL_UICCSLOT_MAX`

## Syntax

```cpp
enum RILUICCSLOTSTATE {
  RIL_UICCSLOT_OFF_EMPTY  = 0x01,
  RIL_UICCSLOT_OFF        = 0x02,
  RIL_UICCSLOT_EMPTY      = 0x03,
  RIL_UICCSLOT_NOT_READY  = 0x04,
  RIL_UICCSLOT_ACTIVE     = 0x05,
  RIL_UICCSLOT_ERROR      = 0x06

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))