# _SERCX2_SYSTEM_DMA_RECEIVE_CONFIG structure

## Description

The **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new system-DMA-receive object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `MaximumTransferLength`

The default maximum size, in bytes, that the serial controller can handle in a single system DMA transfer. If the size of the buffer in the read ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) request is larger than this maximum size, SerCx2 uses multiple DMA transfers to handle the request, and limits each transfer to the maximum length.

### `MinimumTransactionLength`

The minimum length, in bytes, of a system-DMA-receive transaction. If the length of the buffer in a read request is less than this minimum length, SerCx2 uses programmed I/O (PIO) for the transaction.

### `DmaAlignment`

DMA alignment requirement. Specifies how the starting address of a transfer in a system-DMA-receive transaction must be aligned in memory. Set this member to the appropriate FILE_*XXX*_ALIGNMENT constant in the Wdm.h header file. For example, FILE_WORD_ALIGNMENT indicates that the starting DMA address must be aligned to two-byte boundary in memory, FILE_LONG_ALIGNMENT indicates that the address must be aligned to a four-byte boundary, and so on. SerCx2 does not support FILE_BYTE_ALIGNMENT. The minimum transfer unit (MTU) of the system DMA adapter should be greater than or equal to the required alignment. For example, if the MTU is four bytes, **DmaAlignment** must be at least FILE_LONG_ALIGNMENT.

### `MaximumScatterGatherFragments`

The maximum number of buffer fragments that can be specified in the scatter/gather list for a DMA transfer in a system-DMA-receive transaction.

### `DmaWidth`

The width of the data register at the address specified by **DeviceAddress**. Possible values are **Width8Bits**, **Width16Bits**, **Width32Bits**, and **Width64Bits**.

### `DeviceAddress`

The translated address from which the DMA controller transfers. For more information, see the description of the **DeviceAddress** member in [WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config).

### `DmaDescriptor`

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes the system DMA resource to use for receive transactions. The serial controller driver gets this structure from the raw resource list it receives in the [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback that starts the serial controller.

### `MinimumTransferUnitOverride`

An override value to use in place of the default minimum transfer unit. The number of bytes specified by an element in a scatter/gather list must be an integer multiple of the minimum transfer unit. A value of zero indicates that the default minimum transfer unit should be used. For more information, see the description of the **MinimumTransferUnit** member in [DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1).

### `Exclusive`

Whether to use system-DMA-receive transactions exclusively to handle write ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) requests. Set to **TRUE** to indicate that read requests should use system-DMA-receive transactions exclusively. Set to **FALSE** to indicate that read requests can use a combination of system-DMA-receive transactions and PIO-receive transactions.

Set this member to **TRUE** only if the minimum transfer unit for system-DMA-receive transactions is one byte, the minimum transaction length is one byte, and the read buffer for the transaction can start on any byte boundary in memory.

If **Exclusive** is **TRUE**, the **MinimumTransferUnitOverride**, **DmaAlignment**, and **MinimumTransactionLength** members must be zero.

Regardless of the value of this member, PIO-receive transactions are used to save any unread data in the receive FIFO before the serial controller exits the D0 device power state to enter a low-power state.

### `EvtSerCx2SystemDmaReceiveInitializeTransaction`

A pointer to the driver-implemented [EvtSerCx2SystemDmaReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_initialize_transaction) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SystemDmaReceiveCleanupTransaction`

A pointer to the driver-implemented [EvtSerCx2SystemDmaReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cleanup_transaction) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SystemDmaReceiveConfigureDmaChannel`

A pointer to the driver-implemented [EvtSerCx2SystemDmaReceiveConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_configure_dma_channel) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SystemDmaReceiveEnableNewDataNotification`

A pointer to the driver-implemented [EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement an *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* function.

### `EvtSerCx2SystemDmaReceiveCancelNewDataNotification`

A pointer to the driver-implemented [EvtSerCx2SystemDmaReceiveCancelNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cancel_new_data_notification) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement an *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function.

## Remarks

The [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method accepts a pointer to a **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG** structure as an input parameter. Before calling **SerCx2SystemDmaReceiveCreate**, call the [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init) or [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init_new_data_notification) function to initialize this structure.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[EvtSerCx2SystemDmaReceiveCancelNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cancel_new_data_notification)

[EvtSerCx2SystemDmaReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cleanup_transaction)

[EvtSerCx2SystemDmaReceiveConfigureDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_configure_dma_channel)

[EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification)

[EvtSerCx2SystemDmaReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_initialize_transaction)

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init)

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init_new_data_notification)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)

[WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements)