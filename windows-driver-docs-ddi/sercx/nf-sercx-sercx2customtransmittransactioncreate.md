# SerCx2CustomTransmitTransactionCreate function

## Description

The **SerCx2CustomTransmitTransactionCreate** method creates a custom-transmit-transaction object, which version 2 of the serial framework extension (SerCx2) uses to perform custom-transmit transactions.

## Parameters

### `CustomTransmit` [in]

A [SERCX2CUSTOMTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-transmit object. The serial controller driver previously called the [SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate) method to create this object.

### `CustomTransmitTransactionConfig` [in]

A pointer to a [SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_transaction_config) structure. Before calling this method, the caller must call the [SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_transaction_config_init) function to initialize the structure. This structure contains pointers to a set of event callback routines that are implemented by the serial controller driver. SerCx2 calls these functions to do an I/O transaction that uses the custom data-transfer mechanism to write data to the serial controller to be transmitted.

### `Attributes` [in]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes the attributes to assign to the new custom-transmit-transaction object. Before calling this method, the caller must call the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function to initialize the structure. This parameter is optional and can be specified as WDF_NO_OBJECT_ATTRIBUTES if the serial controller driver does not need to assign attributes to the object. For more information, see Remarks.

### `CustomTransmitTransaction` [out]

A pointer to a location to which this method writes a [SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to the newly created custom-transmit-transaction object. SerCx2 and the serial controller driver use this handle in subsequent calls to refer to this object.

## Return value

This method returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | A custom-transmit-transaction object already exists from a previous **SerCx2CustomTransmitTransactionCreate** call. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *CustomTransmitTransactionConfig*->**Size** value does not equal **sizeof**(**SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG**). |
| **STATUS_INVALID_PARAMETER** | A parameter value is not valid. The caller must supply a valid [EvtSerCx2CustomTransmitTransactionStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_start) function pointer. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to create the custom-transmit-transaction object. |

## Remarks

Your serial controller driver can call this method to create a custom-transmit-transaction object. SerCx2 uses this object to manage custom-transmit transactions, which are I/O transactions that use a custom data-transfer mechanism to write data to the serial controller to be transmitted.

As an option, a serial controller driver can use the *Attributes* parameter to create a context for the custom-transmit object, and to supply pointers to [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) and [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) functions that are called to prepare the object for deletion. For more information, see [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes).

If the *Attributes* parameter points to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, the caller must not overwrite the values that the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) initialization function writes to the **ParentObject**, **ExecutionLevel**, and **SynchronizationScope** members of this structure.

If the specified combination of implemented callback functions is not valid, **SerCx2CustomTransmitTransactionCreate** fails and returns STATUS_INVALID_PARAMETER.

For more information about creating custom-transmit-transaction objects, see [SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles). For more information about custom-transmit transactions, see [SerCx2 Custom-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265320(v=vs.85)).

## See also

[EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup)

[EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy)

[EvtSerCx2CustomTransmitTransactionStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_transmit_transaction_start)

[SERCX2CUSTOMTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_transaction_config)

[SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_transaction_config_init)

[SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)