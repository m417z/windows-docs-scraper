# WdfDeviceInitSetRequestAttributes function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceInitSetRequestAttributes** method sets object attributes that will be used for all of the framework request objects that the framework delivers to the driver from the device's I/O queues.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `RequestAttributes` [in]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the device's request objects.

## Remarks

Your driver can call **WdfDeviceInitSetRequestAttributes** to specify the object context space that the framework will assign to the request objects that it creates for your driver. For more information about this context space, see [Using Request Object Context](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-request-object-context).

The framework does not use the specified object attributes for request objects that it creates when a driver calls [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) or [WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp).

Your driver must call **WdfDeviceInitSetRequestAttributes** from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and calls **WdfDeviceInitSetRequestAttributes**.

```cpp
typedef struct _REQUEST_CONTEXT {
  ULONG_PTR  Information;
} REQUEST_CONTEXT, *PREQUEST_CONTEXT;
WDF_OBJECT_ATTRIBUTES  attributes;

WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                        &attributes,
                                        REQUEST_CONTEXT
                                        );
WdfDeviceInitSetRequestAttributes(
                                  DeviceInit,
                                  &attributes
                                  );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)