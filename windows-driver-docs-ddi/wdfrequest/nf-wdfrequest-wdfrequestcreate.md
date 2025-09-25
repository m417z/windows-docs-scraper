# WdfRequestCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestCreate** method creates an empty framework request object.

## Parameters

### `RequestAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the request object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `IoTarget` [in, optional]

A handle to a framework I/O target object. This parameter is optional and can be **NULL**. If non-**NULL**, **WdfRequestCreate** verifies that the driver can eventually send the request to the specified I/O target.

### `Request` [out]

A pointer to a location that receives a handle to a framework request object.

## Return value

**WdfRequestCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | There are insufficient system resources to complete the operation. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The request's array of I/O stack locations is not large enough to allow the driver to send the request to the specified I/O target. |

For a list of additional return values, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A framework-based driver can call **WdfRequestCreate** to create a new request that the driver subsequently passes to other framework functions for initialization. For example, a driver for a USB device might call [WdfUsbTargetPipeFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforread) to format a new read request.

A framework-based driver that communicates with WDM drivers might specify the contents of a request by calling [WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp).

If a driver calls **WdfRequestCreate** to create a request object, it must not call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) for the request object. Instead, the driver must call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) when it has finished using the request object. For more information, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

By default, the new request object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method created. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the request object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the request object when it has finished using the object; otherwise, the request object will remain until the I/O manager unloads your driver.

For more information about calling **WdfRequestCreate**, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects).

#### Examples

The following code example creates an I/O target object, initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, and calls **WdfRequestCreate**. The new request object's parent is the I/O target object.

```cpp
WDF_OBJECT_ATTRIBUTES  attributes;
WDFREQUEST newRequest;
WDFIOTARGET ioTarget;
...
status = WdfIoTargetCreate(
                           Device,
                           WDF_NO_OBJECT_ATTRIBUTES,
                           &ioTarget
                           );
  ...
WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = ioTarget;

status = WdfRequestCreate(
                          &attributes,
                          ioTarget,
                          &newRequest
                          );

if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)