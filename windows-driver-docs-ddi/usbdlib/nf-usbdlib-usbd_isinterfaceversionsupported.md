# USBD_IsInterfaceVersionSupported function

## Description

The **USBD_IsInterfaceVersionSupported** routine is called by a USB client driver to check whether the underlying USB driver stack supports a particular USBD interface version.

## Parameters

### `USBDHandle` [in]

USBD handle that is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `USBDInterfaceVersion` [in]

A LONG value that represents the USBD interface version to check against the USB driver stack. Possible values include USBD_INTERFACE_VERSION_602 or USBD_INTERFACE_VERSION_600. For more information, see Remarks.

## Return value

**USBD_IsInterfaceVersionSupported** returns TRUE if the specified USBD interface version is supported by the USB driver stack; FALSE otherwise. For more information, see Remarks.

## Remarks

The USB driver stack loaded for a device depends on the version of Windows, the host controller hardware, and the USB device. Windows 7 and earlier versions of Windows support USBD_INTERFACE_VERSION_600. The USBD interface versions, supported by the Windows 8 driver stack, are USBD_INTERFACE_VERSION_602 and USBD_INTERFACE_VERSION_600. A USB client driver rarely needs to know about the underlying driver stack's interface version. In cases where such information is required, the client driver can call the **USBD_IsInterfaceVersionSupported** routine to check whether a particular interface version is supported by the underlying driver stack. For instance, the client driver calls **USBD_IsInterfaceVersionSupported** to determine whether the driver stack supports USBD_INTERFACE_VERSION_602. If it supports that version, the routine returns TRUE.

The routine requires a valid USBD handle (obtained in a previous call to [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle)). **USBD_IsInterfaceVersionSupported** can only be called by client drivers that target Windows Vista and later versions of Windows. Those client drivers must get Windows Driver Kit (WDK) for Windows 8 in order to call the routines successfully. **USBD_IsInterfaceVersionSupported** replaces the [USBD_GetUSBDIVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_getusbdiversion) routine.

The USBD interface version does not indicate the capabilities supported by the USB driver stack. For example just because the underlying driver stack supports USBD_INTERFACE_VERSION_602, the client driver *must not* assume that the driver can use the static streams capability. That is because, even though the driver stack supports the capability, the host controller hardware or the USB device might not support streams. To determine whether the USB driver stack supports a certain capability, call [USBD_QueryUsbCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406230(v=vs.85)).