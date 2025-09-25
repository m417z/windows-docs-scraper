# IMiniportWavePci::NewStream

## Description

The `NewStream` method creates a new instance of a logical stream associated with a specified physical channel.

## Parameters

### `Stream` [out]

Output pointer for the new stream. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the stream object's [IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream) interface. The caller specifies a valid, non-**NULL** pointer for this parameter.

### `OuterUnknown` [in, optional]

Pointer to the **IUnknown** interface of an object that needs to aggregate the stream object. This parameter is optional. If aggregation is not required, the caller specifies this parameter as **NULL**.

### `PoolType` [in]

Specifies the type of memory pool from which the storage for the DMA-channel object should be allocated. This parameter will be one of the nonpaged pool types defined in the [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) enumeration.

### `PortStream` [in]

Pointer to the [IPortWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepcistream) interface of the port driver's stream object.

### `Pin` [in]

Specifies a pin ID identifying the pin that is to be opened. If the WavePci miniport driver's filter descriptor specifies a total of *n* pin factories on the filter, then valid values for parameter *Pin* are in the range 0 to *n*-1.

### `Capture` [in]

Specifies whether to create a capture stream or a render stream. This parameter is **TRUE** for an capture (input) channel, and **FALSE** for an playback (output) channel.

### `DataFormat` [in]

Pointer to a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure that specifies the stream's data format.

### `DmaChannel` [out]

Output pointer for the DMA channel. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the stream's [IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel) object. The caller specifies a valid, non-**NULL** pointer for this parameter.

### `ServiceGroup` [out]

Output pointer for the service group. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) interface of the stream's service group object. This is the service group that is being registered for interrupt notification. The caller specifies a valid, non-**NULL** pointer for this parameter.

## Return value

`NewStream` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `NewStream` method sets the initial state of the stream to KSSTATE_STOP and its initial position to zero. (See [IMiniportWavePciStream::SetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-setstate) and [IMiniportWavePciStream::GetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-getposition).)

The *DataFormat* parameter, which specifies the data format of the stream, points to one of the following audio-specific, extended versions of the [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure:

[KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex)

[KSDATAFORMAT_DSOUND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_dsound)

If the miniport driver does not provide a service group pointer (that is, if the `NewStream` call outputs **NULL** through the *ServiceGroup* pointer), the port driver sets up its own periodic timer instead for processing stream position and clock events. The period for this timer is currently 20 milliseconds, but the period might change in future implementations.

The *Stream*, *OuterUnknown*, *PortStream*, and *ServiceGroup* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

Note that `NewStream` does not follow the usual reference-counting conventions in its handling of the pointer that it outputs through the *DmaChannel* OUT parameter. When the port driver finishes using the references that it receives through the `NewStream` method's other OUT parameters, *Stream* and *ServiceGroup*, it releases them, as expected. In contrast, the port driver never uses the *DmaChannel* pointer that it receives from the `NewStream` call and it never calls **Release** on the *DmaChannel* object.

The ac97 sample audio driver in the Microsoft Windows Driver Kit (WDK) reflects this behavior. This sample's implementation of the `IMiniportWavePci::NewStream` method calls **AddRef** on the *Stream* and *ServiceGroup* references that it outputs but not the *DmaChannel* reference. This behavior is preserved for the sake of backward compatibility.

Note that the `NewStream` methods for the other port types (WaveCyclic, in particular) follow the usual reference-counting conventions for all their OUT parameters.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)

[IMiniportWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepci)

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[IPortWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepcistream)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[KSDATAFORMAT_DSOUND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_dsound)

[KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)