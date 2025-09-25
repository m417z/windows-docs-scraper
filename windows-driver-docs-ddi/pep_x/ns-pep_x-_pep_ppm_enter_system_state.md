# _PEP_PPM_ENTER_SYSTEM_STATE structure (pep_x.h)

## Description

Used in the **PEP_NOTIFY_PPM_ENTER_SYSTEM_STATE** notification to notify PEP that the system is about to enter a system power state.

## Members

### `TargetState`

On input, a [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)-type value that indicates the power state that the system is entering.

## Remarks

This notification is sent to all processors simultaneously after the system has completed all passive level work transitioning the processor to the system power state.
This notification is sent at DISPATCH_LEVEL, with all processors at dispatch. This notification is always executed on the target processor.
PEP must not queue any work from this notification. The processors will not process work items, DPCs, etc. after this notification has been sent.

## See also

[Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/)