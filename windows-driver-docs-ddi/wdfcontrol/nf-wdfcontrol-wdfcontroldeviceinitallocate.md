# WdfControlDeviceInitAllocate function

## Description

[Applies to KMDF only]

The **WdfControlDeviceInitAllocate** method allocates a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that a driver uses when creating a new control device object.

## Parameters

### `Driver` [in]

A handle to a framework driver object.

### `SDDLString` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that describes a Unicode string. This string is a Security Descriptor Definition Language (SDDL) representation of a security descriptor. For more information, see the following Remarks section.

## Return value

**WdfControlDeviceInitAllocate** returns a pointer to a framework-allocated [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure, if the operation succeeds. Otherwise, the method returns **NULL**.

## Remarks

If you want your driver to create a control device object, the driver must call **WdfControlDeviceInitAllocate** to obtain a WDFDEVICE_INIT structure that it can pass to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

Your driver can specify a security setting by using a subset of SDDL. The *Wdmsec.h* file defines a set of SDDL_DEVOBJ_*Xxx*-formatted constants that you can use. For more information about security descriptors and SDDL, see [Securing Device Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/securing-device-objects).

The [WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring) method overwrites the security setting, if any, that **WdfControlDeviceInitAllocate** specifies.

For more information about calling **WdfControlDeviceInitAllocate**, see [Using Control Device Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

#### Examples

The following code example allocates a DEVICE_INIT structure, assigns a device object name, registers a shutdown notification callback function, and creates a control device object. For a more complex example that uses **WdfControlDeviceInitAllocate**, see the [NONPNP](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver or the [NDISProt](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver.

```cpp
PWDFDEVICE_INIT  deviceInit = NULL;
NTSTATUS  status;
WDF_OBJECT_ATTRIBUTES  objectAttribs;

deviceInit = WdfControlDeviceInitAllocate(
                                          hDriver,
                                          &SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_RW_RES_R
                                          );
if (deviceInit == NULL) {
    status = STATUS_INSUFFICIENT_RESOURCES;
    goto Error;
}
status = WdfDeviceInitAssignName(
                                 deviceInit,
                                 &ntDeviceName
                                 );
if (!NT_SUCCESS(status)) {
    WdfDeviceInitFree(deviceInit);
    deviceInit = NULL;
    goto Error;
}
WdfControlDeviceInitSetShutdownNotification(
                                            deviceInit,
                                            EvtShutdownNotification,
                                            WdfDeviceShutdown
                                            );
WDF_OBJECT_ATTRIBUTES_INIT(&objectAttribs);

status = WdfDeviceCreate(
                         &deviceInit,
                         &objectAttribs,
                         &controlDevice
                         );
if (!NT_SUCCESS(status)) {
    WdfDeviceInitFree(deviceInit);
    deviceInit = NULL;
    goto Error;
}
WdfControlFinishInitializing(controlDevice);
```

## See also

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfControlDeviceInitSetShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitsetshutdownnotification)

[WdfControlFinishInitializing](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontrolfinishinitializing)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfDeviceInitAssignName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignname)

[WdfDeviceInitAssignSDDLString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitassignsddlstring)