# RILPOSITIONINFOUMTS structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `dwParams`

### `dwMobileCountryCode`

### `dwMobileNetworkCode`

### `dwLocationAreaCode`

### `dwCellID`

### `dwFrequencyInfoUL`

### `dwFrequencyInfoDL`

### `dwFrequencyInfoNT`

### `dwUARFCN`

### `dwPrimaryScramblingCode`

### `dwRSCP`

### `dwECNO`

### `dwPathLoss`

## Syntax

```cpp
typedef struct _RILPOSITIONINFOUMTS {
  DWORD  dwParams;
  DWORD  dwMobileCountryCode;
  DWORD  dwMobileNetworkCode;
  DWORD  dwLocationAreaCode;
  DWORD  dwCellID;
  DWORD  dwFrequencyInfoUL;
  DWORD  dwFrequencyInfoDL;
  DWORD  dwFrequencyInfoNT;
  DWORD  dwUARFCN;
  DWORD  dwPrimaryScramblingCode;
  LONG   dwRSCP;
  LONG   dwECNO;
  DWORD  dwPathLoss;
} RILPOSITIONINFOUMTS, RILPOSITIONINFOUMTS;
```