# IPortWaveCyclic::NewMasterDmaChannel

## Description

The `NewMasterDmaChannel` method creates a new instance of a bus-master DMA channel.

## Parameters

### `DmaChannel` [out]

Pointer to a caller-allocated pointer variable into which the method writes a pointer to the new [IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel) object. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in]

Pointer to the **IUnknown** interface of an object that needs to aggregate the DMA-channel object. This parameter is optional. If aggregation is not required, specify this parameter as **NULL**.

### `ResourceList` [in, optional]

Pointer to the miniport driver's resource list, which is an [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) object. This parameter is optional and can be specified as **NULL**. The `NewMasterDmaChannel` method currently makes no use of this parameter.

### `MaximumLength` [in]

Maximum length in bytes of the cyclic DMA buffer that will be associated with this channel.

### `Dma32BitAddresses` [in]

Specifies the use of 32-bit addresses.

### `Dma64BitAddresses` [in]

Specifies the use of 64-bit addresses.

### `DmaWidth` [in]

Not used. Set to (DMA_WIDTH)(-1).

### `DmaSpeed` [in]

Not used. Set to (DMA_SPEED)(-1).

## Return value

`NewMasterDmaChannel` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

Parameters *MaximumLength*, *Dma32BitAddresses*, *Dma64BitAddresses*, *DmaWidth*, and *DmaSpeed* are similar in meaning to the members of the [DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description) structure with the same names.

A WaveCyclic device with built-in bus-mastering DMA hardware is referred to as a *master device*. In contrast, a *subordinate device* lacks DMA hardware and has to rely on the system DMA controller to perform any data transfers that it requires. The `NewMasterDmaChannel` method creates a DMA-channel object for a master device. To create a DMA-channel object for a subordinate device, call the [IPortWaveCyclic::NewSlaveDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-newslavedmachannel) method instead. For more information about master and subordinate devices, see [IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel) and [IDmaChannelSlave](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave).

The *DmaChannel*, *OuterUnknown*, and *ResourceList* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

## See also

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)

[IDmaChannelSlave](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave)

[IPortWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavecyclic)

[IPortWaveCyclic::NewSlaveDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-newslavedmachannel)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)