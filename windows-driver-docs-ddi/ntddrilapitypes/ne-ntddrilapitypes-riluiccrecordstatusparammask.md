# RILUICCRECORDSTATUSPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCRECORDSTATUSPARAMMASK.

## Constants

### `RIL_PARAM_URS_RECORDTYPE`

### `RIL_PARAM_URS_ITEMCOUNT`

### `RIL_PARAM_URS_SIZE`

### `RIL_PARAM_URS_FILELOCKSTATUS`

### `RIL_PARAM_URS_ALL`

## Syntax

```cpp
enum RILUICCRECORDSTATUSPARAMMASK {
  RIL_PARAM_URS_RECORDTYPE      = 0x00000001,
  RIL_PARAM_URS_ITEMCOUNT       = 0x00000002,
  RIL_PARAM_URS_SIZE            = 0x00000004,
  RIL_PARAM_URS_FILELOCKSTATUS  = 0x00000008,
  RIL_PARAM_URS_ALL             = 0x0000000F

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))