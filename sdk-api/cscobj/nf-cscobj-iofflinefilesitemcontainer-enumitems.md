# IOfflineFilesItemContainer::EnumItems

## Description

Returns an enumerator of child items for the cache item implementing this method. Server, share, and directory entries in the Offline Files cache implement this method to expose the enumeration of their immediate children.

**Note** A call to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to query a file item for **IID_IOfflineFilesItemContainer** fails with **E_NOINTERFACE**, because file items have no children.

## Parameters

### `dwQueryFlags` [in]

Flags affecting the amount of query activity at the time of enumeration. The parameter may contain one or more of the following bit flags.

#### OFFLINEFILES_ITEM_QUERY_REMOTEINFO (0x00000001)

This flag is reserved for future use.

#### OFFLINEFILES_ITEM_QUERY_CONNECTIONSTATE (0x00000002)

If this flag is set, the enumeration operation includes an extra call to the Offline Files store to obtain information about the connection state (online or offline) of the item. If this flag is not set, enumeration does not include this extra operation, and connection information will be automatically queried on demand when it is needed.

#### OFFLINEFILES_ITEM_QUERY_LOCALDIRTYBYTECOUNT (0x00000004)

If this flag is set, the find operation includes an extra call to the Offline Files store to obtain information about the amount, in bytes, of unsynchronized ("dirty") data for the associated file in the local Offline Files cache.

#### OFFLINEFILES_ITEM_QUERY_REMOTEDIRTYBYTECOUNT (0x00000008)

This flag is reserved for future use.

#### OFFLINEFILES_ITEM_QUERY_INCLUDETRANSPARENTCACHE (0x00000010)

Allows administrators to find items cached by any user. If this flag is set and the caller is not an administrator, the method call fails.

### `ppenum` [out]

Enumerator of [IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem) interface pointers.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

To begin a top-down enumeration of the entire cache, perform the following steps:

1. Create an instance of **CLSID_OfflineFilesCache** and obtain its [IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer) interface.
2. Call the **EnumItems** method to obtain an enumerator for the server entries.
3. For each entry returned, call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for [IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer).
4. If [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) succeeds, the item supports children. If so, enumerate each child, calling **QueryInterface** for [IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer) on each. This pattern may be recursively applied to enumerate the entire cache.

#### Examples

This example illustrates how to perform a top-down traversal of the Offline Files cache using a simple recursive implementation.

```cpp
HRESULT EnumItems(IOfflineFilesItemContainer *pContainer);

//
// Emits the item's path string to the console.
//
HRESULT ReportItem(
    IOfflineFilesItem *pItem
    )
{
    LPWSTR pszPath;
    HRESULT hr = pItem->GetPath(&pszPath);
    if (SUCCEEDED(hr))
    {
        LPCWSTR pszType = L"";
        OFFLINEFILES_ITEM_TYPE ItemType;
        hr = pItem->GetItemType(&ItemType);
        if (SUCCEEDED(hr))
        {
            switch(ItemType)
            {
                case OFFLINEFILES_ITEM_TYPE_SERVER:
                    pszType = L" [SERVER]";
                    break;

                case OFFLINEFILES_ITEM_TYPE_SHARE:
                    pszType = L" [SHARE]";
                    break;

                case OFFLINEFILES_ITEM_TYPE_DIRECTORY:
                    pszType = L" [DIR]";
                    break;

                default:
                    break;
            }
            wprintf(L"%s%s", pszPath, pszType);
        }
        CoTaskMemFree(pszPath);
    }
    return hr;
}

//
// Processes the "current" item then recursively enumerate children
// if the item is a container (server, share, directory).
//
HRESULT ProcessItem(
    IOfflineFilesItem *pItem
    )
{
    HRESULT hr = ReportItem(pItem);
    if (SUCCEEDED(hr))
    {
        IOfflineFilesItemContainer *pContainer;
        hr = pItem->QueryInterface(IID_IOfflineFilesItemContainer,
                                   (void **)&pContainer);
        if (SUCCEEDED(hr))
        {
            EnumItems(pContainer);
            pContainer->Release();
        }
    }
    return hr;
}

//
// Enumerate the items in a container.
//
HRESULT EnumItems(
    IOfflineFilesItemContainer *pContainer
    )
{
    IEnumOfflineFilesItems *pEnum;
    HRESULT hr = pContainer->EnumItems(0, &pEnum);
    if (SUCCEEDED(hr))
    {
        IOfflineFilesItem *pItem;
        ULONG celt;
        while(S_OK == (hr = pEnum->Next(1, &pItem, &celt)))
        {
            ProcessItem(pItem);
            pItem->Release();
        }
        pEnum->Release();
    }
    return hr;
}

HRESULT EnumItemsInCache(
    IOfflineFilesCache *pCache
    )
{
    //
    // The "cache" object is a container of "server" items.
    //
    IOfflineFilesItemContainer *pContainer;
    HRESULT hr = pCache->QueryInterface(IID_IOfflineFilesItemContainer,
                                        (void **)&pContainer);
    if (SUCCEEDED(hr))
    {
        hr = EnumItems(pContainer);
    }
    return hr;
}

int wmain(int argc, __in_ecount(argc) WCHAR* argv[])
{
    HRESULT hr = CoInitialize(NULL);
    if (SUCCEEDED(hr))
    {
        //
        // The "cache" object is the entry point into the
        // Offline Files COM API.
        //
        IOfflineFilesCache *pCache;
        hr = CoCreateInstance(CLSID_OfflineFilesCache,
                              NULL,
                              CLSCTX_INPROC_SERVER,
                              IID_IOfflineFilesCache,
                              (void **)&pCache);
        if (SUCCEEDED(hr))
        {
            hr = EnumItemsInCache(pCache);
            pCache->Release();
        }
        CoUninitialize();
    }
    return 0;
}

```

## See also

[IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem)

[IOfflineFilesItemContainer](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemcontainer)