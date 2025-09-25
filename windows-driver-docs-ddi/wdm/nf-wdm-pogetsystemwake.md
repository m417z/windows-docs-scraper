# PoGetSystemWake function

## Description

The **PoGetSystemWake** routine determines whether a specified IRP has been marked as waking the system from a sleeping state.

## Parameters

### `Irp` [in]

A pointer to an IRP.

## Return value

**PoGetSystemWake** returns one of the following:

| Return code | Description |
| --- | --- |
| ****TRUE**** | The specified IRP did cause the system to wake. |
| ****FALSE**** | The specified IRP did not cause the system to wake. |

## Remarks

A driver calls **PoGetSystemWake** to determine if a specified IRP contributed to waking the system from a sleep state.

A driver in a wait/wake chain should call **PoGetSystemWake** on its own wait/wake IRP at completion to determine if the driver should also call [PoSetSystemWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetsystemwake) for child wait/wake IRPs that the driver is about to complete. This ensures that system wake information properly propagates throughout the entire wait/wake chain.

It is possible that several IRPs are causing the system to wake. In this case, **PoGetSystemWake** would return **TRUE** for all of the IRPs contributing to the wake event.

## See also

[PoSetSystemWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetsystemwake)