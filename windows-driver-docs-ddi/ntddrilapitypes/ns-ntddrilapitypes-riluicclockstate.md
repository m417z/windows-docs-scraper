# RILUICCLOCKSTATE structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a RILUICCLOCKSTATE.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILUICCLOCKSTATEPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riluicclockstateparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `rilUiccLock`

Specifies the lock of type [RILUICCLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-riluicclock).

### `dwLockState`

The current state of the lock, a bitmask of [RILUICCLOCKSTATELOCKSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riluicclockstatelockstate).

### `dwVerifyAttemptsLeft`

The number of verification attempts that remain before the lock is blocked.

### `dwUnblockAttemptsLeft`

The number of unblock attempts that remain before the lock is permanently blocked.

## Syntax

```cpp
struct RILUICCLOCKSTATE {
  DWORD       cbSize;
  DWORD       dwParams;
  RILUICCLOCK rilUiccLock;
  DWORD       dwLockState;
  DWORD       dwVerifyAttemptsLeft;
  DWORD       dwUnblockAttemptsLeft;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))