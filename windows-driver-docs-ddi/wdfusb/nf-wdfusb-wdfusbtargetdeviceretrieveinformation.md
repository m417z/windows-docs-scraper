# WdfUsbTargetDeviceRetrieveInformation function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceRetrieveInformation** method retrieves information about the USB device that is associated with a specified framework USB device object.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Information` [in, out]

A pointer to a caller-allocated [WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information) structure that receives USB device information.

## Return value

**WdfUsbTargetDeviceRetrieveInformation** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbTargetDeviceRetrieveInformation** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

In framework versions 1.11 and later, the driver can call [WdfUsbTargetDeviceQueryUsbCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicequeryusbcapability) to retrieve a device's operating speed.

#### Examples

The following code example is part of an [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function that creates a USB device object, initializes a [WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information) structure, and calls **WdfUsbTargetDeviceRetrieveInformation**.

```cpp
NTSTATUS
MyEvtDevicePrepareHardware(
    IN WDFDEVICE  Device,
    IN WDFCMRESLIST  ResourceList,
    IN WDFCMRESLIST  ResourceListTranslated
    )
{
    NTSTATUS  status;
    PMY_DEVICE_CONTEXT  pMyDeviceContext;
    WDF_USB_DEVICE_CREATE_CONFIG  Config;

    pMyDeviceContext = GetDeviceContext(Device);

    // If object handle is not NULL, MyEvtDevicePrepareHardware
    // was called previously and the handle is still valid.
    if (pMyDeviceContext->UsbDevice != NULL) {
        return STATUS_SUCCESS;
    }

    WDF_USB_DEVICE_CREATE_CONFIG_INIT(
                                      &Config,
                                      USBD_CLIENT_CONTRACT_VERSION_602
                                      );

    status = WdfUsbTargetDeviceCreateWithParameters(
                                      Device,
                                      &Config,
                                      WDF_NO_OBJECT_ATTRIBUTES,
                                      &pMyDeviceContext->UsbDevice
                                      );
    if (!NT_SUCCESS(status)) {
        return status;
    }

    WDF_USB_DEVICE_INFORMATION_INIT(&deviceInfo);

    status = WdfUsbTargetDeviceRetrieveInformation(
                                      pDeviceContext->UsbDevice,
                                      &deviceInfo
                                      );
...
}
```

## See also

[WDF_USB_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_device_information)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetDeviceQueryUsbCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicequeryusbcapability)