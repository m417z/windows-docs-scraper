# RILGSMNMR structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILGSMNMR, which is a GSM network measurement report.

## Members

### `dwParams`

A bitwise combination of [RILGSMMNMRPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilgsmmnmrparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwMobileCountryCode`

Mobile country code (0...999)

### `dwMobileNetworkCode`

Mobile network code (0...999).

### `dwLocationAreaCode`

Location area code (0…65535)

### `dwCellID`

GSM Cell ID (0...65535)

### `dwARFCN`

Absolute radio frequency channel number of serving cell (0...1023)

### `dwBaseStationID`

Base station ID of serving cell (0..63)

### `dwRxLevel`

Received signal strength of serving cell (0...63) where:

(x=0, RSS < -110dBm

x=63, RSS > -49dBm

0 <x <63, -110+x < RSS < -109+x)

## Syntax

```cpp
struct RILGSMNMR {
  DWORD dwParams;
  DWORD dwMobileCountryCode;
  DWORD dwMobileNetworkCode;
  DWORD dwLocationAreaCode;
  DWORD dwCellID;
  DWORD dwARFCN;
  DWORD dwBaseStationID;
  DWORD dwRxLevel;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))