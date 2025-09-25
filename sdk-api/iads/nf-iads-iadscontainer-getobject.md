# IADsContainer::GetObject

## Description

The **IADsContainer::GetObject** method retrieves an
interface for a directory object in the container.

## Parameters

### `ClassName` [in]

A **BSTR** that specifies the name of the object class as of the object to retrieve. If this parameter is **NULL**, the provider returns the first item found in the container.

### `RelativeName` [in]

A **BSTR** that specifies the relative distinguished name of the object to retrieve.

### `ppObject` [out]

A pointer to a pointer to the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface on the specified object.

## Return value

This method supports standard return values, including S_OK for a successful operation. For more information about error codes, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

For the LDAP provider, the *bstrRelativeName* parameter must contain the name prefix, such as "CN=Jeff Smith". The *bstrRelativeName* parameter can also contain more than one level of name, such as "CN=Jeff Smith,OU=Sales".

In C++, when **GetObject** has succeeded, the caller must query the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface for the desired interface using the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method.

The *bstrClassName* parameter can be either a valid class name or **NULL**. If the class name is not valid, including when it contains a blank space, this method will throw an [E_ADS_UNKNOWN_OBJECT](https://learn.microsoft.com/windows/desktop/ADSI/generic-adsi-error-codes) error.

#### Examples

The following code example retrieves a user object from a container object.

```vb
Dim cont As IADsContainer
Dim usr As IADsUser
Set cont = GetObject("LDAP://OU=Sales,DC=Fabrikam,DC=com")
Set usr = cont.GetObject("user", "CN=jeffsmith")
```

This is equivalent to:

```vb
Dim usr As IADsUser
Set usr=GetObject("LDAP://CN=jeffsmith,OU=Sales,DC=Fabrikam,DC=com")
```

The following code example retrieves a user object from a container object.

```cpp
HRESULT hr = S_OK;
CoInitialize(NULL);

IADsContainer *pCont = NULL;

hr = ADsGetObject(L"LDAP://DC=windows2000,DC=mytest,DC=fabrikam,DC=com",
            IID_IADsContainer,
            (void**) &pCont );

if(FAILED(hr))
{
    goto Cleanup;
}

///////////////////////////////////////////////////////////////////////
// Retrieve the child from the container.
// Be aware that in the LDAP provider you can navigate multiple levels.
///////////////////////////////////////////////////////////////////////
IDispatch *pDisp = NULL;
IADs *pADs = NULL;
hr = pCont->GetObject(CComBSTR("user"), CComBSTR("CN=Jeff Smith,OU=DSys"), &pDisp);
pCont->Release();
if(FAILED(hr))
{
    goto Cleanup;
}

hr = pDisp->QueryInterface(IID_IADs, (void**)&pADs);
pDisp->Release();
if(FAILED(hr))
{
    goto Cleanup;
}

// Perform an operation with pADs.
pADs->Release();

Cleanup:
if(pCont)
    pCont->Release();

if(pDisp)
    pDisp->Release();

if(pADs)
    pADs->Release();

CoUninitialize();
```

## See also

[ADSI Error
Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADsGetObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetobject)

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

**IADs::get_Class**

**IADs::get_Name**

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)