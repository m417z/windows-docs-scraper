# _PIPE_TERMINATION structure

## Description

The **_PIPE_TERMINATION** structure is for proxy use and not recommended for application use. PIPE_TERMINATION contains information that describes the pin terminator of a pipe.

## Members

### `Flags`

### `OutsideFactors`

One of the factors (flags) defining the Pipes properties. The factors (flags) are defined in ksproxy.h as `PipeFactor_None` through `PipeFactor_LogicalEnd`.

### `Weigth`

The outside weight.

### `PhysicalRange`

A [KS_FRAMING_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_range) structure defining the physical range.

### `OptimalRange`

A [KS_FRAMING_RANGE_WEIGHTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_range_weighted) structure defining the optimal range.

### `Compression`

Relative to the connected pin on a neighboring filter.