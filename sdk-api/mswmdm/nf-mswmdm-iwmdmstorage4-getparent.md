# IWMDMStorage4::GetParent

## Description

The **GetParent** method retrieves the parent of the storage.

## Parameters

### `ppStorage` [out]

Pointer to the [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface of the parent storage. The caller must release this interface when finished with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The application can navigate up the storage hierarchy by calling **GetParent** recursively. After the root storage is reached, **GetParent** returns S_FALSE and sets *ppStorage* to **NULL**.

#### Examples

The following C++ function traverses up to the root parent of a storage.

```cpp

HRESULT BubbleUp(IWMDMStorage *pIStorage)
{
    HRESULT hr = S_OK;
    CComPtr<IWMDMStorage4> pStorage4;

    hr = pIStorage->QueryInterface (__uuidof(IWMDMStorage4), reinterpret_cast<void**>(&pStorage4));
    if (SUCCEEDED(hr))
    {
        while ((pStorage4 != NULL))
        {
            CComPtr<IWMDMStorage> pParent;
            hr = pStorage4->GetParent(&pParent);
            if (FAILED(hr))
            {
                break;
            }

            //
            // Do something with pParent....
            //

            if (S_FALSE != hr)
            {
                hr = pParent->QueryInterface (__uuidof(IMDSPStorage4), reinterpret_cast<void**>(&pStorage4));
                if (FAILED(hr))
                {
                    break;
                }
            }
        } // Loop up to next parent.
    }

    return hr;
}

```

## See also

[IWMDMStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage4)