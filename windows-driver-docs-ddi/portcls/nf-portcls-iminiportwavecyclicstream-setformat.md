# IMiniportWaveCyclicStream::SetFormat

## Description

The `SetFormat` method sets the KS data format of the wave stream.

## Parameters

### `DataFormat` [in]

Specifies the new format of the stream. This parameter is a pointer to a structure of type [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat).

## Return value

`SetFormat` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The wave stream's initial format is specified in the [IMiniportWaveCyclic::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavecyclic-newstream) call that creates the stream. Following stream creation, the `SetFormat` call can change the stream's format from its initial setting.

For information about specifying wave stream formats, see [Audio Data Formats and Data Ranges](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-data-formats-and-data-ranges).

## See also

[IMiniportWaveCyclic::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavecyclic-newstream)

[IMiniportWaveCyclicStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavecyclicstream)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)