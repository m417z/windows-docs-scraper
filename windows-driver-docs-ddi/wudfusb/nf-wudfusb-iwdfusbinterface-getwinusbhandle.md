# IWDFUsbInterface::GetWinUsbHandle

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetWinUsbHandle** method retrieves the WinUsb interface handle that is associated with a USB interface.

## Return value

**GetWinUsbHandle** returns the WinUsb interface handle that is associated with the USB interface.

## Remarks

If called on the default interface, the **IWDFUsbInterface::GetWinUsbHandle** method returns the same WinUsb interface handle as [IWDFUsbTargetDevice::GetWinUsbHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-getwinusbhandle). The default interface is identified by index zero.

If called on interfaces with index greater than zero, **IWDFUsbInterface::GetWinUsbHandle** returns a different handle than [IWDFUsbTargetDevice::GetWinUsbHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-getwinusbhandle).

 A UMDF driver can use the WinUsb interface handle to bypass the UMDF interfaces and call [WinUSB Routines](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540046(v=vs.85)) directly for interface-related operations.

The UMDF driver should not call the [WinUsb_Free](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_free) function to free the WinUsb interface handle because the USB interface object owns the handle.

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)

[WinUsb_Free](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_free)

[WinUsb_Initialize](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_initialize)