# IWDFDevice2::CreateSymbolicLinkWithReferenceString

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The**CreateSymbolicLinkWithReferenceString** method creates a symbolic link name, and optionally, a reference string, for a device

## Parameters

### `pSymbolicLink` [in]

A pointer to a **NULL**-terminated character string that becomes the user-visible name of the device. The symbolic link name must be in the global **DosDevices** namespace.

### `pReferenceString` [in, optional]

A pointer to a **NULL**-terminated character string that Windows appends to the device name when an application uses the symbolic name that the *pSymbolicLink* parameter specifies. For more information, see the following Remarks section. This parameter is optional and can be **NULL**.

## Return value

**CreateSymbolicLinkWithReferenceString** returns S_OK if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The caller specified an invalid value for an input parameter. |
| **E_OUTOFMEMORY** | The memory allocation failed. |

This method might return one of the other values that Winerror.h contains.

## Remarks

**CreateSymbolicLinkWithReferenceString** creates a symbolic link name, and optionally a reference string, for the device that the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface represents. After a driver calls **CreateSymbolicLinkWithReferenceString**, applications can use the symbolic link name to access the device.

Suppose your device's name is "\Device\MyDevice". You can create a symbolic link name of "DeviceUserName" for your device by specifying "L"DeviceUserName"" for the *pSymbolicLink* parameter. If you specify "L"Instance3"" for the *pReferenceString* parameter, you are creating a symbolic link to \Device\MyDevice\Instance3. If an application opens the device by using the symbolic link name, the I/O manager opens \Device\MyDevice and creates a WDM file object that contains the \Instance3 string as the file name. Your UMDF-based driver receives a framework-created file object, which also contains the \Instance3 string as the file name (see [IWDFFile::RetrieveFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffile-retrievefilename)).

Typically, instead of providing symbolic links, framework-based drivers provide [device interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface) that applications can use to access their devices.

If the device is removed unexpectedly (surprise-removed), the framework removes the symbolic link to the device. The driver can then use the symbolic link name for a new instance of the device.

If you do not need to add a reference string to your device's symbolic link name, your driver can call [IWDFDevice::CreateSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createsymboliclink) instead of **CreateSymbolicLinkWithReferenceString**.

#### Examples

The following line defines a symbolic link name prefix in the global **DosDevices** namespace.

```
#define SYMBOLIC_LINK_NAME_PREFIX   L"\\DosDevices\\Global\\"
```

The following code example creates a symbolic name string, obtains the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface, and then calls **CreateSymbolicLinkWithReferenceString**.

```

    IWDFDevice2 *pDevice2 = NULL;
    HRESULT hr;

    //
    // Create symbolic link name string.
    //
    hr = StringCchPrintf(portFullName,
                         portFullNameLength,
                         L"%ws%ws",
                         SYMBOLIC_LINK_NAME_PREFIX,
                         portName);
    if (FAILED(hr))
    {
        goto Exit;
    }

    //
    // Get a pointer to the IWDFDevice2 interface.
    //
    hr = pIWDFDevice->QueryInterface(__uuidof(IWDFDevice2),
                                     (void**) &pDevice2);
    if (SUCCEEDED(hr))
    {
    hr = pDevice2->CreateSymbolicLinkWithReferenceString(portFullName,
                                                         portCountString);
    if (FAILED(hr))
        {
            goto Exit;
        }
        SAFE_RELEASE(pDevice2);
    }
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFDevice::CreateSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createsymboliclink)