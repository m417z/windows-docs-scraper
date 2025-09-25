# IMiniportWavePciStream::SetFormat

## Description

The `SetFormat` method sets the KS data format of the wave stream.

## Parameters

### `DataFormat` [in]

Pointer to [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure that describes the new format of the stream.

## Return value

`SetFormat` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The wave stream's initial format is specified in the [IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream) call that creates the stream. Following stream creation, the `SetFormat` call can change the stream's format from its initial setting.

For information about specifying wave stream formats, see [Audio Data Formats and Data Ranges](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-data-formats-and-data-ranges).

## See also

[IMiniportWavePci::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepci-newstream)

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)