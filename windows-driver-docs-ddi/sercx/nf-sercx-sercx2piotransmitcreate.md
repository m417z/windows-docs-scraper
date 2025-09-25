# SerCx2PioTransmitCreate function

## Description

The **SerCx2PioTransmitCreate** method creates a PIO-transmit object, which version 2 of the serial framework extension (SerCx2) uses to perform PIO-transmit transactions.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `PioTransmitConfig` [in]

A pointer to a [SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config) structure. Before calling this method, the caller must call the [SERCX2_PIO_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_pio_transmit_config_init) function to initialize the structure. This structure contains pointers to a set of event callback routines that are implemented by the serial controller driver. SerCx2 calls these functions to perform PIO-transmit transactions.

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes the attributes to assign to the new PIO-transmit object. Before calling this method, the caller must call the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function to initialize the structure. This parameter is optional and can be specified as WDF_NO_OBJECT_ATTRIBUTES if the serial controller driver does not need to assign attributes to the object. For more information, see Remarks.

### `PioTransmit` [out]

A pointer to a location to which this method writes a [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to the newly created PIO-transmit object. SerCx2 and the serial controller driver use this handle in subsequent calls to refer to this object.

## Return value

This method returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | A PIO-transmit object already exists from a previous **SerCx2PioTransmitCreate** call. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *Config*->**Size** value does not equal **sizeof**(**SERCX2_PIO_TRANSMIT_CONFIG**). |
| **STATUS_INVALID_PARAMETER** | The specified combination of implemented callback functions is not valid. The driver must implement the [EvtSerCx2PioTransmitWriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_write_buffer), [EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification), and [EvtSerCx2PioTransmitCancelReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_ready_notification) functions. The driver must implement either all three or none of the [EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo), [EvtSerCx2PioTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_drain_fifo), and [EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo) functions. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to perform the requested operation. |

## Remarks

Your serial controller driver calls this method to create a PIO-transmit object. SerCx2 uses this object to perform PIO-transmit transactions, which are transactions that use programmed I/O (PIO) to write data to the serial controller to be transmitted.

Typically, a serial controller driver calls **SerCx2PioTransmitCreate** from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) function. The driver must call this method only after it successfully calls the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method.

As an option, a serial controller driver can use the *Attributes* parameter to create a context for the PIO-transmit object, and to supply pointers to [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) and [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) functions that are called to prepare the object for deletion. For more information, see [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes).

If the *Attributes* parameter points to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, the caller must not overwrite the values that the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) initialization function writes to the **ParentObject**, **ExecutionLevel**, and **SynchronizationScope** members of this structure.

For more information about creating PIO-transmit objects, see [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles). For more information about PIO-transmit operations, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

## See also

[EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup)

[EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_PIO_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_pio_transmit_config)

[SERCX2_PIO_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_pio_transmit_config_init)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)