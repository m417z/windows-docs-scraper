# KeEnterGuardedRegion function (ntddk.h)

## Description

The **KeEnterGuardedRegion** routine enters a guarded region, which disables all kernel-mode APC delivery to the current thread.

## Remarks

To exit a guarded region entered with **KeEnterGuardedRegion**, call the **KeLeaveGuardedRegion** routine. Guarded regions can be nested. APCs are not reenabled until the thread exits the outermost guarded region.

For more information about guarded regions, see [Critical Regions and Guarded Regions](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

## See also

[KeLeaveGuardedRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleaveguardedregion)