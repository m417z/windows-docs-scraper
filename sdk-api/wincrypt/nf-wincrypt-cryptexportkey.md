# CryptExportKey function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptExportKey** function exports a [cryptographic key](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) or a key pair from a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) in a secure manner.

A handle to the key to be exported is passed to the function, and the function returns
a [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). This key BLOB can be sent over a nonsecure transport or stored in a nonsecure storage location. This function can export an [Schannel](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) session key, regular [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), or [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The key BLOB to export is useless until the intended recipient uses the
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) function on it to import the key or key pair into a recipient's CSP.

## Parameters

### `hKey` [in]

A handle to the key to be exported.

### `hExpKey` [in]

A handle to a cryptographic key of the destination user. The key data within the exported [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) is encrypted using this key. This ensures that only the destination user is able to make use of the key BLOB. Both *hExpKey* and *hKey* must come from the same CSP.

Most often, this is the [key exchange public key](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) of the destination user. However, certain protocols in some CSPs require that a session key belonging to the destination user be used for this purpose.

If the key BLOB type specified by *dwBlobType* is **PUBLICKEYBLOB**, this parameter is unused and must be set to zero.

If the key BLOB type specified by *dwBlobType* is **PRIVATEKEYBLOB**, this is typically a handle to a session key that is to be used to encrypt the key BLOB. Some CSPs allow this parameter to be zero, in which case the application must encrypt the [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) manually so as to protect it.

To determine how Microsoft [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) respond to this parameter, see the [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) sections of
[Microsoft Cryptographic Service Providers](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-cryptographic-service-providers).

**Note** Some CSPs may modify this parameter as a result of the operation. Applications that subsequently use this key for other purposes should call the [CryptDuplicateKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptduplicatekey) function to create a duplicate key handle. When the application has finished using the handle, release it by calling the [CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey) function.

### `dwBlobType` [in]

Specifies the type of [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) to be exported in *pbData*. This must be one of the following constants as discussed in
[Cryptographic Key Storage and Exchange](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-key-storage-and-exchange).

