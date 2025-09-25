# IWDFUsbTargetDevice::GetWinUsbHandle

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetWinUsbHandle** method retrieves the WinUsb interface handle that is associated with an I/O target device object.

## Return value

**GetWinUsbHandle** returns the WinUsb interface handle that is associated with the I/O target device object.

## Remarks

**IWDFUsbTargetDevice::GetWinUsbHandle** returns a WinUsb interface handle to the default interface. The default interface is identified by index zero.

 A UMDF driver can use the WinUsb interface handle to bypass the UMDF interfaces and call [WinUSB Routines](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540046(v=vs.85)) directly for certain operations.

The UMDF driver should not call the [WinUsb_Free](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_free) function to free the WinUsb interface handle because the I/O target device object owns the handle.

## See also

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)

[WinUsb_Free](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_free)

[WinUsb_Initialize](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_initialize)