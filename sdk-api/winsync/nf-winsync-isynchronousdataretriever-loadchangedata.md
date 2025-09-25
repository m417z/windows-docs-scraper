# ISynchronousDataRetriever::LoadChangeData

## Description

Retrieves item data for a change.

## Parameters

### `pLoadChangeContext` [in]

Metadata that describes the change for which data should be retrieved.

### `ppUnkData` [out]

Returns the item data for the change specified in *pLoadChangeContext*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes.** |  |

## Remarks

The source provider determines the data retrieval interface that is implemented by the object that is returned in *ppUnkData*. The destination provider can acquire this interface by using the **QueryInterface** method of *ppUnkData*.

#### Examples

The following example is an implementation of **LoadChangeData** that finds the specified change in a custom data store and returns a copy of it.

```cpp
STDMETHODIMP CItemStore::LoadChangeData(
    ILoadChangeContext * pLoadChangeContext,
    IUnknown ** ppUnkData)
{
    HRESULT hr = E_UNEXPECTED;

    if (NULL == pLoadChangeContext || NULL == ppUnkData)
    {
        hr = E_POINTER;
    }
    else
    {
        // Find the item in the data store, clone it, and return its IUnknown interface.
        ISyncChange* pChange = NULL;
        hr = pLoadChangeContext->GetSyncChange(&pChange);
        if (SUCCEEDED(hr))
        {
            SYNC_GID gidItem;
            DWORD cbID = sizeof(gidItem);
            hr = pChange->GetRootItemId((BYTE*)&gidItem, &cbID);
            if (SUCCEEDED(hr))
            {
                IXMLDOMNode* pNodeItem = NULL;
                hr = FindItem(&gidItem, &pNodeItem);
                if (SUCCEEDED(hr))
                {
                    IXMLDOMNode* pNodeClone = NULL;
                    hr = pNodeItem->cloneNode(TRUE, &pNodeClone);
                    if (SUCCEEDED(hr))
                    {
                        hr = pNodeClone->QueryInterface(IID_IUnknown, (void**)ppUnkData);

                        pNodeClone->Release();
                    }

                    pNodeItem->Release();
                }
            }

            pChange->Release();
        }
    }

    return hr;
}
```

## See also

[ILoadChangeContext Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iloadchangecontext)

[ISynchronousDataRetriever Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever)