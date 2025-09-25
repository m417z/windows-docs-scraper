# IEnroll::enumProvidersWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **enumProvidersWStr** method retrieves the names of the available [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSPs) specified by the
[ProviderType](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_providertype) property. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `dwIndex` [in]

Specifies the ordinal position of the CSP whose name will be retrieved. Specify zero for the first CSP.

### `dwFlags` [in]

Specifies flags that are passed through to the [CryptEnumProviders](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumprovidersa) function. Not currently used; specify zero.

### `pbstrProvName` [out]

A pointer to a **LPWSTR** variable that receives the name of a CSP with the specified property type.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. The value ERROR_NO_MORE_ITEMS is returned when there are no more CSPs with the property type indicated by the
[ProviderType](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_providertype) property.

## Remarks

If the
[ProviderType](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_providertype) property value has not been set, the default value (usually PROV_RSA_FULL) of **ProviderType** as set in the registry is used.

The **enumProvidersWStr** method calls the
[CryptEnumProviders](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumprovidersa) function.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)