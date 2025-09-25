## Description

The **AcxDataFormatIsEqual** function compares two [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) objects for equality.

## Parameters

### `DataFormat1` [in]

The first [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object to compare.

### `DataFormat2` [in]

The second [ACXDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) object to compare.

## Return value

Returns TRUE if *DataFormat1* and DataFormat2 are equal, otherwise FALSE.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)