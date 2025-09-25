# RILPOSITIONINFOLTE structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents the RILPOSITIONINFOLTE.

## Members

### `dwParams`

A bitwise combination of [RILPOSITIONINFOLTEPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilpositioninfolteparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwMobileCountryCode`

Mobile country code (0...999)

### `dwMobileNetworkCode`

Mobile Network Code (0...999)

### `dwCellID`

Cell identity (28 bits)

### `dwEARFCN`

Radio Frequency Channel Number of serving cell (0...65535)

### `dwPhysCellID`

Physical CellID (0...503)

### `dwTAC`

Tracking area code (0...65535)

### `dwRSRP`

Average Reference Signal Received Power. Range (-1400 ... -440) in units of 0.1dBm.

### `dwRSRQ`

Average Reference Signal Received Quality. Range (-200 ... -30) in units of 0.1dBm.

### `dwTimingAdvance`

Timing Advance (0...255) in bit periods, where a bit period is 48/13µs

## Syntax

```cpp
struct RILPOSITIONINFOLTE {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD dwMobileNetworkCode;
  DWORD dwCellID;
  DWORD dwEARFCN;
  DWORD dwPhysCellID;
  DWORD dwTAC;
  DWORD dwRSRP;
  DWORD dwRSRQ;
  DWORD dwTimingAdvance;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))