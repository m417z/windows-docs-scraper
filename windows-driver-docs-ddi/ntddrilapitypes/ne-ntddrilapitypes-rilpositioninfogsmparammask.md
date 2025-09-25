# RILPOSITIONINFOGSMPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILPOSITIONINFOGSMPARAMMASK.

## Constants

### `RIL_PARAM_POSITION_GSM_MCC`

### `RIL_PARAM_POSITION_GSM_MNC`

### `RIL_PARAM_POSITION_GSM_LAC`

### `RIL_PARAM_POSITION_GSM_CELLID`

### `RIL_PARAM_POSITION_GSM_TA`

### `RIL_PARAM_POSITION_GSM_ARFCN`

### `RIL_PARAM_POSITION_GSM_BSID`

### `RIL_PARAM_POSITION_GSM_RXLEVEL`

### `RIL_PARAM_POSITION_GSM_ALL`

## Syntax

```cpp
enum RILPOSITIONINFOGSMPARAMMASK {
  RIL_PARAM_POSITION_GSM_MCC      = 0x00000001,
  RIL_PARAM_POSITION_GSM_MNC      = 0x00000002,
  RIL_PARAM_POSITION_GSM_LAC      = 0x00000004,
  RIL_PARAM_POSITION_GSM_CELLID   = 0x00000008,
  RIL_PARAM_POSITION_GSM_TA       = 0x00000010,
  RIL_PARAM_POSITION_GSM_ARFCN    = 0x00000020,
  RIL_PARAM_POSITION_GSM_BSID     = 0x00000040,
  RIL_PARAM_POSITION_GSM_RXLEVEL  = 0x00000080,
  RIL_PARAM_POSITION_GSM_ALL      = 0x000000ff

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))