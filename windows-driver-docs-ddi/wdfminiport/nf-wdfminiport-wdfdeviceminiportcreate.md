# WdfDeviceMiniportCreate function

## Description

[Applies to KMDF only]

The **WdfDeviceMiniportCreate** method creates a framework device object that a miniport driver can use.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object, obtained by a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate).

### `Attributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `DeviceObject` [in]

A pointer to a WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object (FDO) for the miniport driver.

### `AttachedDeviceObject` [in, optional]

A pointer to a WDM DEVICE_OBJECT structure that represents the next-lower device object in the device stack.

### `Pdo` [in, optional]

A pointer to a WDM DEVICE_OBJECT structure that represents the physical device object (PDO) for the device.

### `Device` [out]

A pointer to a location that receives a handle to the new framework device object.

## Return value

If the **WdfDeviceMiniportCreate** method encounters no errors, it returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | A device object could not be allocated. |

For a list of other return values that **WdfDeviceMiniportCreate** can return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If your miniport driver uses the framework, the miniport driver should call **WdfDeviceMiniportCreate** when its port driver informs it that a device is available. Miniport drivers do not call [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

Your miniport driver might receive its *DeviceObject*, *AttachedDeviceObject*, and *PDO* pointers from its port driver. For example, an NDIS miniport driver can obtain these pointers by calling [NdisMGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetdeviceproperty).

The following restrictions apply to framework device objects that a miniport driver obtains by calling **WdfDeviceMiniportCreate**:

* The device that the device object represents must support Plug and Play.
* The device object does not support any of the device object's event callback functions. Therefore, the port driver must handle all Plug and Play (PnP) and power management operations.
* The device object handle cannot be passed to [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate), so the port driver must provide any required support for Windows Management Instrumentation (WMI).
* The device object handle cannot be passed to [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate), so the framework does not support I/O queues for miniport drivers.
* The device object handle cannot be passed to [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate), so the framework does not support interrupt objects for miniport drivers.
* The device object handle cannot be passed to any general framework device object methods except [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget), [WdfDeviceWdmGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetdeviceobject), [WdfDeviceWdmGetAttachedDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetattacheddevice), and [WdfDeviceWdmGetPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetphysicaldevice).
* The device object handle cannot be passed to any [framework FDO methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/) except [WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface).
* The device object handle cannot be passed to any [framework PDO methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/) or to [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate), so the miniport driver cannot be a bus driver.
* The driver must eventually call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) to delete the device object that **WdfDeviceMiniportCreate** creates.

Framework device objects that **WdfDeviceMiniportCreate** create can be used as a parent object for any subsequently created framework object.

In order to send I/O requests to I/O targets, the miniport driver might pass the device object handle to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget), [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

The miniport driver can pass the device object handle to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate) if the device supports DMA operations.

For more information about miniport drivers, see [Using Kernel-Mode Driver Framework with Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-kmdf-miniport-drivers).

#### Examples

The following code example calls [NdisMGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetdeviceproperty) to obtain *DeviceObject*, *AttachedDeviceObject*, and *PDO* pointers; initializes the device object's context space, and creates a miniport device object.

```cpp
WDF_OBJECT_ATTRIBUTES  ObjectAttributes;

NdisMGetDeviceProperty(
                       MiniportAdapterHandle,
                       &Adapter->Pdo,
                       &Adapter->Fdo,
                       &Adapter->NextDeviceObject,
                       NULL,
                       NULL
                       );
WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                        &ObjectAttributes,
                                        WDF_DEVICE_INFO
                                        );
ntStatus = WdfDeviceMiniportCreate(
                                   WdfGetDriver(),
                                   &ObjectAttributes,
                                   Adapter->Fdo,
                                   Adapter->NextDeviceObject,
                                   Adapter->Pdo,
                                   &Adapter->WdfDevice
                                   );
if (!NT_SUCCESS (ntStatus)) {
    Status = NDIS_STATUS_FAILURE;
    break;
}
```

## See also

[WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfDriverMiniportUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdriverminiportunload)