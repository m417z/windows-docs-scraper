# IWDFUsbTargetFactory::CreateUsbTargetDevice

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateUsbTargetDevice** method creates a USB device object that is also an I/O target.

## Parameters

### `ppDevice` [out]

A pointer to a buffer that receives a pointer to the [IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice) interface for the USB target device object.

## Return value

**CreateUsbTargetDevice** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [CreateUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetfactory-createusbtargetdevice) successfully created a USB device object that is also an I/O target. |
| **E_OUTOFMEMORY** | [CreateUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetfactory-createusbtargetdevice) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the [WinUsb_Initialize](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_initialize) function returned. |

## Remarks

A UMDF driver should release the [IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice) interface pointer that the **CreateUsbTargetDevice** method returns in the *ppDevice* parameter when the driver is done with the interface.

If the file object that is associated with the created I/O target object is required, the driver should call the [IWDFIoTarget::GetTargetFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-gettargetfile) method. For more information about this file object, see [File Creation by a USB I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/file-creation-by-a-usb-i-o-target).

**Note** **CreateUsbTargetDevice** inherits all of the methods of the [IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget) interface.

To use the newly created USB I/O target object in a device stack, the INF file that installs the UMDF driver must contain the **UmdfDispatcher** directive and set **UmdfDispatcher** to **WinUsb** (`UmdfDispatcher=WinUsb`) in the **DDInstall.WDF** section. **UmdfDispatcher** is required to inform the UMDF platform that it can allow access to the USB I/O target. For more information about **UmdfDispatcher**, see [Specifying WDF Directives](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

#### Examples

The following code example shows how to create and use a USB device object in an implementation of the UMDF driver's [IPnpCallbackHardware::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onpreparehardware) method.

```
HRESULT
CUmdfHidDevice::OnPrepareHardware(
    __in IWDFDevice* WdfDevice
    )
{
    CComPtr<IWDFUsbTargetFactory> factory;
    USB_INTERFACE_DESCRIPTOR interfaceDescriptor;
    bool hidInterfaceFound = false;
    PUSB_HID_DESCRIPTOR hidDescriptor;
    NTSTATUS status;
    HRESULT hr = S_OK;
    //
    // Get the USB I/O target factory interface.
    //
    hr = WdfDevice->QueryInterface(IID_PPV_ARGS(&factory));
    //
    // Create the USB I/O target.
    //
    hr = factory->CreateUsbTargetDevice(&m_UsbTargetDevice);
    //
    // Get the configuration descriptor for the target device.
    //
    if (SUCCEEDED(hr))
    {
        hr = RetrieveConfigDescriptor(&m_ConfigDescriptor,
                                      &m_ConfigDescriptorCb);
    }
    //
    // Iterate through the interfaces on the device and find the HID interface.
    //
    if (SUCCEEDED(hr))
    {
        CComPtr<IWDFUsbInterface> usbInterface;
        UCHAR index;
        bool found = true;
        for (index = 0; index < m_ConfigDescriptor->bNumInterfaces; index += 1)
        {
            hr = m_UsbTargetDevice->RetrieveUsbInterface(index, &usbInterface);
            if (SUCCEEDED(hr))
            {
                usbInterface->GetInterfaceDescriptor(&interfaceDescriptor);
                if (interfaceDescriptor.bInterfaceClass == 0x3)
                {
                    hidInterfaceFound = true;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (SUCCEEDED(hr) && (hidInterfaceFound == false))
        {
            hr = E_FAIL;
        }
    }
    //
    // Get the HID descriptor associated with this interface.
    //
    if (SUCCEEDED(hr))
    {
        hr = ParseHidDescriptor(
                                m_ConfigDescriptor,
                                m_ConfigDescriptorCb,
                                interfaceDescriptor.bInterfaceNumber
                                );
    }
    //
    // Process the HID information from the device and setup
    // the collection data structures.
    //
    if (SUCCEEDED(hr))
    {
        hr = SetupCollections();
    }
    return hr;
}
```

## See also

[IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)

[IWDFIoTarget::GetTargetFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-gettargetfile)

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)

[IWDFUsbTargetFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetfactory)

[WinUsb_Initialize](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_initialize)