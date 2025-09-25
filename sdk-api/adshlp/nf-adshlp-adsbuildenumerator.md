# ADsBuildEnumerator function

## Description

The **ADsBuildEnumerator** function creates an enumerator object for the specified ADSI container object.

## Parameters

### `pADsContainer` [in]

Type: **IADsContainer***

Pointer to the [IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer) interface for the object to enumerate.

### `ppEnumVariant` [out]

Type: **IEnumVARIANT****

Pointer to an [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface pointer that receives the enumerator object created for the specified container object.

## Return value

Type: **HRESULT**

This method supports the standard **HRESULT** return values, including **S_OK** for a successful operation. For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The **ADsBuildEnumerator** helper function wraps the calls used to retrieve the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface on the enumerator object.

**To enumerate the available objects in a container**

1. Call the **ADsBuildEnumerator** function to create an [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) object that will enumerate the contents of the container.
2. Call the [ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext) function as many times as necessary to retrieve the items from the enumerator object.
3. Call the [ADSFreeEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsfreeenumerator) function to release the enumerator object when it is no longer required.

If the server supports paged searches and the client has specified a page size that exceeds the maximum search results allowed by the server, the **ADsBuildEnumerator** function will forward errors and results from the server to the user.

#### Examples

The following code example shows how the **ADsBuildEnumerator**, [ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext), and [ADSFreeEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsfreeenumerator) functions can be used to enumerate the contents of a container.

```cpp
HRESULT PrintAllObjects(IADsContainer* pContainer)
{
    HRESULT hr;

    if(NULL == pContainer)
    {
        return E_INVALIDARG;
    }

    IEnumVARIANT *pEnum = NULL;

    // Create an enumerator object in the container.
    hr = ADsBuildEnumerator(pContainer, &pEnum);
    if(SUCCEEDED(hr))
    {
        VARIANT var;
        ULONG ulFetched = 0L;

        // Get the next contained object.
        while(S_OK == (hr = ADsEnumerateNext(pEnum, 1, &var, &ulFetched)) && (ulFetched > 0))
        {
            IADs *pADs;

            // Print the object
            hr = V_DISPATCH(&var)->QueryInterface(IID_IADs, (void**)&pADs);
            if(SUCCEEDED(hr))
            {
                CComBSTR sbstr;
                IADsContainer *pChildContainer;

                hr = pADs->get_Name(&sbstr);
                if(SUCCEEDED(hr))
                {
                    wprintf(sbstr);
                    wprintf(L"\n");
                }

                hr = pADs->QueryInterface(IID_IADsContainer, (void**)&pChildContainer);
                if(SUCCEEDED(hr))
                {
                    // If the retrieved object is a container, recursively print its contents as well.
                    PrintAllObjects(pChildContainer);
                }

                pADs->Release();
            }

            // Release the VARIANT.
            VariantClear(&var);
        }

        ADsFreeEnumerator(pEnum);
    }

    return hr;
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext)

[ADsFreeEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsfreeenumerator)

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)