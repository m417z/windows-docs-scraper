## Description

The **AcxDataFormatGetEncodedAverageBytesPerSec** function gets the required bytes-per-second transfer rate for the specified encoded data format.

## Parameters

### `DataFormat` [in]

The encoded data format for which to retrieve the required bytes-per-second transfer rate.

## Return value

Returns a ULONG value that contains the required bytes-per-second transfer rate for the specified *DataFormat*.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [Representing Formats for IEC 61937 Transmissions](https://learn.microsoft.com/windows/win32/coreaudio/representing-formats-for-iec-61937-transmissions)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)