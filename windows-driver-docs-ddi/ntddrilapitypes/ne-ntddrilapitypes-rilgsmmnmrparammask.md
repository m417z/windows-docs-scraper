# RILGSMMNMRPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILGSMMNMRPARAMMASK.

## Constants

### `RIL_PARAM_GSMNMR_MCC`

### `RIL_PARAM_GSMNMR_MNC`

### `RIL_PARAM_GSMNMR_LAC`

### `RIL_PARAM_GSMNMR_CELLID`

### `RIL_PARAM_GSMNMR_ARFCN`

### `RIL_PARAM_GSMNMR_BSID`

### `RIL_PARAM_GSMNMR_RXLEVEL`

### `RIL_PARAM_GSMNMR_ALL`

## Syntax

```cpp
enum RILGSMMNMRPARAMMASK {
  RIL_PARAM_GSMNMR_MCC      = 0x00000001,
  RIL_PARAM_GSMNMR_MNC      = 0x00000002,
  RIL_PARAM_GSMNMR_LAC      = 0x00000004,
  RIL_PARAM_GSMNMR_CELLID   = 0x00000008,
  RIL_PARAM_GSMNMR_ARFCN    = 0x00000010,
  RIL_PARAM_GSMNMR_BSID     = 0x00000020,
  RIL_PARAM_GSMNMR_RXLEVEL  = 0x00000040,
  RIL_PARAM_GSMNMR_ALL      = 0x0000007f

};
```

## Remarks

In most situations both serving and neighbor cell sites will return all of these values.

**Serving network**

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | Yes | 0 through 999 |  |
| MobileNetworkCode | Yes | 0 through 999 |  |
| LocationAreaCode | Yes | 0 through 65,535 |  |
| CellID | Yes | 0 through 268,435,455 | 28 bits; may not always be available |
| ARFCN | Yes | 0 through 1,023 | Absolute RF channel number |
| BaseStationID | Yes | 0 through 63 | Base station identity code ID (BSIC ID), including bcc and ncc; lower 6 bits can be set to any value |
| RxLevel | Yes | 0 through 63 | Serving cell Rx measurement; range is mapped to a measured signal level:<br><br>• RxLevel 0 is a signal strength less than −110 dBm<br><br>• RxLevel 1 is −110 dBm to −109 dBm<br><br>• RxLevel 2 is −109 dBm to −108 dBm<br><br>• ...<br><br>• RxLevel 62 is −49 dBm to −48 dBm<br><br>• RxLevel 63 is greater than −48 dBm |

**GSM neighbors** (subject to availability from network)

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | Yes | 0 through 999 |  |
| MobileNetworkCode | Yes | 0 through 999 |  |
| LocationAreaCode | Yes | 0 through 65,535 |  |
| CellID | Yes | 0 through 268,435,455 | May not be available always; MCC/MNC/LAC should be ignored if Cell ID is not valid |
| ARFCN | Yes | 0 through 1,023 |  |
| BaseStationID | Yes | 0 through 63 | Base station identity code is not available for neighbor cells at all times; it can be set to an invalid number |
| RxLevel | Yes | 0 through 63 | Same as RxLevel in serving cell |

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))