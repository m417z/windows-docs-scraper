# ISyncMgrHandlerInfo::GetTypeLabel

## Description

Gets a label for the handler type. This typically provides the model of the device or an equivalent handler-specific identity string.

## Parameters

### `ppszTypeLabel` [out]

Type: **LPWSTR***

When this method returns, contains a pointer to a buffer containing the label string.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. If the method fails, *ppszTypeLabel* contains an empty string.

## Remarks

The label value is displayed as the System.Sync.HandlerTypeLabel (PKEY_Sync_HandlerTypeLabel) property in the folder UI. Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

The handler is responsible for allocating the string buffer pointed to by *ppszTypeLabel* through [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Sync Center deallocates the string buffer through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::GetTypeLabel(__out LPWSTR *ppszTypeLabel)
{
    LPWSTR pszTypeLabel = NULL;

    HRESULT hr = LoadStringAlloc(g_hmodThisDll,
                                 IDS_HANDLER_TYPE_LABEL,
                                 &pszTypeLabel);
    if (SUCCEEDED(hr))
    {
        // Duplicate for the caller.
        hr = SHCoAllocString(pszTypeLabel, ppszTypeLabel);
        LocalFree(pszTypeLabel);
    }

    return hr;
}

```