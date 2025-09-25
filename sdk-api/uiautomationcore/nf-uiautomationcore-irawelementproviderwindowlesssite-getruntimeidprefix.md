# IRawElementProviderWindowlessSite::GetRuntimeIdPrefix

## Description

Retrieves a Microsoft UI Automation runtime ID that is unique to the windowless Microsoft ActiveX control site.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives the runtime ID.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A UI Automation fragment must implement the [IRawElementProviderFragment::GetRuntimeId](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementproviderfragment-getruntimeid) method to return a unique ID for the fragment. This is difficult for a windowless ActiveX control, which must be able to identify itself as unique among other windowless controls in the ActiveX control container. To resolve this issue, the windowless site should implement the **GetRuntimeIdPrefix** method by forming a [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) that contains the constant **UiaAppendRuntimeId**, followed by an integer value that is unique to this windowless site.

The fragment can then append an integer value that is unique relative to all other fragments in the windowless ActiveX control, and return it to the client.

For example, the site might return a SAFEARRAY with the following contents: `{ UiaAppendRuntimeId, 3 }`. This might represent the third ActiveX control in the container. The fragment provider's [GetRuntimeId](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementproviderfragment-getruntimeid) method could then form a SAFEARRAY with the following contents: `{ UiaAppendRuntimeId, 3, 5 }`. This might represent the fifth fragment within the ActiveX container. The whole SAFEARRAY would be a unique ID relative to the whole ActiveX control container.

A provider typically calls this method as part of handling the [GetRuntimeId](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementproviderfragment-getruntimeid) method.

#### Examples

The following C++ code example shows how to implement the **GetRuntimeIdPrefix** method.

```cpp
IFACEMETHODIMP CProviderWindowlessSite::GetRuntimeIdPrefix(
     SAFEARRAY **ppsaPrefix)
{
    if (ppsaPrefix == NULL)
    {
        return E_INVALIDARG;
    }

    // m_siteIndex is the index of the windowless control's
    // site. It is defined by the control container.
    int rId[] = { UiaAppendRuntimeId, m_siteIndex };
    SAFEARRAY *psa = SafeArrayCreateVector(VT_I4, 0, 2);
    if (psa == NULL)
    {
        return E_OUTOFMEMORY;
    }

    for (LONG i = 0; i < 2; i++)
    {
        SafeArrayPutElement(psa, &i, (void*)&(rId[i]));
    }

    *ppsaPrefix = psa;
    return S_OK;
}

```

## See also

[IRawElementProviderWindowlessSite](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderwindowlesssite)