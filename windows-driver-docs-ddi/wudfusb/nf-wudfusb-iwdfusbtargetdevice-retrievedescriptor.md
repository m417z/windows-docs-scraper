# IWDFUsbTargetDevice::RetrieveDescriptor

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveDescriptor** method retrieves a USB descriptor, which can describe a device, configuration, or string.

## Parameters

### `DescriptorType` [in]

A value that specifies the type of descriptor to return. This parameter corresponds to the **bDescriptorType** field of a standard device descriptor, whose values are described in the *Universal Serial Bus* specification. (This resource may not be available in some languages

and countries.) Some of these values are listed in the description of the DescriptorType member of the [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request) structure.

### `Index` [in]

The index of the descriptor, according to the *Universal Serial Bus* specification. (This resource may not be available in some languages

and countries.)

### `LanguageID` [in]

The identifier of the language, if the UMDF driver requests a string descriptor; otherwise, this parameter is zero.

### `BufferLength` [in, out]

A pointer to a variable that, on input, contains the size, in bytes, of the buffer that the *Buffer* points to. If the operation succeeds, the variable receives the number of bytes that the framework copied into the buffer.

### `Buffer` [out]

A pointer to a caller-supplied buffer that receives the USB descriptor. The type of buffer should match the value specified in *DescriptorType*.

## Return value

**RetrieveDescriptor** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [RetrieveDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrievedescriptor) successfully retrieved the USB descriptor. |
| **E_OUTOFMEMORY** | [RetrieveDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-retrievedescriptor) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

For information about valid descriptor types that a UMDF driver can pass for the *DescriptorType* parameter, see the [WinUsb_GetDescriptor](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_getdescriptor) function.

The **RetrieveDescriptor** method generates a UMDF request and synchronously sends the request to the I/O target.

#### Examples

The following code example retrieves a USB configuration descriptor.

```
HRESULT
CUmdfHidDevice::RetrieveConfigDescriptor(
    __out_bcount(ConfigDescriptorCb) PUSB_CONFIGURATION_DESCRIPTOR *ConfigDescriptor,
    __out ULONG *ConfigDescriptorCb
    )
{
    ULONG descriptorCb = sizeof(USB_CONFIGURATION_DESCRIPTOR);
    USB_CONFIGURATION_DESCRIPTOR descriptorHeader;
    PBYTE descriptorBuffer;
    HRESULT hr;

    //
    // Get the configuration descriptor at index 0
    //

    hr = m_UsbTargetDevice->RetrieveDescriptor(
                            USB_CONFIGURATION_DESCRIPTOR_TYPE,
                            0,
                            0,
                            &descriptorCb,
                            &descriptorHeader
                            );
    //
    // Store the buffer in the output parameter, or delete it.
    //
    if (SUCCEEDED(hr)) {
        *ConfigDescriptor = (PUSB_CONFIGURATION_DESCRIPTOR) (descriptorHeader);
        *ConfigDescriptorCb = descriptorCb;
    }
    else {
        delete[] descriptorHeader;
    }
    return hr;
}
```

## See also

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)

[WinUsb_GetDescriptor](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_getdescriptor)