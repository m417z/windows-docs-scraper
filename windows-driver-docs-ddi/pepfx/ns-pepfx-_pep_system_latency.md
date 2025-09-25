# _PEP_SYSTEM_LATENCY structure (pepfx.h)

## Description

The **PEP_SYSTEM_LATENCY** structure specifies the new value for the system latency tolerance.

## Members

### `Latency` [in]

The overall system latency tolerance, in 100-nanosecond units. This member specifies the maximum latency that the operating system can tolerate in the time required to move a component from a low-power F*x* state to F0.

## Remarks

This structure is used by the [PEP_DPM_SYSTEM_LATENCY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_system_latency) notification. The **Latency** member of the structure contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx).

## See also

[PEP_DPM_SYSTEM_LATENCY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_system_latency)