| Value | Meaning |
| --- | --- |
| **OPAQUEKEYBLOB** | Used to store session keys in an Schannel CSP or any other vendor-specific format. OPAQUEKEYBLOBs are nontransferable and must be used within the CSP that generated the BLOB. |
| **PRIVATEKEYBLOB** | Used to transport [public/private key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). |
| **PUBLICKEYBLOB** | Used to transport public keys. |
| **SIMPLEBLOB** | Used to transport session keys. |
| **PLAINTEXTKEYBLOB** | A [PLAINTEXTKEYBLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj650836(v=vs.85)) used to export any key supported by the CSP in use. |
| **SYMMETRICWRAPKEYBLOB** | Used to export and import a [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) wrapped with another symmetric key. The actual wrapped key is in the format specified in the IETF [RFC 3217](https://www.ietf.org/rfc/rfc3217.txt) standard. |

### `dwFlags` [in]

Specifies additional options for the function. This parameter can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_BLOB_VER3**<br><br>0x00000080 | This flag causes this function to export version 3 of a BLOB type. |
| **CRYPT_DESTROYKEY**<br><br>0x00000004 | This flag destroys the original key in the OPAQUEKEYBLOB. This flag is available in Schannel CSPs only. |
| **CRYPT_OAEP**<br><br>0x00000040 | This flag causes PKCS #1 version 2 formatting to be created with the RSA encryption and decryption when exporting SIMPLEBLOBs. |
| **CRYPT_SSL2_FALLBACK**<br><br>0x00000002 | The first eight bytes of the RSA encryption block [padding](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) must be set to 0x03 rather than to random data. This prevents version rollback attacks and is discussed in the SSL3 specification. This flag is available for Schannel CSPs only. |
| **CRYPT_Y_ONLY**<br><br>0x00000001 | This flag is not used. |

### `pbData` [out]

A pointer to a buffer that receives the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) data. The format of this BLOB varies depending on the BLOB type requested in the *dwBlobType* parameter. For the format for PRIVATEKEYBLOBs, PUBLICKEYBLOBs, and SIMPLEBLOBs, see
[Base Provider Key BLOBs](https://learn.microsoft.com/windows/desktop/SecCrypto/base-provider-key-blobs).

If this parameter is **NULL**, the required buffer size is placed in the value pointed to by the *pdwDataLen* parameter. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pdwDataLen` [in, out]

A pointer to a **DWORD** value that, on entry, contains the size, in bytes, of the buffer pointed to by the *pbData* parameter. When the function returns, this value contains the number of bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

To retrieve the required size of the *pbData* buffer, pass **NULL** for *pbData*. The required buffer size will be placed in the value pointed to by this parameter.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by "NTE" are generated by the particular CSP being used. The following table shows some of the possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbData* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pdwDataLen*. |
| **NTE_BAD_DATA** | Either the algorithm that works with the public key to be exported is not supported by this CSP, or an attempt was made to export a session key that was encrypted with something other than one of your public keys. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter is nonzero. |
| **NTE_BAD_KEY** | One or both of the keys specified by *hKey* and *hExpKey* are not valid. |
| **NTE_BAD_KEY_STATE** | You do not have permission to export the key. That is, when the *hKey* key was created, the CRYPT_EXPORTABLE flag was not specified. |
| **NTE_BAD_PUBLIC_KEY** | The [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) type specified by *dwBlobType* is PUBLICKEYBLOB, but *hExpKey* does not contain a public key handle. |
| **NTE_BAD_TYPE** | The *dwBlobType* parameter specifies an unknown BLOB type. |
| **NTE_BAD_UID** | The CSP context that was specified when the *hKey* key was created cannot be found. |
| **NTE_NO_KEY** | A session key is being exported, and the *hExpKey* parameter does not specify a public key. |

## Remarks

For any of the DES key permutations that use a PLAINTEXTKEYBLOB, only the full key size, including parity bit, may be exported. The following key sizes are supported.

| Algorithm | Supported key size |
| --- | --- |
| CALG_DES | 64 bits |
| CALG_3DES_112 | 128 bits |
| CALG_3DES | 192 bits |

#### Examples

The following example shows how to export a cryptographic key or a key pair in a more secure manner. This example assumes that a cryptographic context has been acquired and that a public key is available for export. For an example that includes the complete context for using this function, see
[Example C Program: Signing a Hash and Verifying the Hash Signature](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-signing-a-hash-and-verifying-the-hash-signature). For another example that uses this function, see [Example C Program: Exporting a Session Key](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-exporting-a-session-key).

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>

BOOL GetExportedKey(
    HCRYPTKEY hKey,
    DWORD dwBlobType,
    LPBYTE *ppbKeyBlob,
    LPDWORD pdwBlobLen)
{
    DWORD dwBlobLength;
    *ppbKeyBlob = NULL;
    *pdwBlobLen = 0;

    // Export the public key. Here the public key is exported to a
    // PUBLICKEYBLOB. This BLOB can be written to a file and
    // sent to another user.

    if(CryptExportKey(
        hKey,
        NULL,
        dwBlobType,
        0,
        NULL,
        &dwBlobLength))
    {
        printf("Size of the BLOB for the public key determined. \n");
    }
    else
    {
        printf("Error computing BLOB length.\n");
        return FALSE;
    }

    // Allocate memory for the pbKeyBlob.
    if(*ppbKeyBlob = (LPBYTE)malloc(dwBlobLength))
    {
        printf("Memory has been allocated for the BLOB. \n");
    }
    else
    {
        printf("Out of memory. \n");
        return FALSE;
    }

    // Do the actual exporting into the key BLOB.
    if(CryptExportKey(
        hKey,
        NULL,
        dwBlobType,
        0,
        *ppbKeyBlob,
        &dwBlobLength))
    {
        printf("Contents have been written to the BLOB. \n");
        *pdwBlobLen = dwBlobLength;
    }
    else
    {
        printf("Error exporting key.\n");
        free(*ppbKeyBlob);
        *ppbKeyBlob = NULL;

        return FALSE;
    }

    return TRUE;
}
```

## See also

[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey)

[Key Generation and Exchange Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)