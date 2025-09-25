# IWMDMEnumStorage::Next

## Description

The **Next** method retrieves a pointer to the next sibling storage.

## Parameters

### `celt` [in]

Number of storages requested.

### `ppStorage` [out]

Pointer to caller-allocated array of [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface pointers. The size of this array must be **IWMDMStorage** *[celt]. The caller must release these interfaces when done with them. To avoid allocating a whole array, simply pass in the address of a pointer to an **IWMDMStorage** interface, as shown in Remarks.

### `pceltFetched` [out]

Number of storages enumerated.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Windows Media Device Manager delegates the storage enumeration to the corresponding service provider. For information on service provider storage enumeration, see the [IMDSPEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage) interface.

The storage enumerator may not reflect the effect of media insertion and removal. In that case, the application should obtain a new storage enumerator object by calling [IWMDMDevice::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-enumstorage) to get the refreshed list. If you only want to retrieve a single interface at a time, you do not need to allocate an array for this method, as shown in the following code.

#### Examples

The following two C++ functions recursively explore a device. The first one is a kickoff function that obtains the [IWMDMEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage) interface of the root device storage. It passes this to the recursive function which examines all the nested functions.

```cpp

// Kickoff function to explore a device.
void ExploreDevice(IWMDMDevice* pDevice)
{
    HRESULT hr = S_OK;

    // Get a root enumerator.
    CComPtr<IWMDMEnumStorage> pEnumStorage;
    hr = pDevice->EnumStorage(&pEnumStorage);
    RecursiveExploreStorage(pEnumStorage);

    HANDLE_HR(hr, "Got a root storage in ExploreDevice.","Couldn't get a root storage in ExploreDevice.");

e_Exit:
    return;
}

void RecursiveExploreStorage(IWMDMEnumStorage* pEnumStorage)
{
    HRESULT hr = S_OK;
    CComPtr<IWMDMStorage> pStorage;
    ULONG numRetrieved = 0;
    // Loop through all storages in the current storage.
    // We don't need to allocate an array to retrieve one
    // interface at a time.
    while(pEnumStorage->Next(1, &pStorage, &numRetrieved) == S_OK && numRetrieved == 1)
    {
        // Get the name of the object. The first time this is called on a
        // device, it will retrieve '\' as the root folder name.
        const UINT MAX_LEN = 255;
        WCHAR name[MAX_LEN];
        hr = pStorage->GetName((LPWSTR)&name, MAX_LEN);
        // TODO: Display the storage name.

        // Get metadata for the storage.
        if (SUCCEEDED(hr))
            GetMetadata(pStorage);

        // Find out something about the item.
        DWORD attributes = 0;
        _WAVEFORMATEX audioFormat;
        hr = pStorage->GetAttributes(&attributes, &audioFormat);
        HANDLE_HR(hr, "Got storage attributes in RecursivelyExploreStorage.","Couldn't get storage attributes in RecursivelyExploreStorage.");

        // If this is a folder, recurse into it.
        if (attributes & WMDM_FILE_ATTR_FILE)
            // TODO: Display a message indicating that this is a file.
        if (attributes & WMDM_FILE_ATTR_FOLDER)
        {
            // TODO: Display a message indicating that this is a folder.
            CComPtr<IWMDMEnumStorage> pEnumSubStorage;
            hr = pStorage->EnumStorage(&pEnumSubStorage);
            RecursiveExploreStorage(pEnumSubStorage);
        }

        // Some other useful attributes to check include:
        // WMDM_FILE_ATTR_CANDELETE and WMDM_FILE_ATTR_CANPLAY and others to determine what can be done with a storage.
        // WMDM_FILE_ATTR_HIDDEN and other attributes to determine display characteristics,
        // WMDM_STORAGE_IS_DEFAULT to see if this is the default save location for new files.
        pStorage.Release();
    } // Get the next storage pointer.

e_Exit:
    return;
}

```

## See also

[Exploring a Device](https://learn.microsoft.com/windows/desktop/WMDM/exploring-a-device)

[IWMDMDevice::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-enumstorage)

[IWMDMEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage)