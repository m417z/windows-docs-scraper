# GET_DMA_ADAPTER callback function

## Description

The *GetDmaAdapter* routine returns a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure for the target device.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard) structure for the interface.

### `DeviceDescriptor` [in]

A pointer to a [DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description) structure that describes the attributes of the physical device.

### `NumberOfMapRegisters` [out]

A pointer to, on output, the maximum number of map registers that the driver can allocate for any DMA transfer operation. The caller must allocate a **LONG** variable to receive this data.

## Return value

The *GetDmaAdapter* routine returns a pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure when successful. If an adapter structure cannot be allocated, the routine returns **NULL**.

## Remarks

If the driver is executing at IRQL = PASSIVE_LEVEL, it should obtain a device's DMA adapter object by calling the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) function. **IoGetDmaAdapter** detects whether the bus driver supports the [BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard) interface; if it does, **IoGetDmaAdapter** calls the routine pointed to by the *GetDmaAdapter* member of this interface to obtain the adapter object. Otherwise, **IoGetDmaAdapter** calls an equivalent legacy routine.

However, if a driver must obtain an adapter object while running at IRQL ≥ DISPATCH_LEVEL, it cannot do so with the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) function. In such a case, the driver must query for the [BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard) interface while still at IRQL = PASSIVE_LEVEL by issuing an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request.

## See also

[BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard)

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)