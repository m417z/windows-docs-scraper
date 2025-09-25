# WdfPdoInitAllowForwardingRequestToParent function

## Description

[Applies to KMDF only]

The **WdfPdoInitAllowForwardingRequestToParent** method enables a driver's ability to call [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue).

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Remarks

If your driver uses [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue) to requeue I/O requests from a child device's I/O queue to a parent device's I/O queue, the driver must call **WdfPdoInitAllowForwardingRequestToParent** before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create a physical device object (PDO) for the child device. For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about **WdfPdoInitAllowForwardingRequestToParent** and [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue), see [Requeuing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/requeuing-i-o-requests).

#### Examples

The following code example enables a driver's ability to call [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue).

```cpp
WdfPdoInitAllowForwardingRequestToParent(pDeviceInit);
```

## See also

[WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue)