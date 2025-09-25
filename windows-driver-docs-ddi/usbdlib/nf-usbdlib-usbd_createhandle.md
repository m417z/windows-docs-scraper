# USBD_CreateHandle function

## Description

The **USBD_CreateHandle** routine is called by a WDM USB client driver to obtain a USBD handle. The routine registers the client driver with the underlying USB driver stack.

**Note for Windows Driver Framework (WDF) Drivers:** If your client driver is a WDF-based driver, then you do not need the USBD handle. The client driver is registered in its call to the [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters) method.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the client driver.

### `TargetDeviceObject` [in]

Pointer to the next lower device object in the device stack. The client driver receives a pointer to that device object in a previous call to [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack).

### `USBDClientContractVersion` [in]

The contract version that the client driver supports. *USBDClientContractVersion* must be USBD_CLIENT_CONTRACT_VERSION_602. For more information, see Remarks.

### `PoolTag` [in]

The pool tag used for memory allocations.

### `USBDHandle` [out]

Opaque handle that indicates that the client driver was registered with the USB driver stack. For more information, see Remarks.

## Return value

The routine returns an NTSTATUS code. Possible values include but are not limited to, these values in the following table.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine call succeeded. |
| **STATUS_INVALID_LEVEL** | The caller is not running at the IRQL value PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | The caller passed one of the following invalid parameter values:<br><br>* *DeviceObject*, *TargetDeviceObject*, or *USBDHandle* is NULL.<br>* The client contract value specified in *USBDClientContractVersion* is not valid.<br>* *PoolTag* is zero. |

## Remarks

### Version Registration

Windows 8 includes a new USB driver stack to support USB 3.0 devices. The new USB driver stack provides several new capabilities, such as stream support, chained MDLs, and so on.
Before your client driver can use any of those USB capabilities, you must register the client driver with the USB driver stack and obtain a USBD handle. The handle is required in order to call routines that use or configure the new capabilities. To obtain a USBD handle, call **USBD_CreateHandle**.

The client driver must call **USBD_CreateHandle** regardless of whether the device is attached to a USB 3.0, 2.0, or 1.1 host controller. If the device is attached to a USB 3.0 host controller, Windows loads the USB 3.0 driver stack. Otherwise, USB 2.0 driver stack is loaded. In either case, the client driver is *not* required to know the version supported by the underlying USB driver stack. **USBD_CreateHandle** assesses the driver stack version and allocates resources appropriately.

The client driver must specify USBD_CLIENT_CONTRACT_VERSION_602 in the *USBDClientContractVersion* parameter and follow the set of rules described in [Best Practices: Using URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-driver-contract-in-windows-8).

### Calling USBD_CreateHandle

The **USBD_CreateHandle** routine must be called by a Windows Driver Model (WDM) client driver before the driver send any other requests, through URBs or IOCTLs, to the USB driver stack. Typically, the client driver obtains the USBD handle in its AddDevice routine.

A Windows Driver Frameworks (WDF) client driver is not required to call **USBD_CreateHandle** because the framework calls this routine on behalf of the client driver during the device initialization phase. Instead, the client driver can specify its client contract version in the [WDF_USB_DEVICE_CREATE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_create_config) structure and pass it in the call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### USBD_CreateHandle Call Completion

If the **USBD_CreateHandle** call succeeds, a valid *USBD handle* is obtained in the *USBDHandle* parameter. The client driver must use the USBD handle in the client driver's future requests to the USB driver stack.

If the **USBD_CreateHandle** call fails, the client driver can fail the AddDevice routine.

After the client driver is finished using the USBD handle, the driver must close the handle by calling the [USBD_CloseHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_closehandle) routine.

#### Examples

The following example code shows how to register a client driver by calling **USBD_CreateHandle**.

```C++
DRIVER_ADD_DEVICE MyAddDevice;

NTSTATUS MyAddDevice( __in PDRIVER_OBJECT  DriverObject,
                     __in PDEVICE_OBJECT  PhysicalDeviceObject)
{

    NTSTATUS            ntStatus;
    PDEVICE_OBJECT      deviceObject;
    PDEVICE_EXTENSION   deviceExtension;
    PDEVICE_OBJECT      stackDeviceObject;
    USBD_HANDLE         usbdHandle;

    ...

        ntStatus = IoCreateDevice(DriverObject,
        sizeof(DEVICE_EXTENSION),
        NULL,
        FILE_DEVICE_UNKNOWN,
        FILE_AUTOGENERATED_DEVICE_NAME,
        FALSE,
        &deviceObject);

    if (!NT_SUCCESS(ntStatus))
    {
        return ntStatus;
    }

    ...

        //     Attach the FDO to the top of the PDO in the client driver's
        //  device stack.

        deviceExtension->StackDeviceObject = IoAttachDeviceToDeviceStack (
        deviceObject,
        PhysicalDeviceObject);

    ...

        // Initialize the DeviceExtension

        deviceExtension = deviceObject->DeviceExtension;

    ...

        //Register the client driver with the USB driver stack.
        //Obtain a USBD handle for registration.

        ntStatus = USBD_CreateHandle(deviceObject,
        deviceExtension->StackDeviceObject,
        USBD_CLIENT_CONTRACT_VERSION_602,
        POOL_TAG,
        &deviceExtension->USBDHandle);

    if (!NT_SUCCESS(ntStatus))
    {
        return ntStatus;
    }

    ...

        // Call USBD_QueryUsbCapability to determine
        // stream support.

        ntStatus = USBD_QueryUsbCapability ( deviceExtension->USBDHandle,
        (GUID*)&GUID_USB_CAPABILITY_STATIC_STREAMS,
        sizeof(ULONG),
        (PUCHAR) &deviceExtension.MaxSupportedStreams);

    if (!NT_SUCCESS(ntStatus))
    {
        deviceExtension->MaxSupportedStreams = 0;
        ntStatus = STATUS_SUCCESS;
    }

    ...

}
```

## See also

[Allocating and Building URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-add-xrb-support-for-client-drivers)

[Best Practices: Using URBs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-client-driver-contract-in-windows-8)

[USBD_CloseHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_closehandle)