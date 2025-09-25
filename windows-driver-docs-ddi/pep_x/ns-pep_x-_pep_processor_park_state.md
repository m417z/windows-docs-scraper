# _PEP_PROCESSOR_PARK_STATE structure (pep_x.h)

## Description

The **PEP_PROCESSOR_PARK_STATE** structure describes the parking state for a single processor.

## Members

### `Processor`

Specifies the **PEPHANDLE** associated with this processor.

### `Parked`

Specifies whether or not this processor is parked.

### `Reserved`

This member is reserved and should be set to zero.

## See also

[PEP_NOTIFY_PPM_PARK_MASK notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_PPM_PARK_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_park_mask)