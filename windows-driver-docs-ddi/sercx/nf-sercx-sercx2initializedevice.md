# SerCx2InitializeDevice function

## Description

The **SerCx2InitializeDevice** method finishes initializing the framework device object for the serial controller.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. For more information, see Remarks.

### `Config` [in]

A pointer to a caller-allocated [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config) structure that contains pointers to a set of event callback functions that are implemented by the serial controller driver. Version 2 of the serial framework controller (SerCx2) calls these functions to configure the serial controller and to perform basic operations that are independent of the I/O transaction types (PIO, system DMA, or custom) that the driver supports.

## Return value

**SerCx2InitializeDevice** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The method was called at the wrong IRQL, or the *Device* parameter is not a valid WDFDEVICE handle. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *Config*->**Size** value does not equal **sizeof**(**SERCX2_CONFIG**). |
| **STATUS_INVALID_PARAMETER** | The **RequestAttributes** member is not valid, or required callback functions are missing from the list of function pointers. For more information, see Remarks. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to perform the requested operation. |

## Remarks

Before calling this method, the serial controller driver must previously have called the [SerCx2InitializeDeviceInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedeviceinit) method.

The serial controller driver must call this method from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function after it creates a framework device object for the serial controller. The driver typically calls a method such as [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create the framework device object and to obtain a WDFDEVICE handle to this object.

Three of the function pointers in the [SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config) structure are required by SerCx2. The driver must implement the [EvtSerCx2PurgeFifos](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_purge_fifos), [EvtSerCx2Control](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_control), and [EvtSerCx2ApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_apply_config) callback functions. Otherwise, the **SerCx2InitializeDevice** call fails and returns STATUS_INVALID_PARAMETER.

If the **RequestAttributes** member of the **SERCX2_CONFIG** structure is set to a value other than WDF_NO_OBJECT_ATTRIBUTES, the driver must not overwrite the values written to the **ParentObject**, **ExecutionLevel**, and **SynchronizationScope** members of this structure by the [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function. Otherwise, the **SerCx2InitializeDevice** call fails and returns STATUS_INVALID_PARAMETER.

If the driver calls the [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes) method to set the attributes to use for request objects, the request attributes specified in this call must match the request attributes that the driver specifies in the call to **SerCx2InitializeDevice**. For more information, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)) and [SerCx2 Custom-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265320(v=vs.85)).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SERCX2_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_config)

[SerCx2InitializeDeviceInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedeviceinit)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes)