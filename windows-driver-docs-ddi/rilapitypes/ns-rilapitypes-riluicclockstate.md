# RILUICCLOCKSTATE structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `rilUiccLock`

### `dwLockState`

### `dwVerifyAttemptsLeft`

### `dwUnblockAttemptsLeft`

## Syntax

```cpp
typedef struct _RILUICCLOCKSTATE {
  DWORD        cbSize;
  DWORD        dwParams;
  RILUICCLOCK  rilUiccLock;
  DWORD        dwLockState;
  DWORD        dwVerifyAttemptsLeft;
  DWORD        dwUnblockAttemptsLeft;
} RILUICCLOCKSTATE, RILUICCLOCKSTATE;
```