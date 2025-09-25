# RILNETWORKCODE structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `dwExecutor`

### `dwMCC`

### `dwMNC`

### `dwSID`

### `dwNID`

### `dwRI`

## Syntax

```cpp
typedef struct _RILNETWORKCODE {
  DWORD  cbSize;
  DWORD  dwParams;
  DWORD  dwExecutor;
  DWORD  dwMCC;
  DWORD  dwMNC;
  DWORD  dwSID;
  DWORD  dwNID;
  DWORD  dwRI;
} RILNETWORKCODE, RILNETWORKCODE;
```