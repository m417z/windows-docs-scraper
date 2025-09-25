## Description

The **DrtCreateDerivedKey** function creates a key that can be utilized by [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey) when the DRT is using a derived key security provider.

## Parameters

### `pLocalCert` [in]

Pointer to the certificate that is the "local" portion of the chain. The root of this chain must match the root specified by *pRootCert* in [DrtCreateDerivedKeySecurityProvider](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatederivedkeysecurityprovider). This certificate is used to generate a key that is used to register and prove "key ownership" with the DRT.

### `pKey` [out]

Pointer to the created key.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | * *pLocalCert* is **NULL**.<br>* *pKey* is **NULL**.<br>* The **pb** member in the [DRT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_data) structure is **NULL**.<br>* The **cb** member in the [DRT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_data) structure is not equal to 32 bytes. |
| **DRT_E_CAPABILITY_MISMATCH** | * The requested security algorithms are not available ( ie. BCRYPT_SHA256_ALGORITHM or BCRYPT_AES_ALGORITHM).<br>* The [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) operation failed.<br>* The *dwProvType* parameter indicates that the certificate provider is not AES capable. |

## See also

[DrtCreateDerivedKeySecurityProvider](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatederivedkeysecurityprovider)

[DrtDeleteDerivedKeySecurityProvider](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtdeletederivedkeysecurityprovider)

[DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey)