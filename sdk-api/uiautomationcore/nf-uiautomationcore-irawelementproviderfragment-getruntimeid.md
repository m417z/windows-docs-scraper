# IRawElementProviderFragment::GetRuntimeId

## Description

Retrieves the runtime identifier of an element.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives a pointer to the runtime identifier. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Implementations should return **NULL** for a top-level element that is hosted in a window.
Other elements should return an array that contains **UiaAppendRuntimeId**
(defined in Uiautomationcoreapi.h),
followed by a value that is unique within an instance of the fragment.

#### Examples

The following implementation for a list item returns a runtime identifier made up of the
**UiaAppendRuntimeId** constant and the index of the item within the list.

```cpp
HRESULT STDMETHODCALLTYPE ListItemProvider::GetRuntimeId(SAFEARRAY ** pRetVal)
{
    if (pRetVal == NULL)
    {
        return E_INVALIDARG;
    }

    int rId[] = { UiaAppendRuntimeId, m_itemIndex };
    SAFEARRAY *psa = SafeArrayCreateVector(VT_I4, 0, 2);
    if (psa == NULL)
    {
        return E_OUTOFMEMORY;
    }

    for (LONG i = 0; i < 2; i++)
    {
        SafeArrayPutElement(psa, &i, (void*)&(rId[i]));
    }

    *pRetVal = psa;
    return S_OK;
}
```

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)

**Reference**