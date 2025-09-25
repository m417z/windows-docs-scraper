# RILPOSITIONINFOUMTSPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILPOSITIONINFOUMTSPARAMMASK.

## Constants

### `RIL_PARAM_POSITION_UMTS_MCC`

### `RIL_PARAM_POSITION_UMTS_MNC`

### `RIL_PARAM_POSITION_UMTS_LAC`

### `RIL_PARAM_POSITION_UMTS_CELLID`

### `RIL_PARAM_POSITION_UMTS_FREQINFO_UL`

### `RIL_PARAM_POSITION_UMTS_FREQINFO_DL`

### `RIL_PARAM_POSITION_UMTS_FREQINFO_NT`

### `RIL_PARAM_POSITION_UMTS_UARFCN`

### `RIL_PARAM_POSITION_UMTS_PRIMARY_SC`

### `RIL_PARAM_POSITION_UMTS_RSCP`

### `RIL_PARAM_POSITION_UMTS_ECNO`

### `RIL_PARAM_POSITION_UMTS_PATHLOSS`

### `RIL_PARAM_POSITION_UMTS_ALL`

## Syntax

```cpp
enum RILPOSITIONINFOUMTSPARAMMASK {
  RIL_PARAM_POSITION_UMTS_MCC          = 0x00000001,
  RIL_PARAM_POSITION_UMTS_MNC          = 0x00000002,
  RIL_PARAM_POSITION_UMTS_LAC          = 0x00000004,
  RIL_PARAM_POSITION_UMTS_CELLID       = 0x00000008,
  RIL_PARAM_POSITION_UMTS_FREQINFO_UL  = 0x00000010,
  RIL_PARAM_POSITION_UMTS_FREQINFO_DL  = 0x00000020,
  RIL_PARAM_POSITION_UMTS_FREQINFO_NT  = 0x00000040,
   RIL_PARAM_POSITION_UMTS_UARFCN      = 0x00000080,
  RIL_PARAM_POSITION_UMTS_PRIMARY_SC   = 0x00000100,
  RIL_PARAM_POSITION_UMTS_RSCP         = 0x00000200,
  RIL_PARAM_POSITION_UMTS_ECNO         = 0x00000400,
  RIL_PARAM_POSITION_UMTS_PATHLOSS     = 0x00000800,
  RIL_PARAM_POSITION_UMTS_ALL          = 0x00000fff

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