# IMiniportWaveRT::NewStream

## Description

The `NewStream` method creates a new instance of a WaveRT stream object.

## Parameters

### `Stream` [out]

Output pointer for the new stream. This parameter points to a caller-allocated pointer variable, into which the `NewStream` method writes a pointer to the **IMiniportWaveRTStream** interface of the new stream object. The caller specifies a valid, non-**NULL** pointer for this parameter.

### `PortStream` [in]

Pointer to the [IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream).

### `Pin` [in]

Specifies a pin ID that identifies the pin to be opened. If the filter descriptor of the WaveRT miniport driver specifies a total of *n* pin factories on the filter, valid values for the *Pin* parameter are in the range 0 to *n*-1. For more information about filter descriptors, see the [Filter Factories](https://learn.microsoft.com/windows-hardware/drivers/audio/filter-factories) topic.

### `Capture` [in]

Specifies a Boolean value that indicates whether to create a capture stream or a render stream. This parameter is **TRUE** for a capture (input) stream, and **FALSE** for a playback (output) stream.

### `DataFormat` [in]

Pointer to a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure that specifies the data format of the new stream. For more information, see the following Remarks section.

## Return value

`NewStream` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code.

## Remarks

The `NewStream` method sets the initial state of the stream to [KSSTATE_STOP](https://learn.microsoft.com/windows-hardware/drivers/stream/state-transitions) and its initial position to 0. For more information, see related methods [IMiniportWaveRTStream::SetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstream-setstate) and [IMiniportWaveRTStream::GetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstream-getposition).

The *DataFormat* parameter, which specifies the data format of the stream, points to one of the following audio-specific, extended versions of the KSDATAFORMAT structure:

* [KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex)
* [KSDATAFORMAT_DSOUND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_dsound)

The *Stream* and *PortStream* parameters follow the reference-counting conventions for COM objects.

## See also

[IMiniportWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavert)

IMiniportWaveRTStream

[IMiniportWaveRTStream::GetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstream-getposition)

[IMiniportWaveRTStream::SetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstream-setstate)

[IPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavertstream)