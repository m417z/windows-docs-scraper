# IWMDMStorage4::GetReferences

## Description

The **GetReferences** method retrieves an array of pointers to **IWMDMStorage** objects pointed to by this storage. An abstract album or playlist is typically stored as a collection of references on an MTP device.

## Parameters

### `pdwRefs` [out]

Pointer to the count of values retrieved by *pppIWMDMStorage*. If the object has no references, this will return zero, and the function will return S_OK.

### `pppIWMDMStorage` [out]

Pointer to a pointer to the array of [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface pointers that represent references in a storage. Such references can, for example, represent items in a playlist or album. The retrieved array is in the same order as they appear in the object itself. Memory for this array is allocated by Windows Media Device Manager. When the calling application has finished accessing this array, it must first call **Release** on all of the interface pointers, and then free the array memory using **CoTaskMemFree**.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Windows Media Device Manager delegates to the underlying service provider the task of adding and removing the references on a storage. Objects with references refers to abstract objects such as abstract playlists or albums; folders are not considered as having references.

There are two types of asynchronous deletions that can occur and cause errors in this method. If a *reference* to a storage has been deleted since the application retrieved it, and the application tries to use the reference, the method call will return WMDM_E_INTERFACEDEAD. If the file the reference refers to has been deleted, S_FALSE is returned.

#### Examples

The following C++ code queries for the references of a storage (pStorage).

```cpp

// Get references.
CComQIPtr<IWMDMStorage4> pStorage4(pStorage);
if (pStorage4 != NULL)
{
    WCHAR name[100];
    DWORD numRefs = 0;
    IWMDMStorage** parrReferences;
    hr = pStorage4->GetReferences(&numRefs, &parrReferences);
    for(int i = 0; i < numRefs; i++)
    {
        ZeroMemory(name, sizeof(name));
        hr = parrReferences[i]->GetName(name, (sizeof(name) / sizeof(WCHAR)) - 1);
        if (hr == S_OK)
            // TODO: Display the name.
        parrReferences[i]->Release();
    }
    // Free the memory.
    if (parrReferences != NULL)
        CoTaskMemFree(parrReferences);
}

```

## See also

[Creating a Playlist on the Device](https://learn.microsoft.com/windows/desktop/WMDM/creating-a-playlist-on-the-device)

[IWMDMStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage4)

[IWMDMStorage4::SetReferences](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage4-setreferences)