# RILUICCFILELOCKSTATUS structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `dwAccessCondition`

### `bPinRef`

## Syntax

```cpp
typedef struct _RILUICCFILELOCKSTATUS {
  DWORD                                 cbSize;
  DWORD                                 dwParams;
  RILUICCFILELOCKSTATUSACCESSCONDITION  dwAccessCondition;
  BYTE [MAXNUM_PINREF]                  bPinRef;
} RILUICCFILELOCKSTATUS, RILUICCFILELOCKSTATUS;
```