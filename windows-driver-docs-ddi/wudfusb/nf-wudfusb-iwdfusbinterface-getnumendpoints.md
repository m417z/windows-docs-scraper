# IWDFUsbInterface::GetNumEndPoints

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetNumEndPoints** method retrieves the number of endpoints (pipes) on a USB interface.

## Return value

**GetNumEndPoints** returns the number of endpoints on the USB interface.

## Remarks

The **GetNumEndPoints** method is provided for convenience because a UMDF driver can obtain the number of endpoints from the **bNumEndpoints** member of the [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure that the driver retrieves when it calls the [IWDFUsbInterface::GetInterfaceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-getinterfacedescriptor) method.

#### Examples

The following code example retrieves the number of pipes on a USB interface and then retrieves particular types of pipes.

```
 HRESULT  hr;
 UCHAR  NumEndPoints;
 NumEndPoints = pIUsbInterface->GetNumEndPoints();

 if (NumEndPoints != NUM_OSRUSB_ENDPOINTS) {
     hr = E_UNEXPECTED;
 }
 if (SUCCEEDED(hr))  {
     for (UCHAR PipeIndex = 0; PipeIndex < NumEndPoints; PipeIndex++) {
     hr = pIUsbInterface->RetrieveUsbPipeObject(PipeIndex,
                                                &pIUsbPipe);
     if (FAILED(hr)) {
        // Output an error.
     }
     else {
         if ( pIUsbPipe->IsInEndPoint() && (UsbdPipeTypeBulk == pIUsbPipe->GetType()) ) {
             pIUsbInputPipe = pIUsbPipe;
         }
         else if ( pIUsbPipe->IsOutEndPoint() && (UsbdPipeTypeBulk == pIUsbPipe->GetType()) )
         {
              pIUsbOutputPipe = pIUsbPipe;
         }
         else
              {
                  SAFE_RELEASE(pIUsbPipe);
              }
          }
```

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)

[IWDFUsbInterface::GetInterfaceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-getinterfacedescriptor)

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)