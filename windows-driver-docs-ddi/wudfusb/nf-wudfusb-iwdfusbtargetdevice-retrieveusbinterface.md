# IWDFUsbTargetDevice::RetrieveUsbInterface

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveUsbInterface** method retrieves the specified USB interface for a USB device.

## Parameters

### `InterfaceIndex` [in]

The index of the interface to retrieve.

### `ppUsbInterface` [out]

A pointer to a variable that receives a pointer to the specified [IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface) interface for the USB device.

## Return value

**RetrieveUsbInterface** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [RetrieveUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrieveusbinterface) successfully retrieved the specified USB interface for the USB device. |
| **E_OUTOFMEMORY** | [RetrieveUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrieveusbinterface) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

The driver can call the [IWDFUsbTargetDevice::GetNumInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-getnuminterfaces) method to retrieve the total number of USB interfaces that are available.

The driver can use the interface pointer that **RetrieveUsbInterface** retrieves, to call the methods that the [IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface) interface provides. For more information about using these methods, see [Working with USB Interfaces in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-interfaces-in-umdf-1-x-drivers).

#### Examples

For a code example of how to use the **RetrieveUsbInterface** method, see [IWDFUsbTargetFactory::CreateUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetfactory-createusbtargetdevice).

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)

[IWDFUsbTargetDevice::GetNumInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-getnuminterfaces)

[USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information)