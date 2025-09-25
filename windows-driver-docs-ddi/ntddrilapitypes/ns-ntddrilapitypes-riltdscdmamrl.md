# RILTDSCDMAMRL structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILTDSCDMAMRL, which is a TD_SCDMA network measurement report.

## Members

### `dwParams`

A bitwise combination of [RILTDSCDMAMRLPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riltdscdmamrlparammask) that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwMobileCountryCode`

(Reserved for future use) Mobile country code (0...999).

### `dwMobileNetworkCode`

(Reserved for future use) Mobile Network Code (0...999).

### `dwLocationAreaCode`

(Reserved for future use) Location Area Code (0...65535).

### `dwCellID`

(Reserved for future use) Cell identity 28 bits (0...268435455).

### `dwUARFCN`

Channel number (0...16383).

### `dwCellParameterID`

Cell parameter ID (0...127).

### `dwRSCP`

Received signal code power of serving cell. Range −128...−25 in units of 1dBm in Q8 L3 filtered.

### `dwPathLoss`

Path loss of serving cell (46...173)

## Syntax

```cpp
struct RILTDSCDMAMRL {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD dwMobileNetworkCode;
  DWORD dwLocationAreaCode;
  DWORD dwCellID;
  DWORD dwUARFCN;
  DWORD dwCellParameterID;
  DWORD dwRSCP;
  DWORD dwPathLoss;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))