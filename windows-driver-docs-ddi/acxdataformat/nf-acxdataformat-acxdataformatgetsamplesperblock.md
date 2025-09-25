## Description

The **AcxDataFormatGetSamplesPerBlock** function gets the number of samples per block for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the number of samples per block.

## Return value

Returns a ULONG value containing the number of samples per block for the specified *DataFormat*.

## Remarks

Number of samples contained in one compressed block of audio data. This value is used in buffer estimation. This value is used with compressed formats that have a fixed number of samples within each block. This value can be set to zero if a variable number of samples is contained in each block of compressed audio data. In this case, buffer estimation and position information needs to be obtained in other ways.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [WAVEFORMATEXTENSIBLE structure](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85))
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)