# IWDFUsbTargetDevice::GetNumInterfaces

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetNumInterfaces** method retrieves the number of USB interfaces for the USB device.

## Return value

**GetNumInterfaces** returns the number of [IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface) interfaces for the USB device in the default configuration. The default configuration is identified by index zero.

## Remarks

UMDF USB I/O target devices do not support multiple configurations.

#### Examples

The following code example retrieves the number of USB interfaces for the USB device.

```
    UCHAR NumInterfaces = pIUsbTargetDevice->GetNumInterfaces();
```

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)