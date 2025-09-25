# IADsContainer::get__NewEnum

## Description

The **IADsContainer::get__NewEnum** method Retrieves an enumerator object for the container. The
enumerator object implements the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface to enumerate the children of the container object.

## Parameters

### `retval` [out]

Pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer that receives the enumerator object. The caller must release this interface when it is no longer required.

## Return value

This method supports the standard return values, including S_OK for a successful operation. For more information about error codes, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

There are two underscore characters ("__") in the function name between "get" and "NewEnum".

In Visual Basic, use the **For****Each**… statement to invoke the **IADsContainer::get__NewEnum** method implicitly.

In C/C++, use the [ADsBuildEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildenumerator), [ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext), and [AdsFreeEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsfreeenumerator) helper functions.

#### Examples

The following code example shows how to enumerate child objects in a container.

```vb
Dim cont As IADsContainer
On Error GoTo Cleanup

Set cont = GetObject("LDAP://OU=Sales,DC=Fabrikam,DC=com")
For Each obj In cont
  Debug.Print obj.Name
Next

Cleanup:
    If(Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set cont = Nothing
```

The following code example shows how to enumerate the object contained in a container.

```cpp
IEnumVARIANT *pEnum = NULL;
IADsContainer *pCont = NULL;
LPUNKNOWN pUnk = NULL;
VARIANT var;
IDispatch *pDisp = NULL;
ulong lFetch;
IADs *pADs = NULL;

// In this sample, skip error checking.
ADsGetObject(L"LDAP://OU=Sales,DC=Fabrikam,DC=COM",
                        IID_IADsContainer, (void**) &pCont);
pCont->get__NewEnum(&pUnk);
pCont->Release();

pUnk->QueryInterface(IID_IEnumVARIANT, (void**) &pEnum);
pUnk->Release();

// Enumerate.
HRESULT hr = pEnum->Next(1, &var, &lFetch);
while(SUCCEEDED(hr) && lFetch > 0)
{
    if (lFetch == 1)
    {
        BSTR bstr;

        pDisp = V_DISPATCH(&var);
        pDisp->QueryInterface(IID_IADs, (void**)&pADs);
        pDisp->Release();
        hr = pADs->get_Name(&bstr);
        if(SUCCEEDED(hr))
        {
            SysFreeString(bstr);
        }

        pADs->Release();
    }

    VariantClear(&var);
    hr = pEnum->Next(1, &var, &lFetch);
};

pEnum->Release();
```

## See also

[ADsBuildEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildenumerator)

[ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext)

[AdsFreeEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsfreeenumerator)

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)