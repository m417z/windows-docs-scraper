# IWMDMDevice::GetFormatSupport

## Description

The **GetFormatSupport** method retrieves all the formats supported by the device, including codecs and file formats.

## Parameters

### `ppFormatEx` [out]

Pointer to an array of [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structures specifying information about codecs and bit rates supported by the device. Windows Media Device Manager allocates the memory for this parameter; the caller must free it using **CoTaskMemFree**.

### `pnFormatCount` [out]

Pointer to the number of elements in the *ppFormatEx* array.

### `pppwszMimeType` [out]

Pointer to an array describing file formats and digital rights management schemes supported by the device. Windows Media Device Manager allocates the memory for this parameter; the caller must free it using **CoTaskMemFree**.

### `pnMimeTypeCount` [out]

Pointer to the number of elements in the *pppwszMimeType* array.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The recommended way to retrieve device-supported formats is [IWMDMDevice3::GetFormatCapability](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability).

#### Examples

The following C++ function retrieves various device capabilities.

```cpp

// Function to print out device caps for a device that supports
// only IWMDMDevice.
void GetCaps(IWMDMDevice* pDevice)
{
    HRESULT hr = S_OK;

    // Get all capabilities for audio and mime support.
    _WAVEFORMATEX* pAudioFormats;
    LPWSTR* pMimeFormats;
    UINT numAudioFormats = 0;
    UINT numMimeFormats = 0;
    hr = pDevice->GetFormatSupport(
        &pAudioFormats,
        &numAudioFormats,
        &pMimeFormats,
        &numMimeFormats);

    HANDLE_HR(hr, "Got audio and mime formats in GetCaps IWMDMDevice", "Couldn't get audio and mime formats in GetCaps IWMDMDevice");

    // Print out audio format data.
    if (numAudioFormats > 0)
    {
        / /TODO: Display a banner to precede the supported formats.
    }
    else
    {
        // TODO: Display a message indicating that no formats are supported.
    }
    for(int i = 0; i < numAudioFormats; i++)
    {
        // TODO: Display a configuration value.
        PrintWaveFormatGuid(pAudioFormats[i].wFormatTag);
        // TODO: Display a max channel value.
        // TODO: Display a max samples/second value.
        // TODO: Display the max bytes/second value.
        // TODO: Display the block alignment value.
        // TODo: Display the max bits/sample value.
    }

    // Print out MIME formats.
    if (numMimeFormats > 0)
        // TODO: Display a banner for the MIME format listing.
    else
        / /TODO: Display a message indicating that no MIME formats are supported.
    for(i = 0; i < numMimeFormats; i++)
    {
        // TODO: Display each individual MIME format.
    }

e_Exit:
    return;

}

```

## See also

[Discovering Device Format Capabilities](https://learn.microsoft.com/windows/desktop/WMDM/discovering-device-format-capabilities)

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)

[IWMDMDevice3::GetFormatCapability](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability)

[_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex)