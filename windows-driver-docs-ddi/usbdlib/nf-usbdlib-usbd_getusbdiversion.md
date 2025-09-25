# USBD_GetUSBDIVersion function

## Description

The **USBD_GetUSBDIVersion** routine returns version information about the host controller driver (HCD) that controls the client's USB device.

**Note** [USBD_IsInterfaceVersionSupported](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isinterfaceversionsupported) replaces the **USBD_GetUSBDIVersion** routine

## Parameters

### `VersionInformation` [out]

Pointer to caller-allocated memory for a [USBD_VERSION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_version_information) structure that on return from the routine, contains version information about the HCD.

## Remarks

Callers of this routine can be running at IRQL <= DISPATCH_LEVEL if the memory for *VersionInformation* is allocated from nonpaged pool. Otherwise, callers must be running at IRQL < DISPATCH_LEVEL.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[USBD_IsInterfaceVersionSupported](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isinterfaceversionsupported)