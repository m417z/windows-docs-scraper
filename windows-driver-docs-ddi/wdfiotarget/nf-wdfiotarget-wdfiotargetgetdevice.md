# WdfIoTargetGetDevice function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetGetDevice** method returns a handle to the framework device object that is the parent of the specified local or remote I/O target.

## Parameters

### `IoTarget` [in]

A handle to an I/O target object. This handle is obtained from [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget), [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a [specialized I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/introduction-to-i-o-targets) supplies (such as [WdfUsbTargetDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetiotarget)).

## Return value

**WdfIoTargetGetDevice** returns a handle to a framework device object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about **WdfIoTargetGetDevice**, see [Obtaining Information About a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-a-general-i-o-target).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example is shows how an [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function can call **WdfIoTargetGetDevice**.

```cpp
NTSTATUS
MyEvtIoTargetQueryRemove(
    WDFIOTARGET IoTarget
)
{
WDFDEVICE device;
...
device = WdfIoTargetGetDevice(IoTarget);
...
}
```

## See also

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfUsbTargetDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetiotarget)