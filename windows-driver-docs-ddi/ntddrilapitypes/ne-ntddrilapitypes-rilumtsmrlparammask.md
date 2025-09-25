# RILUMTSMRLPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUMTSMRLPARAMMASK.

## Constants

### `RIL_PARAM_UMTSMRL_MCC`

### `RIL_PARAM_UMTSMRL_MNC`

### `RIL_PARAM_UMTSMRL_LAC`

### `RIL_PARAM_UMTSMRL_CELLID`

### `RIL_PARAM_UMTSMRL_UARFCN`

### `RIL_PARAM_UMTSMRL_PRIMARY_SC`

### `RIL_PARAM_UMTSMRL_RSCP`

### `RIL_PARAM_UMTSMRL_ECNO`

### `RIL_PARAM_UMTSMRL_PATHLOSS`

### `RIL_PARAM_UMTSMRL_ALL`

## Syntax

```cpp
enum RILUMTSMRLPARAMMASK  {
  RIL_PARAM_UMTSMRL_MCC         = 0x00000001,
  RIL_PARAM_UMTSMRL_MNC         = 0x00000002,
  RIL_PARAM_UMTSMRL_LAC         = 0x00000004,
  RIL_PARAM_UMTSMRL_CELLID      = 0x00000008,
  RIL_PARAM_UMTSMRL_UARFCN      =  0x00000010,
  RIL_PARAM_UMTSMRL_PRIMARY_SC  =  0x00000020,
  RIL_PARAM_UMTSMRL_RSCP        = 0x00000040,
  RIL_PARAM_UMTSMRL_ECNO        = 0x00000080,
  RIL_PARAM_UMTSMRL_PATHLOSS    = 0x00000100,
  RIL_PARAM_UMTSMRL_ALL         = 0x000001ff

};
```

## Remarks

Networks will vary, but the following table summarizes which items are returned for common UMTS networks.

**Serving network**

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | Yes | 0 through 999 |  |
| MobileNetworkCode | Yes | 0 through 999 |  |
| LocationAreaCode | Yes | 0 through 65,535 |  |
| CellID | Yes | 0 through 268,435,455 | 28 bits; may not always be available |
| FrequencyInfoUL | No |  |  |
| FrequencyInfoDL | No |  |  |
| FrequencyInfoNT | No |  |  |
| UARFCN | Yes | 0 through 16,383 | UTRA absolute channel number |
| PrimaryScramblingCode | Yes | 0 through 511 |  |
| RSCP | Yes | −25 through −120 | Measured in dBm; defined in 25.304 |
| ECNO | Yes | 0 through −50 | Measured in dB |
| PathLoss | No |  |  |

**UMTS neighbors** (subject to availability from network)

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | No |  |  |
| MobileNetworkCode | No |  |  |
| LocationAreaCode | No |  |  |
| CellID | No |  | May not always be available; CellID may not be valid in DCH state |
| UARFCN | Yes | 0 through 16,383 | WCDMA layer frequency |
| PrimaryScramblingCode | Yes | 0 through 511 |  |
| RSCP | Yes | –25 through −120 | Measured in dBm; defined in 25.304 |
| ECNO | Yes | 0 through −50 | Measured in dB |
| PathLoss | No |  |  |

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))