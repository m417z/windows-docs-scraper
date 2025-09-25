# IDsDisplaySpecifier::GetDisplaySpecifier

## Description

The **IDsDisplaySpecifier::GetDisplaySpecifier** method binds to the display specifier object for a given class in Active Directory Domain Services.

## Parameters

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the object class to retrieve the display specifier for.

### `riid` [in]

Contains the interface identifier of the desired interface.

### `ppv` [in, out]

Pointer to an interface pointer that receives the display specifier of the object class.

## Return value

Returns a standard **HRESULT** value including the following.

## Remarks

This method uses the
[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject) function to bind to the display specifier object of the given class. If that fails, it attempts to bind to the display specifier in the user locale. If this fails again, it binds to the display specifier in the default locale.

This method uses the server and user credentials set by a previous call to
[IDsDisplaySpecifier::SetServer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-setserver).

#### Examples

The following code example demonstrates how to call this method.

```cpp
HRESULT hr;
IDsDisplaySpecifier *pDS;

hr = CoCreateInstance(CLSID_DsDisplaySpecifier,
                        NULL,
                        CLSCTX_INPROC_SERVER,
                        IID_IDsDisplaySpecifier,
                        (void**)&pDS);
if(SUCCEEDED(hr))
{
    IADs *pads;

    hr = pDS->GetDisplaySpecifier(L"user", IID_IADs, (LPVOID*)&pads);

    if(SUCCEEDED(hr))
    {
        pads->Release();
    }

    pDS->Release();
}

```

## See also

[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject)

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)

[IDsDisplaySpecifier::SetServer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-setserver)