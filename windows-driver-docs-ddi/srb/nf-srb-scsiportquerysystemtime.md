# ScsiPortQuerySystemTime function

## Description

The **ScsiPortQuerySystemTime** routine obtains the current system time.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `CurrentTime` [out]

Pointer to the current time, on return.

## Return value

None

## Remarks

The system time returned in *CurrentTime* is the number of 100-nanosecond intervals that have elapsed since January 1, 1601. System time is typically updated approximately every ten milliseconds. This value is computed for the GMT time zone.