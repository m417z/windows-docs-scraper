# WdfDeviceCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceCreate** method creates a framework device object.

## Parameters

### `DeviceInit` [in, out]

The address of a pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure. If **WdfDeviceCreate** encounters no errors, it sets the pointer to **NULL**.

### `DeviceAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Device` [out]

A pointer to a location that receives a handle to the new framework device object.

## Return value

If the **WdfDeviceCreate** method encounters no errors, it returns STATUS_SUCCESS. Additional return values include:

|Return code|Description|
|--- |--- |
|**STATUS_INVALID_PARAMETER**|An invalid *Device* or *DeviceInit* handle is supplied.|
|**STATUS_INVALID_DEVICE_STATE**|The driver has already created a device object for the device.|
|**STATUS_INVALID_SECURITY_DESCR**|The driver called **WdfDeviceInitAssignSDDLString** or **WdfDeviceInitSetDeviceClass** but did not provide a name for the device object.|
|**STATUS_INSUFFICIENT_RESOURCES**|A device object could not be allocated.|
|**STATUS_OBJECT_NAME_COLLISION**|The device name that was specified by a call to **WdfDeviceInitAssignName** already exists. The driver can call **WdfDeviceInitAssignName** again to assign a new name.|

For a list of other return values that **WdfDeviceCreate** can return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Before calling **WdfDeviceCreate**, the driver must call framework-supplied functions that initialize the WDFDEVICE_INIT structure. For more information about initializing this structure, see [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init). If the driver encounters errors while calling the initialization functions, it must not call **WdfDeviceCreate**. In this case, the driver might have to call [WdfDeviceInitFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitfree). For information about when to call **WdfDeviceInitFree**, see [WdfDeviceInitFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitfree).

A call to **WdfDeviceCreate** creates a framework device object that represents either a functional device object (FDO) or a physical device object (PDO). The type of device object that the function creates depends on how the driver obtained the WDFDEVICE_INIT structure:

* If the driver received the WDFDEVICE_INIT structure from an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback, **WdfDeviceCreate** creates an FDO.
* If the driver received the WDFDEVICE_INIT structure from an [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) callback, or from a call to [WdfPdoInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate), **WdfDeviceCreate** creates a PDO.

After the driver calls **WdfDeviceCreate**, it can no longer access the WDFDEVICE_INIT structure.

Miniport drivers that use the framework must call [WdfDeviceMiniportCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdeviceminiportcreate) instead of **WdfDeviceCreate**.

The parent of each framework device object is the driver's framework driver object. The driver cannot change this parent, and the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**. The framework deletes each framework device object (except for some [control device objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects)) when the Plug and Play (PnP) manager determines that the device has been removed.

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the framework device object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about creating device objects, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example shows how an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function might initialize and create a device object.

```cpp
NTSTATUS
MyEvtDeviceAdd(
    IN WDFDRIVER  Driver,
    IN PWDFDEVICE_INIT  DeviceInit
    )
{
    WDF_PNPPOWER_EVENT_CALLBACKS  pnpPowerCallbacks;
    WDF_OBJECT_ATTRIBUTES  attributes;
    NTSTATUS  status;
    WDFDEVICE  device;

    //
    // Initialize the WDF_PNPPOWER_EVENT_CALLBACKS structure.
    //
    WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpPowerCallbacks);
    pnpPowerCallbacks.EvtDevicePrepareHardware = MyEvtDevicePrepareHardware;
    pnpPowerCallbacks.EvtDeviceD0Entry = MyEvtDeviceD0Entry;
    pnpPowerCallbacks.EvtDeviceD0Exit  = MyEvtDeviceD0Exit;
    WdfDeviceInitSetPnpPowerEventCallbacks(
                                           DeviceInit,
                                           &pnpPowerCallbacks
                                           );
    //
    // This driver uses buffered I/O.
    //
    WdfDeviceInitSetIoType(
                           DeviceInit,
                           WdfDeviceIoBuffered
                           );

    //
    // Specify the device object's context space by
    // using a driver-defined DEVICE_CONTEXT structure.
 //
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                            &attributes,
                                            DEVICE_CONTEXT
                                            );
 //
    // Create the device object.
    //
    status = WdfDeviceCreate(
                             &DeviceInit,
                             &attributes,
                             &device
                             );
    if (!NT_SUCCESS(status)) {
        return status;
    }
    return STATUS_SUCCESS;
}
```

## See also

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type)

[WDF_PNPPOWER_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_pnppower_event_callbacks_init)

[WdfDeviceInitFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitfree)

[WdfDeviceInitSetIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype)

[WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks)

[WdfDeviceMiniportCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdeviceminiportcreate)