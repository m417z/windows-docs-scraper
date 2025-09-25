# RILPOSITIONINFOGSM structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `dwParams`

### `dwMobileCountryCode`

### `dwMobileNetworkCode`

### `dwLocationAreaCode`

### `dwCellID`

### `dwTimingAdvance`

### `dwARFCN`

### `dwBaseStationID`

### `dwRxLevel`

## Syntax

```cpp
typedef struct _RILPOSITIONINFOGSM {
  DWORD  dwParams;
  DWORD  dwMobileCountryCode;
  DWORD  dwMobileNetworkCode;
  DWORD  dwLocationAreaCode;
  DWORD  dwCellID;
  DWORD  dwTimingAdvance;
  DWORD  dwARFCN;
  DWORD  dwBaseStationID;
  DWORD  dwRxLevel;
} RILPOSITIONINFOGSM, RILPOSITIONINFOGSM;
```