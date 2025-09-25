# RILEUTRAMRL structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILEUTRAMRL, which is a EUTRA (LTE) network measurement report.

## Members

### `dwParams`

A bitwise combination of [RILEUTRAMRLPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rileutramrlparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwMobileCountryCode`

Mobile country code (0...999)

### `dwMobileNetworkCode`

Mobile Network Code (0...999)

### `dwCellID`

Cell identity (28 bits).

### `dwEARFCN`

EUTRA absolute radio frequency channel number (0...65535).

### `dwPhysCellID`

Physical cell ID (0...503).

### `dwTAC`

Tracking area code (0...65535).

### `dwRSRP`

Average reference signal received power (–1400 ... –440) in units of 0.1dBm.

### `dwRSRQ`

Average reference signal received quality (–200 ... –30) in units of 0.1dBm.

## Syntax

```cpp
struct RILEUTRAMRL {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD dwMobileNetworkCode;
  DWORD dwCellID;
  DWORD dwEARFCN;
  DWORD dwPhysCellID;
  DWORD dwTAC;
  DWORD dwRSRP;
  DWORD dwRSRQ;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))