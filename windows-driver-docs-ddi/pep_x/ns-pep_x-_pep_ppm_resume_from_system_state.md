# _PEP_PPM_RESUME_FROM_SYSTEM_STATE structure (pep_x.h)

## Description

Used by the **PEP_NOTIFY_PPM_RESUME_FROM_SYSTEM_STATE** notification that notifies the PEP that the system has just resumed from a system power state.

## Members

### `TargetState`

On input, a [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)-type value that indicates the power state that the system is entering.

## See also

[Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/)