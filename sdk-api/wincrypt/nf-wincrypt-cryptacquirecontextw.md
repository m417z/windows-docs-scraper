# CryptAcquireContextW function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptAcquireContext** function is used to acquire a handle to a particular [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) within a particular [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This returned handle is used in calls to [CryptoAPI](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) functions that use the selected CSP.

This function first attempts to find a CSP with the characteristics described in the *dwProvType* and *pszProvider* parameters. If the CSP is found, the function attempts to find a key container within the CSP that matches the name specified by the *pszContainer* parameter. To acquire the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and the key container of a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) associated with the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of a certificate, use
[CryptAcquireCertificatePrivateKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecertificateprivatekey).

With the appropriate setting of *dwFlags*, this function can also create and destroy key containers and can provide access to a CSP with a temporary key container if access to a private key is not required.

## Parameters

### `phProv` [out]

A pointer to a handle of a CSP. When you have finished using the CSP, release the handle by calling the [CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext) function.

### `szContainer` [in]

The key container name. This is a null-terminated string that identifies the key container to the CSP. This name is independent of the method used to store the keys. Some CSPs store their key containers internally (in hardware), some use the system registry, and others use the file system. In most cases, when *dwFlags* is set to CRYPT_VERIFYCONTEXT, *pszContainer* must be set to **NULL**. However, for hardware-based CSPs, such as a smart card CSP, can be access publicly available information in the specfied container.

For more information about the usage of the *pszContainer* parameter, see Remarks.

### `szProvider` [in]

A null-terminated string that contains the name of the CSP to be used.

If this parameter is **NULL**, the user default provider is used. For more information, see
[Cryptographic Service Provider Contexts](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-service-provider-contexts). For a list of available cryptographic providers, see
[Cryptographic Provider Names](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-names).

An application can obtain the name of the CSP in use by using the [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) function to read the PP_NAME CSP value in the *dwParam* parameter.

The default CSP can change between operating system releases. To ensure interoperability on different operating system platforms, the CSP should be explicitly set by using this parameter instead of using the default CSP.

### `dwProvType` [in]

Specifies the type of provider to acquire. Defined provider types are discussed in
[Cryptographic Provider Types](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-types).

### `dwFlags` [in]

One or more of the following flags. Note, most applications should set the **CRYPT_VERIFYCONTEXT** flag unless they need to create digital signatures or decrypt messages.

| Value | Meaning |
| --- | --- |
| **CRYPT_VERIFYCONTEXT** | The caller does not need access to persisted private keys. Apps that use ephemeral keys, or that perform only [hashing](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly), [encryption](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly), and [digital signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) verification should set this flag. Only applications that create signatures or decrypt messages need access to a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (and should not set this flag). <br><br>For file-based CSPs, when this flag is set, the *pszContainer* parameter must be set to **NULL**. The application has no access to the persisted private keys of public/private key pairs. When this flag is set, temporary [public/private key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) can be created, but they are not persisted.<br><br>For hardware-based CSPs, such as a smart card CSP, if the *pszContainer* parameter is **NULL** or blank, this flag implies that no access to any keys is required, and that no UI should be presented to the user. This form is used to connect to the CSP to query its capabilities but not to actually use its keys. If the *pszContainer* parameter is not **NULL** and not blank, then this flag implies that access to only the publicly available information within the specified container is required. The CSP should not ask for a PIN. Attempts to access private information (for example, the [CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha) function) will fail.<br><br>When **CryptAcquireContext** is called, many CSPs require input from the owning user before granting access to the private keys in the [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). For example, the private keys can be encrypted, requiring a password from the user before they can be used. However, if the **CRYPT_VERIFYCONTEXT** flag is specified, access to the private keys is not required and the user interface can be bypassed. |
| **CRYPT_NEWKEYSET** | Creates a new key container with the name specified by *pszContainer*. If *pszContainer* is **NULL**, a key container with the default name is created. |
| **CRYPT_MACHINE_KEYSET** | By default, keys and key containers are stored as user keys. For Base Providers, this means that user key containers are stored in the user's profile. A key container created without this flag by an administrator can be accessed only by the user creating the key container and a user with administration privileges.<br><br>**Windows XP:** A key container created without this flag by an administrator can be accessed only by the user creating the key container and the local system account.<br><br>A key container created without this flag by a user that is not an administrator can be accessed only by the user creating the key container and the local system account.<br><br>The CRYPT_MACHINE_KEYSET flag can be combined with all of the other flags to indicate that the key container of interest is a computer key container and the CSP treats it as such. For Base Providers, this means that the keys are stored locally on the computer that created the key container. If a key container is to be a computer container, the CRYPT_MACHINE_KEYSET flag must be used with all calls to **CryptAcquireContext** that reference the computer container. The key container created with CRYPT_MACHINE_KEYSET by an administrator can be accessed only by its creator and by a user with administrator [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) unless access rights to the container are granted using [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam).<br><br>**Windows XP:** The key container created with CRYPT_MACHINE_KEYSET by an administrator can be accessed only by its creator and by the local system account unless access rights to the container are granted using [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam).<br><br>The key container created with CRYPT_MACHINE_KEYSET by a user that is not an administrator can be accessed only by its creator and by the local system account unless access rights to the container are granted using [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam).<br><br>The CRYPT_MACHINE_KEYSET flag is useful when the user is accessing from a service or user account that did not log on interactively. When key containers are created, most CSPs do not automatically create any [public/private key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). These keys must be created as a separate step with the [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) function. |
| **CRYPT_DELETEKEYSET** | Delete the [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) specified by *pszContainer*. If *pszContainer* is **NULL**, the key container with the default name is deleted. All [key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) in the key container are also destroyed. <br><br>When this flag is set, the value returned in *phProv* is undefined, and thus, the [CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext) function need not be called afterward. |
| **CRYPT_SILENT** | The application requests that the CSP not display any user interface (UI) for this [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). If the CSP must display the UI to operate, the call fails and the NTE_SILENT_CONTEXT error code is set as the last error. In addition, if calls are made to [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) with the CRYPT_USER_PROTECTED flag with a context that has been acquired with the CRYPT_SILENT flag, the calls fail and the CSP sets NTE_SILENT_CONTEXT.<br><br>CRYPT_SILENT is intended for use with applications for which the UI cannot be displayed by the CSP. |
| **CRYPT_DEFAULT_CONTAINER_OPTIONAL** | Obtains a context for a smart card CSP that can be used for hashing and symmetric key operations but cannot be used for any operation that requires authentication to a smart card using a PIN. This type of context is most often used to perform operations on an empty smart card, such as setting the PIN by using [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam). This flag can only be used with smart card CSPs. <br><br>**Windows Server 2003 and Windows XP:** This flag is not supported. |

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by NTE are generated by the particular CSP being used. Some possible error codes defined in Winerror.h follow.

