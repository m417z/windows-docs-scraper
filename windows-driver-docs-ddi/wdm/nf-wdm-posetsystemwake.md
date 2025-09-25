# PoSetSystemWake function

## Description

The **PoSetSystemWake** routine marks the specified IRP as one that contributed to waking the system from a sleep state.

## Parameters

### `Irp` [in, out]

A pointer to the wait/wake IRP.

## Remarks

Drivers call **PoSetSystemWake** to mark an [IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake) IRP as contributing to waking the system from a sleep state. By default, wait/wake IRPs are considered to be device wake-up IRPs. It is the responsibility of the terminal device in a wait/wake chain to determine if it woke the system and to call **PoSetSystemWake** for the terminal wait/wake IRP. When a driver calls **PoSetSystemWake** on an IRP, it is marked as having contributed to waking the system from a sleep state. Only one driver in a stack needs to call this routine, and it should normally be the bus driver in a driver stack.

All other drivers in a wait/wake chain can call [PoGetSystemWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pogetsystemwake) for their own wait/wake IRPs at completion to determine if they should call **PoSetSystemWake** on any child wait/wake IRPs that they are about to complete. This ensures that system wake information properly progresses throughout the wait/wake chain.

After a wait/wake IRP completes, the power manager checks if the IRP is marked as a system wake IRP. If the IRP is marked as a system wake IRP, the power manager adds the IRP to an internal list of the devices that woke the system. However, the power manager only keeps track of the most specific devices that work the system. For example, if device A is added as a device that woke the system, and then device B—a child of device A—is also added, the power manager only retains device B in the list because device B is the most specific. If the power manager cannot determine the most specific device that woke the system, the power manager might keep track of more than one device that reported it woke the system.

The power manager logs an Event Tracing for Windows (ETW) event (viewable in the global system channel) that includes information about which devices woke the system.

## See also

[PoGetSystemWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pogetsystemwake)