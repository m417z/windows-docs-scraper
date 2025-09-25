# KeLeaveGuardedRegion function (ntddk.h)

## Description

The **KeLeaveGuardedRegion** routine exits a guarded region entered by **KeEnterGuardedRegion**.

## Remarks

Guarded regions can be nested, so APCs are only reenabled once the thread exists the outermost guarded region.

For more information about guarded regions, see [Critical Regions and Guarded Regions](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

## See also

[KeEnterGuardedRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keenterguardedregion)