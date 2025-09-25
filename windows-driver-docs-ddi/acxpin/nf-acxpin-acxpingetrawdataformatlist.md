## Description

The **AcxPinGetRawDataFormatList** function returns the raw mode data format list for the specified pin.

## Parameters

### `AcxPin`

The pin for which to get the data format list.

## Return value

Returns the [ACXDATAFORMATLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/) for the pin specified by *AcxPin*.

## Remarks

This DDI returns NULL if the specified pin doesn't have a raw mode data format list.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACXDATAFORMATLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)