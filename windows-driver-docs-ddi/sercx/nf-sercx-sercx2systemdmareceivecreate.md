# SerCx2SystemDmaReceiveCreate function

## Description

The **SerCx2SystemDmaReceiveCreate** method creates a SerCx2 system-DMA-receive object, which version 2 of the serial framework extension (SerCx2) uses to perform system-DMA-receive transactions.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `SystemDmaReceiveConfig` [in]

A pointer to a [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config) structure. Before calling this method, the caller must call the [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init) or [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init_new_data_notification) function to initialize the structure. This structure contains pointers to a set of event callback routines that are implemented by the serial controller driver. SerCx2 calls these functions to perform system-DMA-receive transactions.

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes the attributes to assign to the new system-DMA-receive object. Before calling this method, the caller must call the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function to initialize the structure. This parameter is optional and can be specified as WDF_NO_OBJECT_ATTRIBUTES if the serial controller driver does not need to assign attributes to the object. For more information, see Remarks.

### `SystemDmaReceive` [out]

A pointer to a location to which this method writes a [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to the newly created system-DMA-receive object. SerCx2 and the serial controller driver use this handle in subsequent calls to refer to this object.

## Return value

This method returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | A system-DMA-receive object already exists from a previous **SerCx2SystemDmaReceiveCreate** call; or a custom-receive object already exists from a previous call to the [SerCx2CustomReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivecreate) method; or a custom-transmit object exists from a previous call to the [SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate) method; or [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) has not yet been called to create a PIO-receive object. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *Config*->**Size** value does not equal **sizeof**(**SERCX2_SYSTEM_DMA_RECEIVE_CONFIG**). |
| **STATUS_INVALID_PARAMETER** | A parameter value is not valid. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to perform the requested operation. |

## Remarks

This method is called by the serial controller driver to create a system-DMA-receive object. SerCx2 uses this object to perform system-DMA-receive transactions, which are I/O transactions that use the system DMA controller to read data received by the serial controller.

Typically, a serial controller driver calls **SerCx2SystemDmaReceiveCreate** from its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. This function receives a list of hardware resources, which can include system DMA channels.

A serial controller driver must successfully call the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) and [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) methods before calling **SerCx2SystemDmaReceiveCreate**.

Before calling **SerCx2SystemDmaReceiveCreate**, the serial controller driver must call the [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init) or [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init_new_data_notification) function to initialize the [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config) structure pointed to by *SystemDmaReceiveConfig*. These functions set the following members of the structure to zero:

* **MaximumScatterGatherFragments**
* **MinimumTransferUnitOverride**
* **DmaAlignment**
* **MinimumTransactionLength**
* **Exclusive**

If necessary, the serial controller driver can set any of these members to nonzero values after the initialization function returns. However, for convenience, **SerCx2SystemDmaReceiveCreate** uses the following default values if these members are zero:

* If **MaximumScatterGatherFragments** is zero, SerCx2 sets the maximum number of elements in a scatter/gather list to ((ULONG)-1).
* If **MinimumTransferUnitOverride** is zero, SerCx2 sets the minimum transfer unit to its default value, which is specified in the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure for the system DMA controller. For more information about this structure, see [WdfDmaEnablerWdmGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerwdmgetdmaadapter).
* If **DmaAlignment** is zero, SerCx2 sets the alignment value to the minimum transfer unit. If **MinimumTransferUnitOverride** is zero, the default minimum transfer unit is used.
* If **MinimumTransactionLength** is zero, SerCx2 sets the minimum transaction length to one byte.
* If **Exclusive** is zero (**FALSE**), exclusive mode is disabled.

If the calling driver sets **Exclusive** to **TRUE**, the **MinimumTransferUnitOverride**, **DmaAlignment**, and **MinimumTransactionLength** members must be zero. For more information, see [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config).

If the specified combination of implemented callback functions is not valid, **SerCx2SystemDmaReceiveCreate** fails and returns STATUS_INVALID_PARAMETER. The driver must implement either both or neither of the [EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification) and [EvtSerCx2SystemDmaReceiveCancelNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cancel_new_data_notification) functions.

As an option, a serial controller driver can use the *Attributes* parameter to create a context for the system-DMA-receive object, and to supply pointers to [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) and [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) functions that are called to prepare the object for deletion. For more information, see [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes).

If the *Attributes* parameter points to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, the caller must not overwrite the values that the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) initialization function writes to the **ParentObject**, **ExecutionLevel**, and **SynchronizationScope** members of this structure.

For more information about creating system-DMA-receive objects, see [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles). For more information about system-DMA-receive transactions, see [SerCx2 System-DMA-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

## See also

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup)

[EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy)

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[EvtSerCx2SystemDmaReceiveCancelNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cancel_new_data_notification)

[EvtSerCx2SystemDmaReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cleanup_transaction)

[EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification)

[EvtSerCx2SystemDmaReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_initialize_transaction)

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config)

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init)

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init_new_data_notification)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfDmaEnablerWdmGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerwdmgetdmaadapter)