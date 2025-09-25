# RILADDRESS structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `dwType`

### `dwNumPlan`

### `wszAddress`

## Syntax

```cpp
typedef struct _RILADDRESS {
  DWORD                     cbSize;
  DWORD                     dwParams;
  RILADDRESSTYPE            dwType;
  RILADDRESSNUMPLAN         dwNumPlan;
  WCHAR [MAXLENGTH_ADDRESS] wszAddress;
} RILADDRESS, RILADDRESS;
```