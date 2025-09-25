# IWMDMStorage4::GetSpecifiedMetadata

## Description

The **GetSpecifiedMetadata** method retrieves one or more specific metadata properties from the storage.

## Parameters

### `cProperties` [in]

Count of properties to retrieve.

### `ppwszPropNames` [in]

Array of property names to retrieve. The length of this array should be equal to *cProperties*. The application should free this memory using **CoTaskMemFree**.

### `ppMetadata` [out]

Pointer to the returned [IWMDMMetaData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata) interface pointer, containing the retrieved values. The caller must release this interface when finished with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method gives the client control over which properties are retrieved. This can be more efficient than [IWMDMStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-getmetadata), and is recommended when the client needs only a subset of properties supported by the storage.

If this method is used to retrieve data from a Windows Portable Devices (WPD) device, the data is returned in binary form in an **IPortableDeviceValues** object. The application should de-serialize this data in order to obtain the actual property values.

The method succeeds and returns WMDM_S_NOT_ALL_PROPERTIES_RETRIEVED even if some of the specified properties could not be retrieved (but at least one property was retrieved). The method fails and returns WMDM_E_NOTSUPPORTED if none of the specified properties could be retrieved.

Requesting a single property is a special case of this method. If the client requests a single property, the possible return codes are S_OK, E_INVALIDARG, and WMDM_E_NOTSUPPORTED. Thus, in the case of a single property, the method succeeds only if the property is successfully retrieved.

## See also

[Creating a Playlist on the Device](https://learn.microsoft.com/windows/desktop/WMDM/creating-a-playlist-on-the-device)

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[IWMDMStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-getmetadata)

[IWMDMStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage4)

[Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants)