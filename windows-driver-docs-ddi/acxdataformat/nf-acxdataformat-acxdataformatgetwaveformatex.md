## Description

The **AcxDataFormatGetWaveFormatEx** function gets the [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure associated with the specified data format.

## Parameters

### `DataFormat` [in]

The data format for which to retrieve the [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure.

## Return value

Returns a pointer to the [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure associated with the specified *DataFormat*.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)