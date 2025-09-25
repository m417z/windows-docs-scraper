## Description

The **AcxDataFormatGetKsDataFormat** function gets the kernel streaming data format for the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the kernel streaming format.

## Return value

Returns a pointer to the [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure associated with the specified *DataFormat*.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)