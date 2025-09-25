# ADsBuildVarArrayStr function

## Description

The **ADsBuildVarArrayStr** function builds a variant array from an array of Unicode strings.

## Parameters

### `lppPathNames` [in]

Type: **LPWSTR***

Array of null-terminated Unicode strings.

### `dwPathNames` [in]

Type: **DWORD**

Number of Unicode entries in the given array.

### `pVar` [out]

Type: **VARIANT***

Pointer to the resulting variant array.

## Return value

Type: **HRESULT**

This method supports the standard return values, as well as the following.

For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

To support Automation, use the **ADsBuildVarArrayStr** function to convert Unicode strings to a variant array of strings.

#### Examples

The following code example shows how to use the **ADsBuildVarArrayStr** function to convert object class names from Unicode strings to a variant array of strings.

```cpp
HRESULT EnumObject(LPWSTR pszADsPath,
                   LPWSTR * lppClsNames,
                   DWORD dwClsNames)
{
    ULONG ulFetched = 0L;
    IEnumVARIANT * pEnumVar = NULL;
    VARIANT varFilter, varArray[MAX_ADS_ENUM];
    HRESULT hr;
    IADsContainer * pADsContainer = NULL;
    DWORD dwObjects = 0, dwEnumCount=0, i=0;
    BSTR bstrName;
    BOOL fContinue=TRUE;

    hr = ADsGetObject(pszADsPath,
                     IID_IADsContainer,
                     (void**)&pADsContainer);
    if (FAILED(hr)) goto cleanup;

    // Create a string array of class names as search filters.
    VariantInit(&varFilter);
    hr = ADsBuildVarArrayStr(lppClsNames, dwClsNames, &varFilter);
    if (FAILED(hr)) goto cleanup;

    // Apply filters to objects in the container.
    hr = pADsContainer->put_Filter(varFilter);
    if(FAILED(hr)) goto cleanup;

    // Create an enumerator.
    hr = ADsBuildEnumerator(pADsContainer, &pEnumVar);
    if(FAILED(hr)) goto cleanup;

    // Enumerate the objects and print the names.
    while(fContinue) {
        IADs* pObject;
        hr = ADsEnumerateNext(pEnumVar, MAX_ADS_ENUM,
                            varArray, &ulFetched);
        if(hr == S_FALSE) fContinue = FALSE;
        dwEEnumCount++;

        for (i=0; i<ulFetched; i++) {
            IDispatch *pDispatch = NULL;
            pDispatch = varArray[I].pDispVal;
            hr = pDispatch->QueryInterface(IID_IADs,
                                        (void**) &pObject);
            if (FAILED(hr)) goto cleanup;

            hr = pObject->get_Name(&bstrName);
            if(FAILED(hr)) goto cleanup;
            printf(" Object name: %S\n",bstrName);

            // Release the ADSI object.
            SysFreeString(bstrname);
            pObject->Release();
            pDispatch->Release();
        }
        memset(varArray, 0, sizeof(VARIANT)*MAX_ADS_ENUM);
        dwObjects += ulFetched;
    }
    hr = S_OK;

cleanup:
    if(bstrName) SysFreeString(bstrName);
    if(pEnumvar) ADsFreeEnumerator(pEnumVar);
    if(pADsContainer) pADsContainer->Release();

    return (hr);
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsBuildVarArrayInt](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildvararrayint)