# _SERCX2_CONFIG structure

## Description

The **SERCX2_CONFIG** structure contains configuration information for version 2 of the serial framework extension (SerCx2).

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `EvtSerCx2FileOpen`

A pointer to the driver-implemented [EvtSerCx2FileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_fileopen) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function. However, a driver that implements this function must also implement an *EvtSerCx2FileClose* function.

### `EvtSerCx2FileClose`

A pointer to the driver-implemented [EvtSerCx2FileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_fileclose) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SetWaitMask`

A pointer to the driver-implemented [EvtSerCx2SetWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_set_wait_mask) event callback function. This member must point to a valid function.

### `EvtSerCx2PurgeFifos`

A pointer to the driver-implemented [EvtSerCx2PurgeFifos](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_purge_fifos) event callback function. This member must point to a valid function.

### `EvtSerCx2Control`

A pointer to the driver-implemented [EvtSerCx2Control](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_control) event callback function. This member must point to a valid function.

### `EvtSerCx2ApplyConfig`

A pointer to the driver-implemented [EvtSerCx2ApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_apply_config) event callback function. This member must point to a valid function.

### `EvtSerCx2SelectNextReceiveTransactionType`

A pointer to the driver-implemented [EvtSerCx2SelectNextReceiveTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_receive_transaction_type) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `EvtSerCx2SelectNextTransmitTransactionType`

A pointer to the driver-implemented [EvtSerCx2SelectNextTransmitTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_transmit_transaction_type) event callback function. This member is optional and can be set to **NULL** to indicate that the driver does not implement the function.

### `RequestAttributes`

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes the attributes to assign to the framework request objects that SerCx2 passes to the serial controller driver. Before calling the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method, the caller must call the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function to initialize the structure. This member is optional and can be specified as WDF_NO_OBJECT_ATTRIBUTES if the serial controller driver does not need to assign attributes to the object. For more information, see Remarks.

## Remarks

The [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method accepts a pointer to a **SERCX2_CONFIG** structure as an input parameter. Before calling **SerCx2InitializeDevice**, call the [SERCX2_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_config_init) function to initialize this structure.

If the **RequestAttributes** member points to a **WDF_OBJECT_ATTRIBUTES** structure, the caller must not overwrite the values that the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) initialization function writes to the **ParentObject**, **ExecutionLevel**, and **SynchronizationScope** members of this structure.

A driver might need to store information in context areas in the framework request objects that the driver receives. Typically, the driver calls the [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes) method to specify the required attributes for request objects. These attributes include the name and size of the context area in each request object. Additionally, in the current implementation of SerCx2, a serial controller driver that requires a request context should specify these same attributes in the **RequestAttributes** member of the **SERCX2_CONFIG** structure that the driver passes to **SerCx2InitializeDevice**. That is, the driver should specify the same request attributes twice—in the **SerCx2InitializeDevice** call, and in the **WdfDeviceInitSetRequestAttributes** call. For more information, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)) and [SerCx2 Custom-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265320(v=vs.85)).

A driver that never needs a request context does not need to call **WdfDeviceInitSetRequestAttributes**, and can set the **RequestAttributes** member of the **SERCX2_CONFIG** structure to WDF_NO_OBJECT_ATTRIBUTES.

## See also

[EvtSerCx2ApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_apply_config)

[EvtSerCx2Control](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_control)

[EvtSerCx2FileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_fileclose)

[EvtSerCx2FileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_fileopen)

[EvtSerCx2PurgeFifos](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_purge_fifos)

[EvtSerCx2SelectNextReceiveTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_receive_transaction_type)

[EvtSerCx2SelectNextTransmitTransactionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_select_next_transmit_transaction_type)

[EvtSerCx2SetWaitmask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_set_wait_mask)

[SERCX2_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_config_init)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)