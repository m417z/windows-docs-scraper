# ICEnroll4::getProviderType

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **getProviderType** method retrieves the type of the specified [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `strProvName` [in]

A string value that specifies the name of the CSP whose type is being requested.

### `plProvType` [out]

A pointer to **LONG** value that receives the CSP type. The CSP type is one of the following values.

* PROV_DH_SCHANNEL
* PROV_DSS
* PROV_DSS_DH
* PROV_FORTEZZA
* PROV_MS_EXCHANGE
* PROV_RSA_FULL
* PROV_RSA_SCHANNEL
* PROV_RSA_SIG
* PROV_SSL

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

A value that represents the provider type for the provider specified by *strProvName*. This can be one of the following values.

* PROV_RSA_FULL
* PROV_RSA_SIG
* PROV_DSS
* PROV_FORTEZZA
* PROV_MS_EXCHANGE
* PROV_SSL
* PROV_RSA_SCHANNEL
* PROV_DSS_DH
* PROV_DH_SCHANNEL

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)