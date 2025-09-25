# RILPOSITIONINFOLTE structure (rilapitypes.h)

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

### `dwTimingAdvance`

## Syntax

```cpp
typedef struct _RILPOSITIONINFOLTE {
  DWORD  dwParams;
  DWORD  dwMobileCountryCode;
  DWORD  dwMobileNetworkCode;
  DWORD  dwCellID;
  DWORD  dwEARFCN;
  DWORD  dwPhysCellID;
  DWORD  dwTAC;
  LONG   dwRSRP;
  LONG   dwRSRQ;
  DWORD  dwTimingAdvance;
} RILPOSITIONINFOLTE, RILPOSITIONINFOLTE;
```