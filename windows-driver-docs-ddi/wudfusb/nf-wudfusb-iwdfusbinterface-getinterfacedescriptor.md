# IWDFUsbInterface::GetInterfaceDescriptor

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetInterfaceDescriptor** method retrieves a descriptor for a USB interface.

## Parameters

### `UsbAltInterfaceDescriptor` [out]

A pointer to a variable that receives the USB interface descriptor.

## Remarks

After a UMDF driver calls the [IWDFUsbTargetDevice::RetrieveUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrieveusbinterface) method to retrieve the first USB interface for the USB device, a UMDF driver should retrieve the descriptor for the USB interface. Therefore, the **GetInterfaceDescriptor** method does not fail.

For a code example of how to use the **GetInterfaceDescriptor** method, see [IWDFUsbTargetFactory::CreateUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetfactory-createusbtargetdevice).

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)

[IWDFUsbTargetDevice::RetrieveUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrieveusbinterface)