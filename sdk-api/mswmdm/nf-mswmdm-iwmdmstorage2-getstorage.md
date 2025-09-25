# IWMDMStorage2::GetStorage

## Description

The **GetStorage** method retrieves a child storage by name directly from the current storage without having to enumerate through all the children.

## Parameters

### `pszStorageName` [in]

Pointer to a **null**-terminated string specifying the storage name. This is the name retrieved by [IWMDMStorage::GetName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getname).

### `ppStorage` [out]

Pointer to the retrieved storage object, or **NULL** if no storage was found. The caller must release this interface when done with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

**IWMDMStorage2::GetStorage** does not support wildcard characters. It is not recursive; that is, it will only find storages that are immediate children of the current storage. To find a storage more than one level deep, try [IWMDMDevice3::FindStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-findstorage).

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

[IWMDMStorage2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage2)