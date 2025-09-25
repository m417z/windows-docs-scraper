## Description

The **AcxDataFormatGetAverageBytesPerSec** function gets the required bytes-per-second transfer rate for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the required bytes-per-second transfer rate.

## Return value

Returns a ULONG value containing the required bytes-per-second transfer rate for the specified *DataFormat*.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [WAVEFORMAT structure](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)