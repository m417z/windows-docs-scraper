# WdfRequestCreateFromIrp function

## Description

[Applies to KMDF only]

The **WdfRequestCreateFromIrp** method creates a framework request object from a specified WDM IRP.

## Parameters

### `RequestAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the request object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Irp` [in]

A pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that contains a WDM I/O request packet.

### `RequestFreesIrp` [in]

A Boolean value that, if **TRUE**, indicates that the framework removes the IRP when the request handle is destroyed. If **FALSE**, the driver must call [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp) to remove the IRP, using the steps that the following Examples section demonstrates.

### `Request` [out]

A pointer to a location that receives a handle to a framework request object.

## Return value

**WdfRequestCreateFromIrp** returns STATUS_SUCCESS if the operation succeeds. For a list of additional return values, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Typically, framework-based drivers call **WdfRequestCreateFromIrp** only if they receive WDM IRPs in a WDM dispatch routine and then forward the requests to framework I/O targets.

If a driver calls **WdfRequestCreateFromIrp** to create a request object, it must not call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) for the request object. Instead, the driver must call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) when it has finished using the request object.

In addition, the driver must not call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory), [WdfRequestRetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputbuffer), [WdfRequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer), or [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) with the new request object.

By default, the new request object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method created. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the request object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the request object when it has finished using the object; otherwise, the request object will remain until the I/O manager unloads your driver.

For more information about creating framework request objects, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects).

Framework-based drivers must not use the **Tail.Overlay.DriverContext** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure, because the framework uses this member.

#### Examples

**Example 1**

The following code example creates a framework request object from a specified WDM IRP and then deletes it. This example sets the *RequestFreesIrp* parameter to **TRUE**, so the framework removes the IRP when the request handle is destroyed.

```cpp
WDFREQUEST request;
PIRP irp;

//Creation
status = WdfRequestCreateFromIrp(
                                 WDF_NO_OBJECT_ATTRIBUTES,
                                 irp,
                                 TRUE,
                                 &request
                                 );
...
//Deletion
WdfObjectDelete(request);
```
**Example 2**

The following code example also creates a framework request object from a specified WDM IRP and then deletes it. This example sets the *RequestFreesIrp* parameter to **FALSE**, so the driver must call [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp) to remove the IRP. All of the function calls in the example are required.

```cpp
WDF_REQUEST_REUSE_PARAMS params;
WDFREQUEST request;
PIRP irp;

//Creation
status = WdfRequestCreateFromIrp(
                                 WDF_NO_OBJECT_ATTRIBUTES,
                                 irp,
                                 FALSE,
                                 &request
                                 );
...
//Deletion
WDF_REQUEST_REUSE_PARAMS_INIT(
                              &params,
                              WDF_REQUEST_REUSE_NO_FLAGS,
                              STATUS_SUCCESS
                              );
WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP(
                                     &params,
                                     NULL
                                     );
status = WdfRequestReuse(
                         request,
                         &params
                         );
ASSERT(NT_SUCCESS(status));
IoFreeIrp(irp);
WdfObjectDelete(request);
```

## See also

[IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)