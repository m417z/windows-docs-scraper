# ICertPropertyKeyProvInfo::Initialize

## Description

The **Initialize** method initializes the object from a private key.

## Parameters

### `pValue` [in]

Pointer to an [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interface that represents the private key.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CERTSRV_E_PROPERTY_EMPTY**** | The [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) pointer is **NULL**. |
| ****ERROR_ARITHMETIC_OVERFLOW**** | The unique container name and the provider name are too long. |

## Remarks

Call the [SetValueOnCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertproperty-setvalueoncertificate) method to associate the property with a certificate. Call the [PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertykeyprovinfo-get_privatekey) property to retrieve the key.

The **Initialize** method opens the private key and verifies that the following [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) properties are set:

* [CspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_cspinformations)
* [ContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containername)
* [UniqueContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_uniquecontainername)
* [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype)
* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec)
* [MachineContext](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_machinecontext)

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyKeyProvInfo](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertykeyprovinfo)