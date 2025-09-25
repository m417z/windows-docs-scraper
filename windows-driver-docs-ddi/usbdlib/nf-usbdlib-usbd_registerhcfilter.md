# USBD_RegisterHcFilter function

## Description

The **USBD_RegisterHcFilter** routine has been deprecated in Windows XP and later operating systems. Do not use.

On Windows XP and later operating systems, a filter driver that is installed between the root hub FDO and PDO sees all USB traffic for a USB device after it has been enumerated. There is no supported mechanism for filtering descriptor requests that occur during the enumeration of a USB device, because those requests originate and remain in the port driver (usbport.sys) and not the hub driver.

## Parameters

### `DeviceObject` [in]

Pointer to the device object that is the current top of the stack as reported by [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack).

### `FilterDeviceObject` [in]

Pointer to the filter device object created by the filter driver for its operations.

## Remarks

USB bus filter drivers must call this routine after attaching their device object to the device object stack for the host controller driver.

## See also

[IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack)

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)