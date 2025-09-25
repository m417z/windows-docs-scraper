# KeAreApcsDisabled function (wdm.h)

## Description

The **KeAreApcsDisabled** routine returns whether the calling thread is within a critical region or a guarded region, which disables normal kernel APC delivery.

## Return value

**KeAreApcsDisabled** returns **TRUE** if the thread is within a critical region or a guarded region, and **FALSE** otherwise.

## Remarks

A thread running at IRQL = PASSIVE_LEVEL can use **KeAreApcsDisabled** to determine if normal kernel APCs are disabled. A thread that is inside a critical region has both user APCs and normal kernel APCs disabled, but not special kernel APCs. A thread that is inside a guarded region has all APCs disabled, including special kernel APCs.

## See also

[KeAreAllApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keareallapcsdisabled)

[KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)

[KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion)