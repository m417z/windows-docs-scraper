# _SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG structure

## Description

The **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new system-DMA-transmit object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `MaximumTransferLength`

The default maximum size, in bytes, that the serial controller can handle in a single system DMA transfer. If the size of the buffer in the write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request is larger than this maximum size, SerCx2 uses multiple DMA transfers to handle the request, and limits each transfer to the maximum length.

### `MinimumTransactionLength`

The minimum length, in bytes, of a system-DMA-transmit transaction. If the length of the buffer in a write request is less than this minimum length, SerCx2 uses programmed I/O (PIO) for the transaction.

### `DmaAlignment`

DMA alignment requirement. Specifies how the starting address of a transfer in a system-DMA-transmit transaction must be aligned in memory. Set this member to the appropriate FILE_*XXX*_ALIGNMENT constant in the Wdm.h header file. For example, FILE_WORD_ALIGNMENT indicates that the starting DMA address must be aligned to a two-byte boundary in memory, FILE_LONG_ALIGNMENT indicates that the address must be aligned to a four-byte boundary, and so on. SerCx2 does not support FILE_BYTE_ALIGNMENT. The minimum transfer unit (MTU) of the system DMA adapter should be greater than or equal to the required alignment. For example, if the MTU is four bytes, **DmaAlignment** must be at least FILE_LONG_ALIGNMENT.

### `MaximumScatterGatherFragments`

The maximum number of buffer fragments that can be specified in the scatter/gather list for a DMA transfer in a system-DMA-transmit transaction.

### `DmaWidth`

The width of the data register at the address specified by **DeviceAddress**. Possible values are **Width8Bits**, **Width16Bits**, **Width32Bits**, and **Width64Bits**.

### `DeviceAddress`

The translated device address to which the DMA controller transfers data to be transmitted. For more information, see the description of the **DeviceAddress** member in [WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config).

### `DmaDescriptor`

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes the system DMA resource to use for transmit transactions. The serial controller driver gets this structure from the raw resource list it receives in the [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback that starts the serial controller.

### `MinimumTransferUnitOverride`

An override value to use in place of the default minimum transfer unit. The number of bytes specified by an element in a scatter/gather list must be an integer multiple of the minimum transfer unit. A value of zero indicates that the default minimum transfer unit should be used. For more information about the default minimum transfer unit, see [DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1).

### `Exclusive`

Whether to use system-DMA-transmit transactions exclusively to handle write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) requests. Set to **TRUE** to indicate that write requests should use system-DMA-transmit transactions exclusively. Set to **FALSE** to indicate that write requests can use a combination of system-DMA-transmit transactions and PIO-transmit transactions.

Set this member to **TRUE** only if the minimum transfer unit for system-DMA-transmit transactions is one byte, the minimum transaction length is one byte, and the write buffer for the transaction can start on any byte boundary in memory.

If **Exclusive** is **TRUE**, the **MinimumTransferUnitOverride**, **Alignment**, and **MinimumTransactionLength** members must be zero.

### `EvtSerCx2SystemDmaTransmitInitializeTransaction`

A pointer to the driver-implemented [EvtSerCx2SystemDmaTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_initialize_transaction) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SystemDmaTransmitCleanupTransaction`

A pointer to the driver-implemented [EvtSerCx2SystemDmaTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cleanup_transaction) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SystemDmaTransmitConfigureDmaChannel`

A pointer to the driver-implemented [EvtSerCx2SystemDmaTransmitConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_configure_dma_channel) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SystemDmaTransmitDrainFifo`

A pointer to the driver-implemented [EvtSerCx2SystemDmaTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_drain_fifo) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement *EvtSerCx2SystemDmaTransmitCancelDrainFifo* and *EvtSerCx2SystemDmaTransmitPurgeFifo* functions.

### `EvtSerCx2SystemDmaTransmitCancelDrainFifo`

A pointer to the driver-implemented [EvtSerCx2SystemDmaTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cancel_drain_fifo) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement *EvtSerCx2SystemDmaTransmitDrainFifo* and *EvtSerCx2SystemDmaTransmitPurgeFifo* functions.

### `EvtSerCx2SystemDmaTransmitPurgeFifo`

A pointer to the driver-implemented [EvtSerCx2SystemDmaTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_purge_fifo) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement *EvtSerCx2SystemDmaTransmitDrainFifo* and *EvtSerCx2SystemDmaTransmitCancelDrainFifo* functions.

## Remarks

The [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method accepts a pointer to a **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG** structure as an input parameter. Before calling **SerCx2SystemDmaTransmitCreate**, call the [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_transmit_config_init) function to initialize this structure.

## See also

[DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1)

[EvtSerCx2SystemDmaTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cancel_drain_fifo)

[EvtSerCx2SystemDmaTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cleanup_transaction)

[EvtSerCx2SystemDmaTransmitConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_configure_dma_channel)

[EvtSerCx2SystemDmaTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_drain_fifo)

[EvtSerCx2SystemDmaTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_initialize_transaction)

[EvtSerCx2SystemDmaTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_purge_fifo)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_transmit_config_init)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)

[WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements)