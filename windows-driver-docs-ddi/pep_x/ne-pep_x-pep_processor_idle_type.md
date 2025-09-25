# PEP_PROCESSOR_IDLE_TYPE enumeration

## Description

The **PEP_PROCESSOR_IDLE_TYPE** enumeration indicates whether idle constraints apply to just the current processor or to all processors in the hardware platform.

## Constants

### `PepIdleTypeProcessor`

Apply to current processor.

### `PepIdleTypePlatform`

Apply to all processors.

### `PepIdleTypeMax`

Reserved for use by operating system.

## Remarks

The **Type** member of the [PEP_PROCESSOR_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_processor_idle_constraints) structure is a **PEP_PROCESSOR_IDLE_TYPE** enumeration value.

## See also

[PEP_PROCESSOR_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_processor_idle_constraints)