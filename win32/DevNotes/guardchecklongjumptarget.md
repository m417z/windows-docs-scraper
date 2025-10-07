# GuardCheckLongJumpTarget function

## Description

Attempts to verify whether the target of a [longjmp](https://learn.microsoft.com/cpp/c-runtime-library/reference/longjmp) is valid for a process which has [Control Flow Guard (CFG)](https://learn.microsoft.com/windows/win32/secbp/control-flow-guard) enabled.

If the target address corresponds to an image mapping, the valid targets are extracted for the binary.
The function uses those targets to validate the target.
If the binary does not have metadata that describes the set of valid *longjmp* targets, the function returns **TRUE**.

If the target address corresponds to a non-image mapping, as in JIT code, a global read-only policy is consulted to determine whether the jump is allowed.

## Parameters

### TargetAddress [in]

The target address for the jump.

### Flags [in]

Flags describing the operation to be performed on the address.
If you specify **GUARD_CHECK_LONGJUMP_NON_FATAL** (0x1), this function does not terminate the process if the target is invalid.

## Returns

**TRUE** if the target is valid, otherwise **FALSE**.

## Remarks

## See also