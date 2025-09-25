# WdfIoTargetWdmGetTargetPhysicalDevice function

## Description

[Applies to KMDF only]

The **WdfIoTargetWdmGetTargetPhysicalDevice** method returns a pointer to the Windows Driver Model (WDM) physical device object (PDO) that represents a remote I/O target's device.

## Parameters

### `IoTarget` [in]

A handle to a remote I/O target object. This handle was obtained from a previous call to [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate).

## Return value

If the I/O target represents a PnP device, **WdfIoTargetWdmGetTargetPhysicalDevice** returns a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents a remote I/O target's PDO. Otherwise the method returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The pointer that the **WdfIoTargetWdmGetTargetPhysicalDevice** method returns is valid until the driver calls [WdfIoTargetClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetclose) or [WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove), or until the remote I/O target object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the remote I/O target object, and if the object is deleted before the remote I/O target is closed, the pointer is valid until the *EvtCleanupCallback* function returns.

If the driver attempts to access the WDM device object after it has been removed, the driver can cause the system to crash. The [toastmon](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample demonstrates how the driver can provide an [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function so that it is notified if the I/O target is removed.

For more information about **WdfIoTargetWdmGetTargetPhysicalDevice**, see [Obtaining Information About a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-a-general-i-o-target).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example obtains a pointer to a DEVICE_OBJECT structure that represents the PDO of a remote I/O target's device.

```cpp
PDEVICE_OBJECT  pTargetDO;

pTargetDO = WdfIoTargetWdmGetTargetPhysicalDevice(IoTarget);
```

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)