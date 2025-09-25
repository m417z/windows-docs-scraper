# SerCx2CustomTransmitCreate function

## Description

The **SerCx2CustomTransmitCreate** method creates a custom-transmit object, which version 2 of the serial framework extension (SerCx2) uses to write transmit data to the serial controller by means of a custom data-transfer mechanism.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `CustomTransmitConfig` [in]

A pointer to a [SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config) structure. Before calling this method, the caller must call the [SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_config_init) function to initialize the structure. This structure contains pointers to a set of event callback routines that are implemented by the serial controller driver. SerCx2 calls these functions to perform custom-transmit transactions.

### `Attributes` [in]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes the attributes to assign to the new custom-transmit object. Before calling this method, the caller must call the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function to initialize the structure. This parameter is optional and can be specified as WDF_NO_OBJECT_ATTRIBUTES if the serial controller driver does not need to assign attributes to the object. For more information, see Remarks.

### `CustomTransmit` [out]

A pointer to a location to which this method writes a [SERCX2CUSTOMTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to the newly created custom-transmit object. SerCx2 and the serial controller driver use this handle in subsequent calls to refer to this object.

## Return value

This method returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | A custom-transmit object already exists from a previous **SerCx2CustomTransmitCreate** call; or a system-DMA-transmit object exists from a previous [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) call; or a system-DMA-transmit object exists from a previous **SerCx2SystemDmaTransmitCreate** call; or [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) has not yet been called to create a PIO-transmit object. |
| **STATUS_INVALID_PARAMETER** | A parameter value is not valid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *Config*->**Size** value does not equal **sizeof**(**SERCX2_CUSTOM_TRANSMIT_CONFIG**). |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to create the custom-transmit object. |

## Remarks

This method is called by the serial controller driver to create a custom-transmit object. SerCx2 uses this object to perform custom-transmit transactions, which are transactions that use a custom data-transfer mechanism to write transmit data to the serial controller.

A serial controller driver must successfully call the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) and [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) methods before calling **SerCx2CustomTransmitCreate**.

Before calling **SerCx2CustomTransmitCreate**, the serial controller driver must call the [SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_config_init) function to initialize the [SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config) structure pointed to by *CustomTransmitConfig*. This function sets the following members of the structure to zero:

* **Alignment**
* **MinimumTransactionLength**
* **MaximumTransactionLength**
* **MinimumTransferUnit**
* **Exclusive**

If necessary, the serial controller driver can set any of these members to nonzero values after the initialization function returns. However, for convenience, **SerCx2CustomTransmitCreate** uses the following default values if these members are zero:

* If **Alignment** is zero, SerCx2 sets the data alignment value to one, which means the write buffer can start on an arbitrary byte boundary in memory.
* If **MinimumTransactionLength** is zero, SerCx2 sets the minimum transaction length to one byte.
* If **MaximumTransactionLength** is zero, SerCx2 sets the maximum transaction length to ((ULONG)-1).
* If **MinimumTransferUnit** is zero, SerCx2 sets the minimum transfer unit to one byte.
* If **Exclusive** is zero (**FALSE**), exclusive mode is disabled.

If the calling driver sets **Exclusive** to **TRUE**, the **MinimumTransferUnit**, **Alignment**, and **MinimumTransactionLength** members must be zero. For more information, see [SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config).

As an option, a serial controller driver can use the *Attributes* parameter to create a context for the custom-transmit object, and to supply pointers to [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) and [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) functions that are called to prepare the object for deletion. For more information, see [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes).

If the *Attributes* parameter points to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, the caller must not overwrite the values that the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) initialization function writes to the **ParentObject**, **ExecutionLevel**, and **SynchronizationScope** members of this structure.

For more information about creating custom-transmit objects, see [SERCX2CUSTOMTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles). For more information about custom-transmit transactions, see [SerCx2 Custom-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265320(v=vs.85)).

## See also

[EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup)

[EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SERCX2CUSTOMTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config)

[SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_config_init)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)