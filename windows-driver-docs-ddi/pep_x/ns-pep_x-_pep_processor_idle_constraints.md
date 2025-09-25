# _PEP_PROCESSOR_IDLE_CONSTRAINTS structure

## Description

The **PEP_PROCESSOR_IDLE_CONSTRAINTS** structure specifies a set of constraints that the PEP uses to select a processor idle state.

## Members

### `IdleDuration`

The length of time, in 100-nanosecond units, for which the processor is expected to stay in the selected idle state. This is the operating system's current best estimate and might vary over time without further notification.

### `Interruptible`

Whether the processor must be able to respond to interrupts in the selected idle state. A value of TRUE indicates that the processor must be interruptible in this idle state. A value of FALSE indicates that the processor is not required to be interruptible in this idle state.

### `Type`

A [PEP_PROCESSOR_IDLE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ne-pep_x-pep_processor_idle_type) enumeration value that indicates whether these idle constraints apply to just the current processor (**Type** = **PepIdleTypeProcessor**) or to all processors in the hardware platform (**Type** = **PepIdleTypePlatform**).

## Remarks

The **Constraints** member of the [PEP_PPM_IDLE_SELECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_select) structure is a pointer to a **PEP_PROCESSOR_IDLE_CONSTRAINTS** structure.

## See also

[PEP_PPM_IDLE_SELECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_select)

[PEP_PROCESSOR_IDLE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ne-pep_x-pep_processor_idle_type)