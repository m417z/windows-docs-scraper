# ICEnroll::enumProviders

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **enumProviders** method retrieves the names of the available [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSPs) specified by the
[ProviderType](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_providertype) property. This method was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

## Parameters

### `dwIndex` [in]

Specifies the ordinal position of the CSP whose name will be retrieved. Specify zero for the first CSP.

### `dwFlags` [in]

Specifies flags that are passed through to the [CryptEnumProviders](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumprovidersa) function. This parameter is not currently used; specify zero.

### `pbstrProvName` [out]

A pointer to a **BSTR** variable that receives the name of a CSP with the specified property type. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates success. The value ERROR_NO_MORE_ITEMS is returned when there are no more CSPs with the property type indicated by the
[ProviderType](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_providertype) property.

### VB

The return value is a **String** variable that contains the name of a CSP. An exception is raised if an error is encountered or when there are no more items.

## Remarks

If the
[ProviderType](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_providertype) property value has not been set, the default value (usually PROV_RSA_FULL) of **ProviderType** as set in the registry, is used.

The **enumProviders** method calls the
[CryptEnumProviders](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumprovidersa) function.

#### Examples

```cpp
BSTR       bstrProvName = NULL;
DWORD      nProv;
int        j;
HRESULT    hr;

// array of CSP provider types (see Wincrypt.h)
DWORD      nProvType[] = { PROV_RSA_FULL,
                           PROV_RSA_SIG,
                           // list shortened for brevity
                           //...
                           PROV_STT_ISS };

// Loop, for each Prov Type.
for (j = 0; j < (sizeof(nProvType)/sizeof(DWORD)); j++)
{
    nProv = 0;

    // pEnroll is previously instantiated ICEnroll interface pointer
    hr = pEnroll->put_ProviderType( nProvType[j] );
    if ( FAILED(hr))
    {
        printf("Failed put_ProviderType - %x\n", hr);
        goto error;
    }
    // Enumerate the CSPs of this type.
    while ( S_OK == ( hr = pEnroll->enumProviders(nProv,
                                                  0,
                                                  &bstrProvName)))
    {
        printf("Provider %ws (type %d )\n", bstrProvName,
            nProvType[j] );
        nProv++;
        if ( bstrProvName )
        {
            SysFreeString( bstrProvName );
            bstrProvName = NULL;
        }
    }

    // Print message if provider type does not have any CSPs.
    if ( 0 == nProv )
       printf("There were no CSPs of type %d\n", dwType );
}

error:
// Clean up resources, and so on.
if ( bstrProvName )
    SysFreeString( bstrProvName );
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll)

[ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2)

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[ProviderType](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_providertype)