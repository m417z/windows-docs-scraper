# RILPOSITIONINFOTDSCDMA structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `dwParams`

### `dwMobileCountryCode`

### `dwMobileNetworkCode`

### `dwLocationAreaCode`

### `dwCellID`

### `dwUARFCN`

### `dwCellParameterID`

### `dwTimingAdvance`

### `dwRSCP`

### `dwPathLoss`

## Syntax

```cpp
typedef struct _RILPOSITIONINFOTDSCDMA {
  DWORD  dwParams;
  DWORD  dwMobileCountryCode;
  DWORD  dwMobileNetworkCode;
  DWORD  dwLocationAreaCode;
  DWORD  dwCellID;
  DWORD  dwUARFCN;
  DWORD  dwCellParameterID;
  DWORD  dwTimingAdvance;
  DWORD  dwRSCP;
  DWORD  dwPathLoss;
} RILPOSITIONINFOTDSCDMA, RILPOSITIONINFOTDSCDMA;
```