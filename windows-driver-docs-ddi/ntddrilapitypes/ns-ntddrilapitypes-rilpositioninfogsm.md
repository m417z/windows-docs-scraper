# RILPOSITIONINFOGSM structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILPOSITIONINFOGSM.

## Members

### `dwParams`

A bitwise combination of [RILPOSITIONINFOGSMPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilpositioninfogsmparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwMobileCountryCode`

Mobile country code (0...999)

### `dwMobileNetworkCode`

Mobile Network Code (0...999)

### `dwLocationAreaCode`

Location Area Code (0…65535)

### `dwCellID`

Cell ID (0...65535)

### `dwTimingAdvance`

Timing Advance (0...255) in bit periods, where a bit period is 48/13µs

### `dwARFCN`

Absolute radio frequency channel number of serving cell (0...1023)

### `dwBaseStationID`

Radio base station ID of serving cell (0..63)

### `dwRxLevel`

Received signal strength of serving cell (0...63) where:

(x=0, RSS < -110dBm

x=63, RSS > -49dBm

0 <x <63, -110+x < RSS < -109+x)

## Syntax

```cpp
struct RILPOSITIONINFOGSM {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD dwMobileNetworkCode;
  DWORD dwLocationAreaCode;
  DWORD dwCellID;
  DWORD dwTimingAdvance;
  DWORD dwARFCN;
  DWORD dwBaseStationID;
  DWORD dwRxLevel;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))