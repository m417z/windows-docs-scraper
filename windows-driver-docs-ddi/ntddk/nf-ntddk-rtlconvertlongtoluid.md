# RtlConvertLongToLuid function

## Description

The **RtlConvertLongToLuid** routine converts a long integer to a locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)), which is used by the system to represent a security privilege.

## Parameters

### `Long` [in]

Specifies the long integer to convert.

## Return value

**RtlConvertLongToLuid** returns the converted [LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid).

## Remarks

**RtlConvertLongToLuid** is used to convert a system-defined privilege value to the locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) used by the system to represent that privilege. Drivers typically pass a LUID to **SeSinglePrivilegeCheck**, which is usually called by network transport drivers.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[RtlConvertUlongToLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlconvertulongtoluid)

[RtlEqualLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalluid)

[SeSinglePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-sesingleprivilegecheck)