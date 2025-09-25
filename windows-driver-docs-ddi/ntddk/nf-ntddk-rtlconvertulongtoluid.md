# RtlConvertUlongToLuid function

## Description

The **RtlConvertUlongToLuid** routine converts an unsigned long integer to a locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)), which is used by the system to represent a security privilege.

## Parameters

### `Ulong` [in]

Specifies the unsigned long integer to convert.

## Return value

**RtlConvertUlongToLuid** returns the converted [LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid).

## Remarks

**RtlConvertUlongToLuid** is used to convert a system-defined privilege value, passed as a ULONG, to a locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) used by the system to represent that privilege. Drivers typically pass a LUID to **SeSinglePrivilegeCheck**.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[RtlConvertLongToLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlconvertlongtoluid)

[RtlEqualLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalluid)

[SeSinglePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-sesingleprivilegecheck)