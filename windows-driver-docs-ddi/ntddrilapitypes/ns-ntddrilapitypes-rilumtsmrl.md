# RILUMTSMRL structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a RILUMTSMRL.

## Members

### `dwParams`

 A bitwise combination of [RILUMTSMRLPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilumtsmrlparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwMobileCountryCode`

Country code (0...999)

### `dwMobileNetworkCode`

Mobile network code (0...999)

### `dwLocationAreaCode`

Location area code (0...65535)

### `dwCellID`

UMTS cell ID (0...268435455)

### `dwUARFCN`

UTRA absolute radio frequency channel number (0...16383)

### `dwPrimaryScramblingCode`

Primary Scrambling Code (0...511)

### `dwRSCP`

Received signal code power of serving cell. Range (-1200 ... -250) in units of 0.1dBm, i.e., -250 represents -25dBm.

### `dwECNO`

Signal to noise ratio of serving cell; the ratio of the received energy per PN chip for the CPICH to the total received power spectral density at the antenna. Range (-500...0) in units of 0.1dBm.

### `dwPathLoss`

Path loss.

## Syntax

```cpp
struct RILUMTSMRL {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD  dwMobileNetworkCode;
  DWORD dwLocationAreaCode;
  DWORD dwCellID;
  DWORD dwUARFCN;
  DWORD dwPrimaryScramblingCode;
  LONG  dwRSCP;
  LONG  dwECNO;
  DWORD dwPathLoss;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))