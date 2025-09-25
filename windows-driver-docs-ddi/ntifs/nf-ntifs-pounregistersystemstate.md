# PoUnregisterSystemState function (ntifs.h)

## Description

The **PoUnregisterSystemState** routine cancels a system state registration created by [PoRegisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregistersystemstate).

## Parameters

### `StateHandle` [in, out]

A pointer to a handle previously returned by **PoRegisterSystemState**.

## Remarks

This routine cancels a system busy state registration established by **PoRegisterSystemState** and frees the associated *StateHandle*.

## See also

[PoRegisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregistersystemstate)