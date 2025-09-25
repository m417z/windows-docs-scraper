# RILSYSTEMTYPE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration represents RILSYSTEMTYPE.

## Constants

### `RIL_SYSTEMTYPE_NONE`

### `RIL_SYSTEMTYPE_1XRTT`

### `RIL_SYSTEMTYPE_EVDO`

### `RIL_SYSTEMTYPE_GSM`

### `RIL_SYSTEMTYPE_UMTS`

### `RIL_SYSTEMTYPE_LTE`

### `RIL_SYSTEMTYPE_TDSCDMA`

### `RIL_SYSTEMTYPE_CDMA`

### `RIL_SYSTEMTYPE_GSMUMTS`

### `RIL_SYSTEMTYPE_GSMTDS`

### `RIL_SYSTEMTYPE_GSMUMTSTDS`

### `RIL_SYSTEMTYPE_3GPP`

### `RIL_SYSTEMTYPE_ALL`

## Syntax

```cpp
enum RILSYSTEMTYPE {
  RIL_SYSTEMTYPE_NONE     = 0x00000000,
  RIL_SYSTEMTYPE_1XRTT    = 0x00000001,
  RIL_SYSTEMTYPE_EVDO     = 0x00000002,
  RIL_SYSTEMTYPE_GSM      = 0x00000004,
  RIL_SYSTEMTYPE_UMTS     = 0x00000008,
  RIL_SYSTEMTYPE_LTE      = 0x00000010,
  RIL_SYSTEMTYPE_TDSCDMA  = 0x00000020,
  RIL_SYSTEMTYPE_CDMA     = RIL_SYSTEMTYPE_1XRTT | RIL_SYSTEMTYPE_EVDO,
  RIL_SYSTEMTYPE_GSMUMTS  = RIL_SYSTEMTYPE_GSM | RIL_SYSTEMTYPE_UMTS,
  RIL_SYSTEMTYPE_ALL      = 0x0000003F

};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))