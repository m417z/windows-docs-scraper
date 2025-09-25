# WdfIoTargetWdmGetTargetDeviceObject function

## Description

\[Applies to KMDF only\]

The **WdfIoTargetWdmGetTargetDeviceObject** method returns a pointer to the Windows Driver Model (WDM) device object that is associated with a specified local or remote I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to **[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)** or **[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)** or from a method that a specialized I/O target supplies.

## Return value

**WdfIoTargetWdmGetTargetDeviceObject** returns a pointer to a WDM **[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)** structure.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Most framework-based drivers do not need to access an I/O target's WDM device object.

The pointer that the **WdfIoTargetWdmGetTargetDeviceObject** method returns is valid until the driver calls **[WdfIoTargetClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetclose)** or **[WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove)**, or until the remote I/O target object is deleted. If the driver provides an **[EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup)** function for the remote I/O target object, and if the object is deleted before the remote I/O target is closed, the pointer is valid until the *EvtCleanupCallback* function returns.

If the driver attempts to access the WDM device object after it has been removed, the driver can cause the system to crash. The [toastmon](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample demonstrates how the driver can provide an **[EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove)** callback function so that it is notified if the I/O target is removed.

For more information about **WdfIoTargetWdmGetTargetDeviceObject**, see [Obtaining Information About a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-a-general-i-o-target).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

> [!NOTE]
> The framework does not take a reference on the target device object before returning it to the driver. The caller does not need to dereference it unless it explicitly adds a reference.

### Examples

The following code example checks an I/O target's WDM DEVICE_OBJECT structure to verify that the target supports direct I/O operations.

```cpp
if (!((WdfIoTargetWdmGetTargetDeviceObject(Adapter->IoTarget))->Flags
 & DO_DIRECT_IO)) {
    ASSERTMSG("Target device doesn't support direct I/O\n", FALSE);
    return STATUS_INVALID_DEVICE_REQUEST;
}
```

## See also

- **[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)**
- **[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)**
- **[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)**
- **[WdfIoTargetWdmGetTargetFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetwdmgettargetfilehandle)**
- **[WdfIoTargetWdmGetTargetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetwdmgettargetfileobject)**