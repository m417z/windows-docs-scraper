## Description

The **AcxDataFormatGetBlockAlign** function gets the block alignment of the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the block alignment.

## Return value

Returns a ULONG value containing the block alignment, in bytes, for the specified data format. The block alignment is the minimum atomic unit of data for the *DataFormat* type.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [WAVEFORMAT structure](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformat)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)