| Return code/value | Description |
| --- | --- |
| **ERROR_BUSY**<br><br>107L | Some CSPs set this error if the CRYPT_DELETEKEYSET flag value is set and another thread or [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) is using this [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). |
| **ERROR_FILE_NOT_FOUND**<br><br>2L | The profile of the user is not loaded and cannot be found. This happens when the application impersonates a user, for example, the IUSR_*ComputerName* account. |
| **ERROR_INVALID_PARAMETER**<br><br>87L | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY**<br><br>8L | The operating system ran out of memory during the operation. |
| **NTE_BAD_FLAGS**<br><br>0x80090009L | The *dwFlags* parameter has a value that is not valid. |
| **NTE_BAD_KEY_STATE**<br><br>0x8009000BL | The user password has changed since the private keys were encrypted. |
| **NTE_BAD_KEYSET**<br><br>0x80090016L | The key container could not be opened. A common cause of this error is that the key container does not exist. To create a key container, call [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) using the CRYPT_NEWKEYSET flag. This error code can also indicate that access to an existing key container is denied. Access rights to the container can be granted by the key set creator by using [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam). |
| **NTE_BAD_KEYSET_PARAM**<br><br>0x8009001FL | The *pszContainer* or *pszProvider* parameter is set to a value that is not valid. |
| **NTE_BAD_PROV_TYPE**<br><br>0x80090014L | The value of the *dwProvType* parameter is out of range. All provider types must be from 1 through 999, inclusive. |
| **NTE_BAD_SIGNATURE**<br><br>0x80090006L | The provider DLL signature could not be verified. Either the DLL or the digital signature has been tampered with. |
| **NTE_EXISTS**<br><br>0x8009000FL | The *dwFlags* parameter is CRYPT_NEWKEYSET, but the key container already exists. |
| **NTE_KEYSET_ENTRY_BAD**<br><br>0x8009001AL | The *pszContainer* key container was found but is corrupt. |
| **NTE_KEYSET_NOT_DEF**<br><br>0x80090019L | The requested provider does not exist. |
| **NTE_NO_MEMORY**<br><br>0x8009000EL | The CSP ran out of memory during the operation. |
| **NTE_PROV_DLL_NOT_FOUND**<br><br>0x8009001EL | The provider DLL file does not exist or is not on the current path. |
| **NTE_PROV_TYPE_ENTRY_BAD**<br><br>0x80090018L | The provider type specified by *dwProvType* is corrupt. This error can relate to either the user default CSP list or the computer default CSP list. |
| **NTE_PROV_TYPE_NO_MATCH**<br><br>0x8009001BL | The provider type specified by *dwProvType* does not match the provider type found. Note that this error can only occur when *pszProvider* specifies an actual CSP name. |
| **NTE_PROV_TYPE_NOT_DEF**<br><br>0x80090017L | No entry exists for the provider type specified by *dwProvType*. |
| **NTE_PROVIDER_DLL_FAIL**<br><br>0x8009001DL | The provider DLL file could not be loaded or failed to initialize. |
| **NTE_SIGNATURE_FILE_BAD**<br><br>0x8009001CL | An error occurred while loading the DLL file image, prior to verifying its signature. |

