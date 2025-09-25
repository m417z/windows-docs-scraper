# IMiniportWaveRTStream::SetFormat

## Description

The SetFormat method sets the data format of the wave stream.

## Parameters

### `DataFormat` [in]

Pointer to a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure that describes the requested data format.

## Return value

The following table shows the possible return status codes.

| Return code | Description |
|-------------|-------------|
| STATUS_SUCCESS | The call was successful|
| STATUS_INVALID_PARAMETER| The specified format is either not valid or not supported by the driver, or the format cannot be changed while the stream is running. |

## Remarks

None

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)