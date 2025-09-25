# RILTDSCDMAMRL structure (rilapitypes.h)

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

### `dwRSCP`

### `dwPathLoss`

## Syntax

```cpp
typedef struct _RILTDSCDMAMRL {
  DWORD  dwParams;
  DWORD  dwMobileCountryCode;
  DWORD  dwMobileNetworkCode;
  DWORD  dwLocationAreaCode;
  DWORD  dwCellID;
  DWORD  dwUARFCN;
  DWORD  dwCellParameterID;
  DWORD  dwRSCP;
  DWORD  dwPathLoss;
} RILTDSCDMAMRL, RILTDSCDMAMRL;
```