## Remarks

The *pszContainer* parameter specifies the name of the container that is used to hold the key. Each container can contain one key. If you specify the name of an existing container when creating keys, the new key will overwrite a previous one.

The combination of the CSP name and the key container name uniquely identifies a single key on the system. If one application tries to modify a key container while another application is using it, unpredictable behavior may result.

If you set the *pszContainer* parameter to **NULL**, the default key container name is used. When the Microsoft software CSPs are called in this manner, a new container is created each time the **CryptAcquireContext** function is called. However, different CSPs may behave differently in this regard. In particular, a CSP may have a single default container that is shared by all applications accessing the CSP. Therefore, applications must not use the default key container to store private keys. Instead, either prevent key storage by passing the **CRYPT_VERIFYCONTEXT** flag in the *dwFlags* parameter, or use an application-specific container that is unlikely to be used by another application.

An application can obtain the name of the key container in use by using the
[CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) function to read the PP_CONTAINER value.

For performance reasons, we recommend that you set the *pszContainer* parameter to **NULL** and the *dwFlags* parameter to **CRYPT_VERIFYCONTEXT** in all situations where you do not require a persisted key. In particular, consider setting the *pszContainer* parameter to **NULL** and the *dwFlags* parameter to **CRYPT_VERIFYCONTEXT** for the following scenarios:

* You are creating a hash.
* You are generating a symmetric key to encrypt or decrypt data.
* You are deriving a symmetric key from a hash to encrypt or decrypt data.
* You are verifying a signature. It is possible to import a public key from a PUBLICKEYBLOB or from a certificate by using [CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) or [CryptImportPublicKeyInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfoex2).
  A context can be acquired by using the **CRYPT_VERIFYCONTEXT** flag if you only plan to import the public key.
* You plan to export a symmetric key, but not import it within the crypto context's lifetime. A context can be acquired by using the **CRYPT_VERIFYCONTEXT** flag if you only plan to import the public key for the last two scenarios.
* You are performing private key operations, but you are not using a persisted private key that is stored in a key container.

If you plan to perform private key operations, the best way to acquire a context is to try to open the container. If this attempt fails with NTE_BAD_KEYSET, then create the container by using the **CRYPT_NEWKEYSET** flag.

#### Examples

The following example shows acquiring a cryptographic context and access to public/private key pairs in a key container. If the requested key container does not exist, it is created.

For an example that includes the complete context for this example, see [Example C Program: Creating a Key Container and Generating Keys](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-creating-a-key-container-and-generating-keys). For additional examples, see
[Example C Program: Using CryptAcquireContext](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-using-cryptacquirecontext).

```cpp
//-------------------------------------------------------------------
// Declare and initialize variables.

HCRYPTPROV hCryptProv = NULL;        // handle for a cryptographic
                                     // provider context
LPCSTR UserName = "MyKeyContainer";  // name of the key container
                                     // to be used
//-------------------------------------------------------------------
// Attempt to acquire a context and a key
// container. The context will use the default CSP
// for the RSA_FULL provider type. DwFlags is set to zero
// to attempt to open an existing key container.

if(CryptAcquireContext(
   &hCryptProv,               // handle to the CSP
   UserName,                  // container name
   NULL,                      // use the default provider
   PROV_RSA_FULL,             // provider type
   0))                        // flag values
{
    printf("A cryptographic context with the %s key container \n",
  UserName);
    printf("has been acquired.\n\n");
}
else
{
//-------------------------------------------------------------------
// An error occurred in acquiring the context. This could mean
// that the key container requested does not exist. In this case,
// the function can be called again to attempt to create a new key
// container. Error codes are defined in Winerror.h.
 if (GetLastError() == NTE_BAD_KEYSET)
 {
   if(CryptAcquireContext(
      &hCryptProv,
      UserName,
      NULL,
      PROV_RSA_FULL,
      CRYPT_NEWKEYSET))
    {
      printf("A new key container has been created.\n");
    }
    else
    {
      printf("Could not create a new key container.\n");
      exit(1);
    }
  }
  else
  {
      printf("A cryptographic service handle could not be "
          "acquired.\n");
      exit(1);
   }

} // End of else.
//-------------------------------------------------------------------
// A cryptographic context and a key container are available. Perform
// any functions that require a cryptographic provider handle.

//-------------------------------------------------------------------
// When the handle is no longer needed, it must be released.

if (CryptReleaseContext(hCryptProv,0))
{
  printf("The handle has been released.\n");
}
else
{
  printf("The handle could not be released.\n");
}
```

> [!NOTE]
> The wincrypt.h header defines CryptAcquireContext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey)

[CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam)

[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext)

[Service Provider Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)