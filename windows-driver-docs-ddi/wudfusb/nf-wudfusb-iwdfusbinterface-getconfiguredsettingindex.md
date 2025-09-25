# IWDFUsbInterface::GetConfiguredSettingIndex

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetConfiguredSettingIndex** method retrieves the current setting index for a USB interface.

## Return value

**GetConfiguredSettingIndex** returns the current setting index for the USB interface.

## Remarks

The **GetConfiguredSettingIndex** method is provided for convenience because a UMDF driver can obtain the current setting index from the **bAlternateSetting** member of the [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure that the driver retrieves when it calls the [IWDFUsbInterface::GetInterfaceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-getinterfacedescriptor) method.

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)

[IWDFUsbInterface::GetInterfaceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-getinterfacedescriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)