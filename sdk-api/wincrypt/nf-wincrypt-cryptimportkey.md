# CryptImportKey function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptImportKey** function transfers a [cryptographic key](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from a [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) into a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This function can be used to import an [Schannel](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), regular session key, [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), or [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). For all but the public key, the key or key pair is encrypted.

## Parameters

### `hProv` [in]

The handle of a CSP obtained with the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function.

### `pbData` [in]

A **BYTE** array that contains a
[PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc) BLOB header followed by the encrypted key. This key BLOB is created by the
[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) function, either in this application or by another application possibly running on a different computer.

### `dwDataLen` [in]

Contains the length, in bytes, of the key BLOB.

### `hPubKey` [in]

A handle to the cryptographic key that decrypts the key stored in *pbData*. This key must come from the same CSP to which *hProv* refers. The meaning of this parameter differs depending on the CSP type and the type of key BLOB being imported:

* If the key BLOB is encrypted with the key [exchange key pair](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly), for example, a **SIMPLEBLOB**, this parameter can be the handle to the key exchange key.
* If the key BLOB is encrypted with a session key, for example, an encrypted **PRIVATEKEYBLOB**, this parameter contains the handle of this session key.
* If the key BLOB is not encrypted, for example, a **PUBLICKEYBLOB**, this parameter is not used and must be zero.
* If the key BLOB is encrypted with a session key in an [Schannel](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) CSP, for example, an encrypted **OPAQUEKEYBLOB** or any other vendor-specific **OPAQUEKEYBLOB**, this parameter is not used and must be set to zero.

**Note** Some CSPs may modify this parameter as a result of the operation. Applications that subsequently use this key for other purposes should call the [CryptDuplicateKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptduplicatekey) function to create a duplicate key handle. When the application has finished using the handle, release it by calling the [CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey) function.

### `dwFlags` [in]

Currently used only when a [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in the form of a **PRIVATEKEYBLOB** is imported into the CSP.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_EXPORTABLE** | The key being imported is eventually to be reexported. If this flag is not used, then calls to [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) with the key handle fail. |
| **CRYPT_OAEP** | This flag causes PKCS #1 version 2 formatting to be checked with RSA encryption and decryption when importing **SIMPLEBLOB**s. |
| **CRYPT_NO_SALT** | A [no-salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) gets allocated for a 40-bit [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). For more information, see [Salt Value Functionality](https://learn.microsoft.com/windows/desktop/SecCrypto/salt-value-functionality). |
| **CRYPT_USER_PROTECTED** | If this flag is set, the CSP notifies the user through a dialog box or some other method when certain actions are attempted using this key. The precise behavior is specified by the CSP or the CSP type used. If the provider context was acquired with CRYPT_SILENT set, using this flag causes a failure and the last error is set to NTE_SILENT_CONTEXT. |
| **CRYPT_IPSEC_HMAC_KEY** | Allows for the import of an RC2 key that is larger than 16 bytes. If this flag is not set, calls to the **CryptImportKey** function with RC2 keys that are greater than 16 bytes fail, and a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **NTE_BAD_DATA**. |

### `phKey` [out]

A pointer to a **HCRYPTKEY** value that receives the handle of the imported key. When you have finished using the key, release the handle by calling the [CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey) function.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Error codes prefaced by "NTE" are generated by the particular CSP being used. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_BUSY** | Some CSPs set this error if a private key is imported into a container while another thread or [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) is using this key. |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **NTE_BAD_ALGID** | The [simple key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to be imported is not encrypted with the expected [key exchange algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). |
| **NTE_BAD_DATA** | Either the algorithm that works with the public key to be imported is not supported by this CSP, or an attempt was made to import a session key that was encrypted with something other than one of your public keys. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter specified is not valid. |
| **NTE_BAD_TYPE** | The key BLOB type is not supported by this CSP and is possibly not valid. |
| **NTE_BAD_UID** | The *hProv* parameter does not contain a valid context handle. |
| **NTE_BAD_VER** | The version number of the key BLOB does not match the CSP version. This usually indicates that the CSP needs to be upgraded. |

## Remarks

When importing a [Hash-Based Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) (HMAC) key, the caller must identify the imported key as a **PLAINTEXTKEYBLOB** type and set the appropriate algorithm identifier in the **aiKeyAlg** field of the [PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc) BLOB header.

The **CryptImportKey** function can be used to import a plaintext key for symmetric algorithms; however, we recommend that, for ease of use, you use the [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) function instead. When you import a plaintext key, the structure of the key BLOB that is passed in the *pbData* parameter is a [PLAINTEXTKEYBLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj650836(v=vs.85)).

You can use the **PLAINTEXTKEYBLOB** type with any algorithm or type of key combination supported by the CSP in use.

For an example of importing a plaintext key, see [Example C Program: Importing a Plaintext Key](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program--importing-a-plaintext-key).

The following example shows how you can set the header fields.

```cpp
keyBlob.header.bType = PLAINTEXTKEYBLOB;
keyBlob.header.bVersion = CUR_BLOB_VERSION;
keyBlob.header.reserved = 0;
// CALG_AES_128 is used as an example. You would set this to the
// algorithm id that corresponds to the one used by the key.
keyBlob.header.aiKeyAlg = CALG_AES_128;
```

The length of the key is specified in keyBlob.keyLength, which is followed by the actual key data.

**Note** The HMAC algorithms do not have their own algorithm identifiers; use CALG_RC2 instead. **CRYPT_IPSEC_HMAC_KEY** allows the import of RC2 keys longer than 16 bytes.

For any of the [Data Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DES) key permutations that use **PLAINTEXTKEYBLOB**, only the full key size, including parity bit, can be imported.

The following key sizes are supported.

| Algorithm | Supported key size |
| --- | --- |
| CALG_DES | 64 bits |
| CALG_3DES_112 | 128 bits |
| CALG_3DES | 192 bits |

#### Examples

The following example shows how to import a key from a key BLOB. For a full example for this function, see
[Example C Program: Signing a Hash and Verifying the Hash Signature](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-signing-a-hash-and-verifying-the-hash-signature).
For additional code that uses this function, see
[Example C Program: Decrypting a File](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-decrypting-a-file).

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>

BOOL ImportKey(HCRYPTPROV hProv, LPBYTE pbKeyBlob, DWORD dwBlobLen)
{
    HCRYPTKEY hPubKey;

    //---------------------------------------------------------------
    // This code assumes that a cryptographic provider (hProv)
    // has been acquired and that a key BLOB (pbKeyBlob) that is
    // dwBlobLen bytes long has been acquired.

    //---------------------------------------------------------------
    // Get the public key of the user who created the digital
    // signature and import it into the CSP by using CryptImportKey.
    // The key to be imported is in the buffer pbKeyBlob that is
    // dwBlobLen bytes long. This function returns a handle to the
    // public key in hPubKey.

    if(CryptImportKey(
        hProv,
        pbKeyBlob,
        dwBlobLen,
        0,
        0,
        &hPubKey))
    {
        printf("The key has been imported.\n");
    }
    else
    {
        printf("Public key import failed.\n");
        return FALSE;
    }

    //---------------------------------------------------------------
    // Insert code that uses the imported public key here.
    //---------------------------------------------------------------

    //---------------------------------------------------------------
    // When you have finished using the key, you must release it.
    if(CryptDestroyKey(hPubKey))
    {
        printf("The public key has been released.");
    }
    else
    {
        printf("The public key has not been released.");
        return FALSE;
    }

    return TRUE;
}
```

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey)

[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey)

[Key Generation and Exchange Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)