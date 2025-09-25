# RILIMSI structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `wszImsi`

### `dwMcc`

### `dwMnc`

## Syntax

```cpp
typedef struct _RILIMSI {
  DWORD                  cbSize;
  DWORD                  dwParams;
  WCHAR [MAXLENGTH_IMSI] wszImsi;
  DWORD                  dwMcc;
  DWORD                  dwMnc;
} RILIMSI, RILIMSI;
```