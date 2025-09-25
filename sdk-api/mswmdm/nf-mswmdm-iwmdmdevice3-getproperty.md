# IWMDMDevice3::GetProperty

## Description

The **GetProperty** method retrieves a specific device metadata property.

## Parameters

### `pwszPropName` [in]

A wide character, null-terminated string name of the property to retrieve. A list of standard property name constants is given in [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

### `pValue` [out]

Returned value for the property. The application must free this memory using **PropVariantClear**.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

To obtain the list of supported device properties, the client call this function and specify **g_wszWMDMSupportedDeviceProperties**. For the list of standard device property names, see [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

The client should pass in a pointer to an empty **PROPVARIANT** in the *pValue* parameter. On return, *pValue* will contain the value of the property.

This method is similar to the **GetMetadata** and **GetSpecifiedMetadata** methods for storages, but this method can get only one property at a time.

#### Examples

The following C++ code queries for the g_wszWMDMFormatsSupported property, which returns a **SAFEARRAY** list of formats supported by a device.

```cpp

// Query a device for supported configurations for each media or format type.
HRESULT GetCaps(IWMDMDevice3* pDevice)
{
    HRESULT hr = S_OK;

    // Request the "formats supported" property to get a list of supported formats.
    PROPVARIANT pvFormatsSupported;
    PropVariantInit(&pvFormatsSupported);
    hr = pDevice->GetProperty(g_wszWMDMFormatsSupported, &pvFormatsSupported);
    HANDLE_HR(hr, "Got a property list in GetCaps", "Couldn't get a property list in GetCaps.");

    // Loop through the retrieved format list.
    // For each format, get a list of format configurations.
    SAFEARRAY* formatList = pvFormatsSupported.parray;
    WMDM_FORMATCODE formatCode = WMDM_FORMATCODE_NOTUSED;
    for(LONG iCap = 0; iCap < formatList->rgsabound[0].cElements; iCap++)
    {
        // Get a format from the SAFEARRAY of retrieved formats.
        SafeArrayGetElement(formatList, &iCap, &formatCode);

        // Call a custom function to see the specifics of device support for
       // each format.
        if (formatCode != WMDM_FORMATCODE_NOTUSED)
            myGetFormatCaps(formatCode, pDevice);
    }

e_Exit:
    // Clear out the memory we used.
    PropVariantClear(&pvFormatsSupported);
    return hr;
}

```

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices)

[IWMDMDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice3)

[IWMDMDevice3::SetProperty](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-setproperty)

[IWMDMStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-getmetadata)

[IWMDMStorage4::GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage4-getspecifiedmetadata)

[Setting Metadata on a File](https://learn.microsoft.com/windows/desktop/WMDM/setting-metadata-on-a-file)