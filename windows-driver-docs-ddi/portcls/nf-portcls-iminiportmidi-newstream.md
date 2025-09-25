# IMiniportMidi::NewStream

## Description

The `NewStream` method creates a new instance of a logical stream associated with a specified physical channel.

## Parameters

### `Stream` [out]

Output pointer for the new stream. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the stream object's [IMiniportMidiStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidistream) interface.

### `OuterUnknown` [in, optional]

Pointer to the **IUnknown** interface of an object that needs to aggregate the stream object. This parameter is optional. If aggregation is not required, the caller specifies this parameter as **NULL**.

### `PoolType` [in]

Specifies the type of memory pool from which the storage for the DMA-channel object should be allocated. This parameter is set to one of the [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) enumeration values.

### `Pin` [in]

Specifies the pin ID. This parameter identifies the pin that is to be opened. If the MIDI miniport object's [IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription) method outputs a filter descriptor that specifies a total of *n* pin factories on the filter, then valid pin IDs are in the range 0 to *n*-1.

### `Capture` [in]

Specifies whether the channel is to be used for capture or for playback. If **TRUE**, it is a capture (input) channel. If **FALSE**, it is a playback (output) channel.

### `DataFormat` [in]

Pointer to a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure that specifies the data format to use for this stream instance.

### `ServiceGroup` [out]

Output pointer for the service group. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) interface of the stream's service group object. This is the service group that is being registered for interrupt notification.

## Return value

`NewStream` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `NewStream` method sets the initial state of the stream to KSSTATE_STOP.

The *Stream*, *OuterUnknown*, and *ServiceGroup* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription)

[IMiniportMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidi)

[IMiniportMidiStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidistream)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)