## Description

The **AcxDataFormatGetSpecifier** function gets the audio format specifier for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the audio format specifier.

## Return value

Returns a GUID value representing the audio format specifier for the *DataFormat*.

## Remarks

Specifies additional data format type information for a specific setting of MajorFormat and SubFormat. The significance of this field is determined by the major format and subformat. For example, the specifier can represent a particular encoding of a subformat, or it can be used to specify what type of data structure follows [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) in memory.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [Audio Data Formats](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-data-formats)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)