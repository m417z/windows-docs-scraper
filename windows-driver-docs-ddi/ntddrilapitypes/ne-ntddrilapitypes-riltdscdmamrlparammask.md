# RILTDSCDMAMRLPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILTDSCDMAMRLPARAMMASK.

## Constants

### `RIL_PARAM_TDSCDMAMRL_MCC`

### `RIL_PARAM_TDSCDMAMRL_MNC`

### `RIL_PARAM_TDSCDMAMRL_LAC`

### `RIL_PARAM_TDSCDMAMRL_CELLID`

### `RIL_PARAM_TDSCDMAMRL_UARFCN`

### `RIL_PARAM_TDSCDMAMRL_CELLPARAM`

### `RIL_PARAM_TDSCDMAMRL_RSCP`

### `RIL_PARAM_TDSCDMAMRL_PATHLOSS`

### `RIL_PARAM_TDSCDMAMRL_ALL`

## Syntax

```cpp
enum RILTDSCDMAMRLPARAMMASK {
  RIL_PARAM_TDSCDMAMRL_MCC        = 0x00000001,
  RIL_PARAM_TDSCDMAMRL_MNC        = 0x00000002,
  RIL_PARAM_TDSCDMAMRL_LAC        = 0x00000004,
  RIL_PARAM_TDSCDMAMRL_CELLID     = 0x00000008,
  RIL_PARAM_TDSCDMAMRL_UARFCN     = 0x00000010,
  RIL_PARAM_TDSCDMAMRL_CELLPARAM  = 0x00000020,
  RIL_PARAM_TDSCDMAMRL_RSCP       = 0x00000040,
  RIL_PARAM_TDSCDMAMRL_PATHLOSS   = 0x00000080,
  RIL_PARAM_TDSCDMAMRL_ALL        = 0x000000ff

};
```

## Remarks

Networks will vary, but the following table summarizes which items are returned for typical TD-SCDMA networks.

**Serving network**

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | Yes | 0 through 999 |  |
| MobileNetworkCode | Yes | 0 through 999 |  |
| LocationAreaCode | Yes | 0 to 65535 |  |
| CellID | Yes | 0 through 268,435,455 | May not always be available; 28 bits |
| UARFCN | Yes | 0 through 16,383 | Channel number |
| CellParameterID | Yes | 0 through 127 |  |
| TimingAdvance | Yes | 0 through 8,191 | By standards, the maximum range is 96 chips (0 to 96x8) |
| RSCP | Yes | −25 through −128 | Received signal code power of serving cell in dBm |
| PathLoss | No | 46 through 158 | Path loss of serving cell in dBs |

**TD-SCDMA neighbors** (subject to availability from network)

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | No |  |  |
| MobileNetworkCode | No |  |  |
| LocationAreaCode | No |  |  |
| CellID | No |  |  |
| UARFCN | Yes | 0 through 16,383 | Channel number |
| CellParameterID | Yes | 0 through 127 |  |
| TimingAdvance | No |  |  |
| RSCP | Yes | −25 through −128 | Received signal code power of serving cell in dBm |
| PathLoss | No |  |  |

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))