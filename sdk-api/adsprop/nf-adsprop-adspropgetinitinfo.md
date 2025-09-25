# ADsPropGetInitInfo function

## Description

The **ADsPropGetInitInfo** function is used to obtain directory object data that an Active Directory Domain Services property sheet extension applies to.

## Parameters

### `hNotifyObj` [in]

The handle of the notification object. To obtain this handle, call [ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj).

### `pInitParams` [out]

Pointer to an [ADSPROPINITPARAMS](https://learn.microsoft.com/windows/desktop/api/adsprop/ns-adsprop-adspropinitparams) structure that receives the directory object data. The **dwSize** member of this structure must be entered before calling this function.

## Return value

Returns nonzero if successful or zero otherwise.

## Remarks

The memory for the **pwzCN** and **pWritableAttrs** members is allocated by the **ADsPropGetInitInfo** function. This memory is freed by the system after all property sheet objects are destroyed. The reference count for the interface pointer in **pDsObj** is not incremented by calling **ADsPropGetInitInfo**, so the interface must not be released by the caller.

For multiple-selection property sheets, the system only binds to the first object in the [DSOBJECT](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobject) array. Because of this, **ADsPropGetInitInfo** only supplies the [IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject) and writable attributes for the first object in the array. The other objects in the array are not bound to.

#### Examples

The following code example shows how to use the **ADsPropGetInitInfo** function.

```cpp
HRESULT GetADsPageInfo(HWND hwndNotifyObject, ADSPROPINITPARAMS *pip)
{
    if((NULL == pip) || (!IsWindow(hwndNotifyObject)))
    {
        return E_INVALIDARG;
    }

    ADSPROPINITPARAMS   InitParams;

    InitParams.dwSize = sizeof(ADSPROPINITPARAMS);
    if(ADsPropGetInitInfo(hwndNotifyObject, &InitParams))
    {
        *pip = InitParams;

        return InitParams.hr;
    }

    return E_FAIL;
}

```

## See also

[ADSPROPINITPARAMS](https://learn.microsoft.com/windows/desktop/api/adsprop/ns-adsprop-adspropinitparams)

[ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj)