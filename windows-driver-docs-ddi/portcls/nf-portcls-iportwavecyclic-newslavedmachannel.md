# IPortWaveCyclic::NewSlaveDmaChannel

## Description

The `NewSlaveDmaChannel` method creates a new instance of a subordinate DMA channel.

## Parameters

### `DmaChannel` [out]

Pointer to a caller-allocated pointer variable into which the method writes a pointer to the new DMA-channel object's [IDmaChannelSlave](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave) interface. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in]

Pointer to the **IUnknown** interface of an object that needs to aggregate the DMA-channel object. This parameter is optional. If aggregation is not required, specify this parameter as **NULL**.

### `ResourceList` [in]

Pointer to an [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) object. This resource list contains the resource that describes the DMA channel.

### `DmaIndex` [in]

Index in the resource list of the DMA-channel descriptor. The function uses this value as a call parameter to the *ResourceList* object's IResourceList::Find*xxx*Entry method.

### `MaximumLength` [in]

Maximum length in bytes of the cyclic DMA buffer that will be associated with this channel.

### `DemandMode` [in]

Indicates whether the device associated with the DMA channel supports demand mode.

### `DmaSpeed` [in]

The DMA speed can be specified as one of the following DMA_SPEED enumeration values: **Compatible**, **TypeA**, **TypeB**, **TypeC**, or **TypeF**.

## Return value

`NewSlaveDmaChannel` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

Parameters *MaximumLength*, *DemandMode*, and *DmaSpeed* are similar in meaning to the members of the [DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description) structure with the same names.

A WaveCyclic device that lacks DMA-hardware capabilities is referred to as a *subordinate device*. In contrast, a *master device* has built-in bus-mastering DMA hardware. A subordinate device has to rely on the system DMA controller to perform any data transfers that it requires. The `NewSlaveDmaChannel` method creates a DMA-channel object for a subordinate device. To create a DMA-channel object for a master device, call the [IPortWaveCyclic::NewMasterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-newmasterdmachannel) method instead. The sb16 sample audio driver in the Microsoft Windows Driver Kit (WDK) is an example of a WaveCyclic miniport driver for a subordinate device. For more information about master and subordinate devices, see [IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel) and [IDmaChannelSlave](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave).

The *DmaChannel*, *OuterUnknown*, and *ResourceList* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)

[IDmaChannelSlave](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave)

[IPortWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavecyclic)

[IPortWaveCyclic::NewMasterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-newmasterdmachannel)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)