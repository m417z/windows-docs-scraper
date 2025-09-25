# _PEP_PPM_PARK_MASK structure (pep_x.h)

## Description

The **PEP_PROCESSOR_PARK_MASK** structure contains the current core parking mask.

## Members

### `Count` [in]

Indicates the number of processors in the **Processors** array.

### `EvaluationTime` [in]

The interrupt time of the performance check evaluation that initiated this notification.

### `Processors` [in/out]

An array of processors in the core parking domain.

#### On input

Indicates the OS parking preference for each processor.

#### On output

Returns the PEP parking preference for each processor.

The Processors array is guaranteed to contain the processors in increasing order by processor index.

##### - Processors.On input

Indicates the OS parking preference for each processor.

##### - Processors.On output

Returns the PEP parking preference for each processor.

## See also

[PEP_NOTIFY_PPM_PARK_MASK notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_PROCESSOR_PARK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_park_state)