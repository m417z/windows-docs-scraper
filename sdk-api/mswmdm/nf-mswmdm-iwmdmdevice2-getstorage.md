# IWMDMDevice2::GetStorage

## Description

The **GetStorage** method searches the immediate children of the root storage for a storage with the given name.

## Parameters

### `pszStorageName` [in]

Pointer to a **null**-terminated string specifying the name of the storage to find. This parameter does not support wildcard characters.

### `ppStorage` [out]

Pointer to the [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface of the storage specified by the *pszStorageName* parameter. The caller must release this interface when done with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This function is not recursive; it only searches the immediate children of the device root storage. For a recursive search version of this function, use [IWMDMDevice3::FindStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-findstorage).

#### Examples

The following C++ function searches for a storage recursively. It uses **GetStorage** to search the immediate children; if the requested storage is not found, it then loops through all the children and recursively searches folders.

```cpp

HRESULT myFindStorageRecursively(LPCWSTR storageName, IWMDMStorage* pCurrentStorage, IWMDMStorage** ppFoundStorage)
{
    HRESULT hr = S_OK;

    // Start with a quick check of all storages inside the storage.
    // If we found it, stop now and return.
    CComQIPtr<IWMDMStorage2> pStorage2(pCurrentStorage);
    hr = pStorage2->GetStorage(storageName, ppFoundStorage);
    if (*ppFoundStorage != NULL)
        return hr;

    //
    // Otherwise, enumerate through and dive into all child folders.
    //

    // First get enumerator.
    CComPtr<IWMDMEnumStorage> pEnumStorage;
    hr = pCurrentStorage->EnumStorage(&pEnumStorage);
    if (hr != S_OK && pEnumStorage != NULL)
        return hr;

    // Now enumerate all folders until found the right item, or out of folders.
    CComPtr<IWMDMStorage> pThisStorage;
    DWORD numRetrieved = 0;
    DWORD attr = 0;
    while(pEnumStorage->Next(1, &pThisStorage, &numRetrieved) == S_OK)
    {
        pThisStorage->GetAttributes(&attr, NULL);
        if (attr & WMDM_FILE_ATTR_FOLDER)
        {
            hr = myFindStorageRecursively(storageName, pThisStorage, ppFoundStorage);
            if (*ppFoundStorage != NULL)
                return hr;
        }
        pThisStorage.Release();
    }

    return hr;
}

```

## See also

[IWMDMDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice2)