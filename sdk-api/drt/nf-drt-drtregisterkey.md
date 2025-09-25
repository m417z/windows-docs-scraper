# DrtRegisterKey function

## Description

The **DrtRegisterKey** function registers a key in the DRT.

## Parameters

### `hDrt` [in]

A pointer to a handle returned by the [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen) function.

### `pRegistration` [in]

A pointer to a handle to the [DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration) structure.

### `pvKeyContext` [in, optional]

Pointer to the context data associated with the key in the DRT. This data is passed to the key-specific functions of the security provider.

### `phKeyRegistration` [out]

Pointer to a handle for a key that has been registered.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | * *pRegistration* is **NULL**<br>* The **cb** value of the **appData** member of the [DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration) structure is too large (ie. less than 1).<br>* The **cb** value of the **appData** member of the [DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration) structure is too large (ie. more than 5120).<br>* The **pb** value of the **key** member of the [DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration) structure is **NULL**.<br>* *phKeyRegistration* is **NULL** |
| **E_HANDLE** | *hDrt* is an invalid handle or *phKeyRegistration* is an invalid handle |
| **DRT_E_INVALID_KEY_SIZE** | The size of cb value of the key member of the DRT_REGISTRATION structure is not equal to 256 bits or the **pb** value of the **key** member of the [DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration) structure is **NULL**.. |
| **DRT_E_FAULTED** | The DRT cloud is in the faulted state. |
| **DRT_E_DUPLICATE_KEY** | The key is already registered. |
| **DRT_E_INVALID_CERT_CHAIN** | The provided certification chain is invalid. |
| **DRT_E_CAPABILITY_MISMATCH** | Supplied certificate provider is not AES capable. |
| **DRT_E_INVALID_KEY** | Supplied key does not match generated key. |
| **DRT_E_TRANSPORT_NO_DEST_ADDRESSES** | Valid address not found. |
| **DRT_E_TRANSPORT_SHUTTING_DOWN** | Transport is shutting down. |
| **DRT_E_INVALID_TRANSPORT_PROVIDER** | Transport provider is **NULL**. |
| **DRT_E_TRANSPORTPROVIDER_NOT_ATTACHED** | Transport is not attached. |
| **DRT_E_SECURITYPROVIDER_NOT_ATTACHED** | Security provider is not attached. |
| **DRT_E_TRANSPORT_NOT_BOUND** | Transport is not currently bound. |
| **E_OUTOFMEMORY** | The system is out of memory. |
| **E_UNEXPECTED** | * The GlobalControl.HandleTable is **NULL**.<br>* The cloud is shutting down.<br>* The DRT is shutting down. |
| **E_FAIL** | An unexpected fatal error has occurred. |

**Note** **DrtRegisterKey** may also surface errors from underlying calls to [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam), [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain), [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore), [CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore), [CryptContextAddRef](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcontextaddref), [CryptAcquireCertificatePrivateKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecertificateprivatekey), [CertSaveStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsavestore), [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl), [CryptImportPublicKeyInfoEx2](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfoex2), [NCryptSignHash](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptsignhash), [CertEnumCertificatesInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumcertificatesinstore), [BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty), [BCryptGenRandom](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgenrandom), [BCryptGenerateSymmetricKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratesymmetrickey) and [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt).

## Remarks

 A node can register keys while in the **DRT_ACTIVE**, **DRT_ALONE**, or **DRT_NO_NETWORK** state. However, keys registered in **DRT_ALONE** and **DRT_NO_NETWORK** states can only be recognized by other DRTs after the local node has transitioned to **DRT_ACTIVE**.

 To update an existing key, an application must first deregister the key with [DrtUnregisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtunregisterkey) before calling **DrtRegisterKey** to register the updated key.

## See also

[DRT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_registration)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)

[DrtUnregisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtunregisterkey)