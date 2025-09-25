# PcNewDmaChannel function

## Description

The **PcNewDmaChannel** function creates a new DMA-channel object. This function is obsolete; for more information, see the following comments.

## Parameters

### `OutDmaChannel` [out]

Output pointer for the DMA-channel object created by this function. This parameter points to a caller-allocated pointer variable into which the function outputs a reference to the newly created [IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel) object. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in, optional]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of an object that needs to aggregate the object. Unless aggregation is required, set this parameter to **NULL**.

### `PoolType` [in]

Specifies the type of storage pool from which the object is to be allocated. This is a [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) enumeration value. Specify a nonpaged pool type for this parameter.

### `DeviceDescription` [in]

Pointer to a description of the physical device for which the caller is requesting a DMA object. This parameter points to a structure of type [DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description).

### `DeviceObject` [in]

Pointer to the device object for the physical adapter device. This parameter points to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

## Return value

**PcNewDmaChannel** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

**PcNewDmaChannel** is obsolete. For all new audio drivers, use one of the following IPortWave *Xxx*::New*Xxx*DmaChannel methods in place of **PcNewDmaChannel**:

[IPortWavePci::NewMasterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepci-newmasterdmachannel)

[IPortWaveCyclic::NewMasterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-newmasterdmachannel)

[IPortWaveCyclic::NewSlaveDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavecyclic-newslavedmachannel)

For the sake of backward compatibility, the PortCls system driver will continue to support **PcNewDmaChannel**, and existing drivers can continue to use this function.

Specify the *PoolType* parameter to be one of the nonpaged pool types defined in the POOL_TYPE enumeration. The DMA-channel object must not reside in paged memory because several of the methods in the [IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel) interface can be called from IRQL DISPATCH_LEVEL.

The *OutDmaChannel* and *OuterUnknown* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

## See also

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)