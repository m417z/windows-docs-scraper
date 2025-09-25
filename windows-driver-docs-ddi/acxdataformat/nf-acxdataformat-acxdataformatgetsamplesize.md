## Description

The **AcxDataFormatGetSampleSize** function gets the sample size for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the sample size.

## Return value

Returns a ULONG value containing the sample size for the specified *DataFormat*.

## Remarks

Specifies the sample size of the data, for fixed sample sizes, or zero, if the format has a variable sample size.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)