# RILPOSITIONINFOTDSCDMA structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents the RILPOSITIONINFOTDSCDMA.

## Members

### `dwParams`

A bitwise combination of [RILPOSITIONINFOTDSCDMAPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilpositioninfotdscdmaparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set

### `dwMobileCountryCode`

Mobile country code (0...999).

### `dwMobileNetworkCode`

Mobile Network Code (0...999).

### `dwLocationAreaCode`

Location Area Code (0...65535).

### `dwCellID`

Cell ID (0...268435455)).

### `dwUARFCN`

Channel number for serving cell (0...16383).

### `dwCellParameterID`

Cell parameter ID (0...127).

### `dwTimingAdvance`

Timing Advance (0...1023), same value for all timeslots.

### `dwRSCP`

Received signal code power of serving cell. Range (−128...−25) in units of 1dBm in Q8 L3 filtered.

### `dwPathLoss`

Path loss of serving cell (46...158).

## Syntax

```cpp
struct RILPOSITIONINFOTDSCDMA {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD dwMobileNetworkCode;
  DWORD dwLocationAreaCode;
  DWORD dwCellID;
  DWORD dwUARFCN;
  DWORD dwCellParameterID;
  DWORD dwTimingAdvance;
  LONG  dwRSCP;
  DWORD dwPathLoss;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))