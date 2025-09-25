## Description

The **KsDeviceRegisterAdapterObject** function registers a DMA adapter object with AVStream for performing scatter/gather DMA on the specified device. All drivers compiled for Win64 should use [IKsDeviceFunctions::RegisterAdapterObjectEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-iksdevicefunctions-registeradapterobjectex) instead.

## Parameters

### `Device` [in]

A pointer to the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the AVStream device for which to register an adapter object.

### `AdapterObject` [in]

A pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the DMA controller..

### `MaxMappingsByteCount` [in]

This parameter specifies the maximum number of bytes that the device can handle for a single mapping. Allows AVStream to automatically break up large chunks of contiguous physical memory into multiple scatter/gather elements for devices that impose a size limit on individual mappings in DMA transfers. Breaks are not guaranteed to occur on page boundaries.

### `MappingTableStride` [in]

This parameter specifies how many bytes each entry in the mapping table requires. This must be at least **sizeof** ([KSMAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksmapping)) and can be as large as necessary.

Additional space can be used by the minidriver as context information.

## Remarks

A minidriver that calls **KsDeviceRegisterAdapterObject** is responsible for previously acquiring the adapter object through [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

Also note that if the minidriver specifies the KSPIN_FLAG_GENERATE_MAPPINGS flag for any pin on any filter on the device, the minidriver must call **KsDeviceRegisterAdapterObject** before processing any data. More information about this flag can be found in the reference page for [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex). Also see [AVStream DMA Services](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-dma-services).

If you set *MaxMappingByteCount* to one physical page in length, mappings are not guaranteed to reside on a single physical page. In addition, as noted in the member description above, setting *MaxMappingsByteCount* does not guarantee that breaks will occur on page boundaries. If you require breaks on page boundaries, consider not specifying a limit on mapping sizes; instead, break the returned scatter/gather mappings into page-aligned chunks manually.

Also see [Supporting DMA in 64-Bit AVStream Drivers](https://learn.microsoft.com/windows-hardware/drivers/stream/supporting-dma-in-64-bit-avstream-drivers).

## See also

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KSMAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksmapping)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)