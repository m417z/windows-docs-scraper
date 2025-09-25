# IMasterClock::GetTime

## Description

The `GetTime` method retrieves the current reference time read from the master clock.

## Parameters

### `pTime` [out]

Output pointer for the reference time. This parameter points to a caller-allocated variable into which the method writes the reference time. Reference time is measured in 100-nanosecond units.

## Return value

`GetTime` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## See also

[IMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imasterclock)

[IMiniportDMus::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iminiportdmus-newstream)