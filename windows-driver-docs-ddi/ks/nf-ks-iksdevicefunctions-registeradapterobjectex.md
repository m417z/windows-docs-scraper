# IKsDeviceFunctions::RegisterAdapterObjectEx

## Description

The **IKsDeviceFunctions::RegisterAdapterObjectEx** method registers a DMA adapter object with AVStream. All drivers compiled for Win64 platforms should use this method instead of [KsDeviceRegisterAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeviceregisteradapterobject).

## Parameters

### `AdapterObject` [in]

Pointer to the ADAPTER_OBJECT for the device. Must be acquired through [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) before calling **RegisterAdapterObjectEx**.

### `DeviceDescription` [in]

Pointer to a structure of type [DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description) that describes the attributes of the physical device for which the caller is registering a DMA object.

### `NumberOfMapRegisters` [in]

Specifies the number of map registers returned from the minidriver's call to **IoGetDmaAdapter**.

### `MaxMappingsByteCount` [in]

Specifies the maximum number of bytes that the device can handle for a single mapping. Enables AVStream to automatically break up large chunks of contiguous physical memory into multiple scatter/gather elements for devices that impose a size limit on individual mappings in DMA transfers. See important additional information about **MaxMappingsByteCount** on the [KsDeviceRegisterAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeviceregisteradapterobject) reference page.

### `MappingTableStride` [in]

Specifies how many bytes each entry in the mapping table requires. This value must be at least **sizeof** ([KSMAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksmapping)) and can be as large as necessary.

Additional space can be used by the minidriver as context information.

## Return value

**RegisterAdapterObjectEx** returns STATUS_SUCCESS if the DMA object was successfully registered. The method returns STATUS_INSUFFICIENT_RESOURCES if sufficient memory is not available.

## Remarks

Also see [Supporting DMA in 64-Bit AVStream Drivers](https://learn.microsoft.com/windows-hardware/drivers/stream/supporting-dma-in-64-bit-avstream-drivers).

## See also

[KsDeviceRegisterAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeviceregisteradapterobject)