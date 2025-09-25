# RILEUTRAMRLPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILEUTRAMRLPARAMMASK.

## Constants

### `RIL_PARAM_EUTRAMRL_MCC`

### `RIL_PARAM_EUTRAMRL_MNC`

### `RIL_PARAM_EUTRAMRL_CELLID`

### `RIL_PARAM_EUTRAMRL_EARFCN`

### `RIL_PARAM_EUTRAMRL_PHYSCELLID`

### `RIL_PARAM_EUTRAMRL_TAC`

### `RIL_PARAM_EUTRAMRL_RSRP`

### `RIL_PARAM_EUTRAMRL_RSRQ`

### `RIL_PARAM_EUTRAMRL_ALL`

## Syntax

```cpp
enum RILEUTRAMRLPARAMMASK {
  RIL_PARAM_EUTRAMRL_MCC         = 0x00000001,
  RIL_PARAM_EUTRAMRL_MNC         = 0x00000002,
  RIL_PARAM_EUTRAMRL_CELLID      = 0x00000004,
  RIL_PARAM_EUTRAMRL_EARFCN      = 0x00000008,
  RIL_PARAM_EUTRAMRL_PHYSCELLID  = 0x00000010,
  RIL_PARAM_EUTRAMRL_TAC         = 0x00000020,
  RIL_PARAM_EUTRAMRL_RSRP        = 0x00000040,
  RIL_PARAM_EUTRAMRL_RSRQ        = 0x00000080,
  RIL_PARAM_EUTRAMRL_ALL         = 0x000000ff

};
```

## Remarks

Networks will vary, but the following table summarizes which items are returned for typical LTE networks.

**Serving network**

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | Yes | 0 through 999 |  |
| MobileNetworkCode | Yes | 0 through 999 |  |
| CellID | Yes | 0 through 268,435,455 | Global cell ID in the system information block; 28 bits |
| EARFCN | Yes | 0 through 65,535 | E-UTRA absolute radio frequency channel number of the serving cell |
| PhysCellID | Yes | 0 through 503 | LTE serving cell ID |
| TAC | Yes | 0 through 65,535 |  |
| RSRP | Yes | −44 through −140 | The current reference signal receive power in dBm |
| RSRQ | Yes | −3 through −20 | Measured in dB |

**LTE neighbors** (subject to availability from network)

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | No |  |  |
| MobileNetworkCode | No |  |  |
| CellID | No |  |  |
| EARFCN | Yes | 0 through 65,535 | E-UTRA absolute radio frequency channel number of the serving cell |
| PhysCellID | Yes | 0 through 503 | LTE serving cell ID |
| TAC | No |  |  |
| RSRP | Yes | −44 through −140 | The current reference signal receive power in dBm |
| RSRQ | Yes | −3 through −20 | Measured in dB |

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))