# IMiniportDMus::NewStream

## Description

The `NewStream` method creates a new instance of a logical stream associated with a specified physical channel.

## Parameters

### `MXF` [out]

Output pointer for the new stream. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the stream object's [IMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imxf) interface.

### `OuterUnknown` [in, optional]

Pointer to the **IUnknown** interface of an object that needs to aggregate the stream object. This parameter is optional. If aggregation is not required, the caller specifies this parameter as **NULL**.

### `PoolType` [in]

Specifies the type of memory pool from which the storage for the DMA-channel object should be allocated. This parameter is set to one of the [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) enumeration values.

### `PinID` [in]

Specifies the pin ID. This parameter identifies the pin that is to be opened. If the DMus miniport driver's [IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription) method outputs a filter descriptor that specifies a total of *n* pin factories on the filter, then valid pin IDs are in the range 0 to *n*-1.

### `StreamType` [in]

Specifies the type of data stream to create. This parameter is set to one of the following DMUS_STREAM_TYPE enumeration values:

#### DMUS_STREAM_MIDI_RENDER

Specifies a MIDI output (playback) stream.

#### DMUS_STREAM_MIDI_CAPTURE

Specifies a MIDI input stream.

#### DMUS_STREAM_WAVE_SINK

Specifies a wave output stream.

For more information, see the following Remarks section.

### `DataFormat` [in]

Pointer to a kernel streaming [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure specifying the data format to use for this instance

### `ServiceGroup` [out]

Output pointer for service group. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) interface of the stream's service group object. This is the service group that is being registered for interrupt notification.

### `AllocatorMXF` [in]

Pointer to an [IAllocatorMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iallocatormxf) object. This is the port driver's memory allocator, which is needed to recycle [DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event) structures.

### `MasterClock` [in]

Pointer to an [IMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imasterclock) object. This master clock passes a wrapper for the KS clock to the miniport driver. The master-clock pointer is required to sync to reference time.

### `SchedulePreFetch` [out]

Output pointer for the schedule-prefetch time. This parameter is a pointer to a caller-allocated ULONGLONG variable into which the method writes a time value that specifies how far ahead to query for events. The time is specified in 100-nanosecond units. The port driver is responsible for sequencing any events that exceed the amount of time that the miniport driver specifies here.

## Return value

`NewStream` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

Note that the port driver creates the **IAllocatorMXF** object that the `NewStream` method inputs through the *pAllocatorMXF* parameter, but the miniport driver creates the **IMXF** object that the method outputs through the *ppMXF* parameter. For more information about **IMXF** and **IAllocatorMXF**, see [MIDI Transport](https://learn.microsoft.com/windows-hardware/drivers/audio/midi-transport).

The meaning of the `IMiniportDMus::NewStream` method's *StreamType* parameter is similar to that of the [IMiniportMidi::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportmidi-newstream) method's *Capture* parameter:

* When creating a stream on a MIDI pin, the **IMiniportMidi::NewStream** method's *Capture* parameter indicates whether the pin is to serve as the sink for a MIDI render stream (*Capture* = **FALSE**) or as the source of a MIDI capture stream (*Capture* = **TRUE**).
* Similarly, when creating a stream on a MIDI or DirectMusic pin, the `IMiniportDMus::NewStream` method's *StreamType* parameter can indicate whether the pin is to serve as the sink for a MIDI render stream (*StreamType* = DMUS_STREAM_MIDI_RENDER) or as the source of a MIDI capture stream (*StreamType* = DMUS_STREAM_MIDI_CAPTURE).

However, a pin on a DirectMusic filter can support a third option that is not available with a MIDI filter. A pin can serve as the source of a wave output stream (*StreamType* = DMUS_STREAM_WAVE_SINK). The DMus port driver implements the wave sink for this stream. After creating the wave output stream, the DMus port driver queries the stream object (which the port driver obtains through the `IMiniportDMus::NewStream` method's *ppMXF* output parameter) for its [ISynthSinkDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-isynthsinkdmus) interface. The port driver's wave sink calls the **Render** method on this interface to pull wave data from the software synthesizer. For more information, see [A Wave Sink for Kernel-Mode Software Synthesizers](https://learn.microsoft.com/windows-hardware/drivers/audio/a-wave-sink-for-kernel-mode-software-synthesizers).

The *ppMXF*, *pOuterUnknown*, *ppServiceGroup*, *pAllocatorMXF*, and *pMasterClock* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event)

[IAllocatorMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iallocatormxf)

[IMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imxf)

[IMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imasterclock)

[IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription)

[IMiniportDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iminiportdmus)

[IMiniportMidi::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportmidi-newstream)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[ISynthSinkDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-isynthsinkdmus)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)