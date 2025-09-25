# RILPOSITIONINFOUMTS structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a RILPOSITIONINFOUMTS.

## Members

### `dwParams`

A bitwise combination of [RILPOSITIONINFOUMTSPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilpositioninfoumtsparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwMobileCountryCode`

Mobile country code (0...999).

### `dwMobileNetworkCode`

Mobile Network Code (0...999).

### `dwLocationAreaCode`

Location Area Code (0...65535).

### `dwCellID`

Cell ID (0...268435455)).

### `dwFrequencyInfoUL`

Channel number for serving cell (0...16383).

### `dwFrequencyInfoDL`

Frequency Info Downlink (0...16383)

### `dwFrequencyInfoNT`

Frequency Info for TDD (0...16383)

### `dwUARFCN`

UTRA Absolute Radio Frequency Channel Number for serving cell (0...16383)

### `dwPrimaryScramblingCode`

Primary scrambling code of serving cell (0...511)

### `dwRSCP`

Received signal code power of serving cell. Range (-1200 ... -250) in units of .1dBm, i.e., -250 represents -25dBm.

### `dwECNO`

Signal to noise ratio of serving cell; the ratio of the received energy per PN chip for the CPICH to the total received power spectral density at the antenna. Range (-500…0) in units of 0.1dBm.

### `dwPathLoss`

Path loss of serving cell (46...173)

## Syntax

```cpp
struct RILPOSITIONINFOUMTS {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD dwMobileNetworkCode;
  DWORD dwLocationAreaCode;
  DWORD dwCellID;
  DWORD dwFrequencyInfoUL;
  DWORD dwFrequencyInfoDL;
  DWORD dwFrequencyInfoNT;
  DWORD dwUARFCN;
  DWORD dwPrimaryScramblingCode;
  DWORD dwRSCP;
  DWORD dwECNO;
  DWORD dwPathLoss;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))