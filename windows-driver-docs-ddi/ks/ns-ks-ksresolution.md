# KSRESOLUTION structure

## Description

The KSRESOLUTION structure specifies granularity and error of a kernel streaming clock.

## Members

### `Granularity`

Specifies the increment granularity of the clock in 100-nanosecond units, where 1 is the best.

### `Error`

Specifies the +/- notification error of the clock in 100-nanosecond units, where 0 is the best, meaning the event notification granularity is as good as the increment granularity.

## Remarks

Vendors can supply a structure of type KSRESOLUTION in a [KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution) property request.

## See also

[KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution)