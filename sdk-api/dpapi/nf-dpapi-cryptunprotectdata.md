# CryptUnprotectData function

## Description

The **CryptUnprotectData** function decrypts and does an [integrity](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) check of the data in a
[DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. Usually, the only user who can decrypt the data is a user with the same logon [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) as the user who encrypted the data. In addition, the encryption and decryption must be done on the same computer. For information about exceptions, see the Remarks section of
[CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata).

## Parameters

### `pDataIn` [in]

A pointer to a
[DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that holds the encrypted data. The **DATA_BLOB** structure's **cbData** member holds the length of the **pbData** member's byte string that contains the text to be encrypted.

### `ppszDataDescr` [out, optional]

A pointer to a string-readable description of the encrypted data included with the encrypted data. This parameter can be set to **NULL**. When you have finished using *ppszDataDescr*, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

### `pOptionalEntropy` [in, optional]

A pointer to a [DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a password or other additional entropy used when the data was encrypted. This parameter can be set to **NULL**; however, if an optional entropy **DATA_BLOB** structure was used in the encryption phase, that same **DATA_BLOB** structure must be used for the decryption phase. For information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `pvReserved`

This parameter is reserved for future use and must be set to **NULL**.

### `pPromptStruct` [in, optional]

A pointer to a
[CRYPTPROTECT_PROMPTSTRUCT](https://learn.microsoft.com/windows/desktop/api/dpapi/ns-dpapi-cryptprotect_promptstruct) structure that provides information about where and when prompts are to be displayed and what the content of those prompts should be. This parameter can be set to **NULL**.

### `dwFlags` [in]

A **DWORD** value that specifies options for this function. This parameter can be zero, in which case no option is set, or the following flag.

| Value | Meaning |
| --- | --- |
| **CRYPTPROTECT_UI_FORBIDDEN** | This flag is used for remote situations where the user interface (UI) is not an option. When this flag is set and UI is specified for either the protect or unprotect operation, the operation fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the ERROR_PASSWORD_RESTRICTION code. |
| **CRYPTPROTECT_VERIFY_PROTECTION** | This flag verifies the protection of a protected [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). If the default protection level configured of the host is higher than the current protection level for the BLOB, the function returns **CRYPT_I_NEW_PROTECTION_REQUIRED** to advise the caller to again protect the plaintext contained in the BLOB. |

### `pDataOut` [out]

A pointer to a [DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure where the function stores the decrypted data. When you have finished using the **DATA_BLOB** structure, free its **pbData** member by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.

## Remarks

The
[CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata) function creates a session key when the data is encrypted. That key is derived again and used to decrypt the data [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

The [Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MAC) [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) added to the encrypted data can be used to determine whether the encrypted data was altered in any way. Any tampering results in the return of the ERROR_INVALID_DATA code.

When you have finished using the [DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure, free its **pbData** member by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function. Any *ppszDataDescr* that is not **NULL** must also be freed by using **LocalFree**.

 When you have finished using sensitive information, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function.

#### Examples

The following example shows decrypting encrypted data in a
[DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. This function does the decryption by using a session key that the function creates by using the user's logon credentials. For another example that uses this function, see
[Example C Program: Using CryptProtectData](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-using-cryptprotectdata).

```cpp
// Decrypt data from DATA_BLOB DataOut to DATA_BLOB DataVerify.

//--------------------------------------------------------------------
// Declare and initialize variables.

DATA_BLOB DataOut;
DATA_BLOB DataVerify;
LPWSTR pDescrOut =  NULL;
//--------------------------------------------------------------------
// The buffer DataOut would be created using the CryptProtectData
// function. If may have been read in from a file.

//--------------------------------------------------------------------
//   Begin unprotect phase.

if (CryptUnprotectData(
        &DataOut,
        &pDescrOut,
        NULL,                 // Optional entropy
        NULL,                 // Reserved
        NULL,                 // Here, the optional
                              // prompt structure is not
                              // used.
        0,
        &DataVerify))
{
     printf("The decrypted data is: %s\n", DataVerify.pbData);
     printf("The description of the data was: %s\n",pDescrOut);
     LocalFree(DataVerify.pbData);
     LocalFree(pDescrOut);
}
else
{
    printf("Decryption error!");
}

```

## See also

[CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata)

[CryptUnprotectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectmemory)

[Data Encryption and Decryption Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[Microsoft Base Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider)