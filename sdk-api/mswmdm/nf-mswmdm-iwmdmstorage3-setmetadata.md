# IWMDMStorage3::SetMetadata

## Description

The **SetMetadata** method sets metadata on the storage.

## Parameters

### `pMetadata` [in]

An [IWMDMMetaData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata) pointer containing metadata to set on the object. To create this interface, call [CreateEmptyMetadataObject](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-createemptymetadataobject).

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Existing properties in the storage with the same name are overwritten. All other existing properties are not modified or lost.

To set properties for a Windows Portable Devices (WPD) device, an application would create an **IPortableDeviceValues** object and set each property into this collection. Then, the application would serialize the collection to a binary large object (BLOB). Once the data is serialized, the application would add it to the **IWMDMMetaData** referenced by the *pMetadata* argument using the g_wszWPDPassthroughPropertyValues metadata constant.

#### Examples

The following C++ code adds a subtitle as metadata to a storage (pStorage3) using the **IWMDMMetaData** interface retrieved from the storage previously (not shown).

```cpp

// Set metadata values on a storage.
WCHAR* station = L"Mysubtitle";
UINT numBytes = (wcslen(station) + 1) * sizeof(WCHAR); // WCHAR string is 2 * length of characters long
                                                       // plus the terminating null character.
hr = pMetadata->AddItem(WMDM_TYPE_STRING, g_wszWMDMMediaStationName, (BYTE*)station, numBytes) ;
BREAK_HR(hr, "Added a metadata value to the interface in TestUpdateMetadata.", "Couldn't add a metadata value to the interface in TestUpdateMetadata.");

// Add the metadata to the storage.
hr = pStorage3->SetMetadata(pMetadata);
BREAK_HR(hr, "Set metadata on the storage in TestUpdateMetadata.", "Couldn't set metadata on the storage in TestUpdateMetadata: " << hex << hr << dec);

```

## See also

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[IWMDMStorage3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage3)

[IWMDMStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-getmetadata)

[Setting Metadata on a File](https://learn.microsoft.com/windows/desktop/WMDM/setting-metadata-on-a-file)