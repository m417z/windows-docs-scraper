# RILEUTRAMRL structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `dwParams`

### `dwMobileCountryCode`

### `dwMobileNetworkCode`

### `dwCellID`

### `dwEARFCN`

### `dwPhysCellID`

### `dwTAC`

### `dwRSRP`

### `dwRSRQ`

## Syntax

```cpp
typedef struct _RILEUTRAMRL {
  DWORD  dwParams;
  DWORD  dwMobileCountryCode;
  DWORD  dwMobileNetworkCode;
  DWORD  dwCellID;
  DWORD  dwEARFCN;
  DWORD  dwPhysCellID;
  DWORD  dwTAC;
  LONG   dwRSRP;
  LONG   dwRSRQ;
} RILEUTRAMRL, RILEUTRAMRL;
```