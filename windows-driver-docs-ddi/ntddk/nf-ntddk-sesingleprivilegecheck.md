# SeSinglePrivilegeCheck function

## Description

The
**SeSinglePrivilegeCheck** routine checks for the passed privilege value in the context of the current thread.

## Parameters

### `PrivilegeValue` [in]

Specifies the [LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) value of the privilege being checked.

### `PreviousMode` [in]

Specifies the previous execution mode, one of **UserMode** or **KernelMode**.

## Return value

**SeSinglePrivilegeCheck** returns **TRUE** if the current subject has the required privilege.

## Remarks

If *PreviousMode* is **KernelMode**, the privilege check always succeeds. Otherwise, this routine uses the token of the user-mode thread to determine whether the current (user-mode) thread has been granted the given privilege.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[RtlConvertLongToLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlconvertlongtoluid)

[RtlConvertUlongToLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlconvertulongtoluid)

[RtlEqualLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalluid)

[SeValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-sevalidsecuritydescriptor)