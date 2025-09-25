# KeAreAllApcsDisabled function

## Description

The **KeAreAllApcsDisabled** routine indicates whether the calling thread is inside a guarded region or running at IRQL >= APC_LEVEL, which disables all APC delivery.

## Return value

**KeAreAllApcsDisabled** returns **TRUE** if the calling thread is inside a guarded region or running at IRQL >= APC_LEVEL, and **FALSE** otherwise.

## Remarks

A thread inside a guarded region or running at IRQL >= APC_LEVEL has all APCs disabled, including special kernel APCs.

## See also

[KeAreApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keareapcsdisabled)