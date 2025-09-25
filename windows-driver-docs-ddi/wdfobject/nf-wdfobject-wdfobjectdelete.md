# WdfObjectDelete function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectDelete** method deletes a framework object and its child objects.

## Parameters

### `Object` [in]

A handle to framework object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

> [!NOTE]
> Callback functions that are called at PASSIVE_LEVEL cannot delete timer objects. For more info, see [*EVT_WDF_TIMER* callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer#remarks).

After a driver calls **WdfObjectDelete**, the specified object is deleted after its reference count becomes zero.

Drivers cannot call **WdfObjectDelete** to delete the following framework objects, because the framework always handles deletion of these objects:

* Framework child-list objects (WDFCHILDLIST)
* Framework device objects (WDFDEVICE), unless the driver has called [WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate) and created a [control device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects), which the driver must sometimes delete
* Framework driver objects (WDFDRIVER)
* Framework file objects (WDFFILEOBJECT)
* Framework interrupt objects (WDFINTERRUPT)
* Framework queue objects (WDFQUEUE), if an object represents a [default I/O queue](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues) or if the driver has called [WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching) to set up the queue to receive all I/O requests of a particular type
* Framework USB pipe objects (WDFUSBPIPE)
* Framework USB interface objects (WDFUSBINTERFACE)
* Framework WMI provider objects (WDFWMIPROVIDER)
* Resource range list object
  (WDFIORESLIST)
* Resource list object
  (WDFCMRESLIST)
* Resource requirements list object
  (WDFIORESREQLIST)

See [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects) for a complete list of framework objects.

The **WdfObjectDelete** method can return before the framework has deleted the object and its child objects. The order in which the framework deletes child objects is not predictable.

For more information about **WdfObjectDelete** and the cleanup rules for a framework object hierarchy, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

The **WdfObjectDelete** method must be called at IRQL <= DISPATCH_LEVEL. If your driver is deleting a control device object, **WdfObjectDelete** must be called at IRQL = PASSIVE_LEVEL. Similarly, if your driver is deleting a common buffer, **WdfObjectDelete** must be called at IRQL = PASSIVE_LEVEL.

#### Examples

The following code example deletes a framework object and its child objects.

```cpp
WdfObjectDelete(Object);
```

## See also

[WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate)

[WdfObjectCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectcreate)