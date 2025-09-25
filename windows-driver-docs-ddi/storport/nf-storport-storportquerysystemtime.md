# StorPortQuerySystemTime function

## Description

The **StoriPortQuerySystemTime** routine obtains the current system time.

## Parameters

### `CurrentTime` [out]

Pointer to the current time, on return.

## Return value

None

## Remarks

The system time returned in *CurrentTime* is the number of 100-nanosecond intervals that have elapsed since January 1, 1601. System time is typically updated approximately every ten milliseconds. This value is computed for the GMT time zone.

## See also

[ScsiPortQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportquerysystemtime)