# IEnroll4::getProviderTypeWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **getProviderTypeWStr** method retrieves the type of the specified [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Parameters

### `pwszProvName` [in]

A pointer to a null-terminated wide character string that contains the name of the CSP whose type is being requested. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

### `plProvType` [out]

A pointer to a **LONG** value that receives the CSP type. The CSP type is one of the following values:

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

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)