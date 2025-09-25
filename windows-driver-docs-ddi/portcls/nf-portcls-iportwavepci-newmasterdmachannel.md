# IPortWavePci::NewMasterDmaChannel

## Description

The `NewMasterDmaChannel` method creates a new instance of a bus-master DMA channel.

## Parameters

### `DmaChannel` [out]

Output pointer for the DMA channel. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the new DMA-channel object's [IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel) interface.

### `OuterUnknown` [in, optional]

Pointer to the **IUnknown** interface of an object that needs to aggregate the DMA-channel object. This parameter is optional. If aggregation is not required, specify this parameter as **NULL**.

### `PoolType` [in]

Specifies the type of storage pool from which the object is to be allocated. This is a [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) enumeration value. Specify a nonpaged pool type for this parameter.

### `ResourceList` [in, optional]

Pointer to the miniport driver's resource list, which is an [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) object. This parameter is optional and can be specified as **NULL**. The `NewMasterDmaChannel` method currently makes no use of this parameter.

### `ScatterGather` [in]

Requests that the DMA channel support scatter/gather DMA. Always set this parameter to **TRUE**.

### `Dma32BitAddresses` [in]

Specifies the use of 32-bit addresses for DMA operations.

### `Dma64BitAddresses` [in]

Specifies the use of 64-bit addresses for DMA operations.

### `IgnoreCount` [in]

Indicates whether to ignore the DMA controller's transfer counter. Set to **TRUE** if the DMA controller in this platform does not maintain an accurate transfer counter, and therefore requires a workaround.

### `DmaWidth` [in]

Not used. Set to (DMA_WIDTH)(-1).

### `DmaSpeed` [in]

Not used. Set to (DMA_SPEED)(-1).

### `MaximumLength` [in]

Maximum number of bytes in the buffer that will be associated with this DMA channel.

### `DmaPort` [in]

Not used. Set to 0.

## Return value

`NewMasterDmaChannel` returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

The definitions of the call parameters for the `NewMasterDmaChannel` method are similar to those for the members of the [DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description) structure with the same names.

Specify the *PoolType* parameter to be one of the nonpaged pool types defined in the POOL_TYPE enumeration. The DMA-channel object must not reside in paged memory because several of the methods in the **IDmaChannel** interface can be called from IRQL DISPATCH_LEVEL.

The *DmaChannel*, *OuterUnknown*, and *ResourceList* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)

[IPortWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepci)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)