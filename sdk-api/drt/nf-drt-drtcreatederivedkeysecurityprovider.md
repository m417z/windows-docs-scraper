# DrtCreateDerivedKeySecurityProvider function

## Description

The **DrtCreateDerivedKeySecurityProvider** function creates the derived key security provider for a Distributed Routing Table.

## Parameters

### `pRootCert` [in]

Pointer to the certificate that is the "root" portion of the chain. This is used to ensure that keys derived from the same chain can be verified.

### `pLocalCert` [out]

Pointer to the [DRT_SECURITY_PROVIDER](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_security_provider) module to be included in the [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) structure.

### `ppSecurityProvider`

Receives a pointer to the created security provider.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pRootCert* is **NULL**. |
| **E_OUTOFMEMORY** | The system could not allocate memory for the security provider. |
| **DRT_E_CAPABILITY_MISMATCH** | * The requested security algorithms are not available ( ie. BCRYPT_SHA256_ALGORITHM or BCRYPT_AES_ALGORITHM).<br>* The [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) operation failed.<br>* The *dwProvType* parameter indicates that the certificate provider is not AES capable. |
| **DRT_E_INVALID_CERT_CHAIN** | No certificate store attached or there is an error in the certificate chain. |

## Remarks

The security provider created by this function is specific to the DRT it was created for. It cannot be shared by multiple DRT instances.

## See also

[DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration)

[DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings)

[DrtCreateDerivedKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatederivedkey)

[DrtDeleteDerivedKeySecurityProvider](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtdeletederivedkeysecurityprovider)