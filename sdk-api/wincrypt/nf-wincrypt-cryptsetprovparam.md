# CryptSetProvParam function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptSetProvParam** function customizes the operations of a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This function is commonly used to set a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) on the [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) associated with a CSP to control access to the [private keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in that key container.

## Parameters

### `hProv` [in]

The handle of a CSP for which to set values. This handle must have already been created by using
the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function.

### `dwParam` [in]

Specifies the parameter to set. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PP_CLIENT_HWND**<br><br>1 (0x1) | Set the window handle that the provider uses as the parent of any dialog boxes it creates. *pbData* contains a pointer to an **HWND** that contains the parent window handle.<br><br>This parameter must be set before calling [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) because many CSPs will display a user interface when **CryptAcquireContext** is called. You can pass **NULL** for the *hProv* parameter to set this window handle for all cryptographic contexts subsequently acquired within this [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). |
| **PP_DELETEKEY**<br><br>24 (0x18) | Delete the ephemeral key associated with a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly), [encryption](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly), or verification context. This will free memory and clear registry settings associated with the key. |
| **PP_KEYEXCHANGE_ALG** | This constant is not used. |
| **PP_KEYEXCHANGE_PIN**<br><br>32 (0x20) | Specifies that the key exchange PIN is contained in *pbData*. The PIN is represented as a null-terminated ASCII string. |
| **PP_KEYEXCHANGE_KEYSIZE** | This constant is not used. |
| **PP_KEYSET_SEC_DESCR**<br><br>8 (0x8) | Sets the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) on the key storage container. The *pbData* parameter is the address of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the new security descriptor for the key storage container. |
| **PP_PIN_PROMPT_STRING**<br><br>44 (0x2C) | Sets an alternate prompt string to display to the user when the user's PIN is requested. The *pbData* parameter is a pointer to a null-terminated Unicode string. |
| **PP_ROOT_CERTSTORE**<br><br>46 (0x2E) | Sets the root certificate store for the smart card. The provider will copy the root certificates from this store onto the smart card.<br><br>The *pbData* parameter is an **HCERTSTORE** variable that contains the handle of the new certificate store. The provider will copy the certificates from the store during this call, so it is safe to close this store after this function is called.<br><br>**Windows XP and Windows Server 2003:** This parameter is not supported. |
| **PP_SIGNATURE_ALG** | This constant is not used. |
| **PP_SIGNATURE_PIN**<br><br>33 (0x21) | Specifies the signature PIN. The *pbData* parameter is a null-terminated ASCII string that represents the PIN. |
| **PP_SIGNATURE_KEYSIZE** | This constant is not used. |
| **PP_UI_PROMPT**<br><br>21 (0x15) | For a smart card provider, sets the search string that is displayed to the user as a prompt to insert the smart card. This string is passed as the **lpstrSearchDesc** member of the [OPENCARDNAME_EX](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencardname_exa) structure that is passed to the [SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda) function. This string is used for the lifetime of the calling process.<br><br>The *pbData* parameter is a pointer to a null-terminated Unicode string. |
| **PP_USE_HARDWARE_RNG**<br><br>38 (0x26) | Specifies that the CSP must exclusively use the hardware random number generator (RNG). When **PP_USE_HARDWARE_RNG** is set, random values are taken exclusively from the hardware RNG and no other sources are used. If a hardware RNG is supported by the CSP and it can be exclusively used, the function succeeds and returns **TRUE**; otherwise, the function fails and returns **FALSE**. The *pbData* parameter must be **NULL** and *dwFlags* must be zero when using this value.<br><br>None of the Microsoft CSPs currently support using a hardware RNG. |
| **PP_USER_CERTSTORE**<br><br>42 (0x2A) | Specifies the user certificate store for the smart card. This certificate store contains all of the user certificates that are stored on the smart card. The certificates in this store are encoded by using PKCS_7_ASN_ENCODING or X509_ASN_ENCODING encoding and should contain the **CERT_KEY_PROV_INFO_PROP_ID** property. <br><br>The *pbData* parameter is an **HCERTSTORE** variable that receives the handle of an in-memory certificate store. When this handle is no longer needed, the caller must close it by using the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function.<br><br>**Windows Server 2003 and Windows XP:** This parameter is not supported. |
| **PP_SECURE_KEYEXCHANGE_PIN**<br><br>47 (0x2F) | Specifies that an encrypted key exchange PIN is contained in *pbData*. The *pbData* parameter contains a [DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)). |
| **PP_SECURE_SIGNATURE_PIN**<br><br>48 (0x30) | Specifies that an encrypted signature PIN is contained in *pbData*. The *pbData* parameter contains a [DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)). |
| **PP_SMARTCARD_READER**<br><br>43 (0x2B) | Specifies the name of the smart card reader. The *pbData* parameter is the address of an ANSI character array that contains a null-terminated ANSI string that contains the name of the smart card reader. <br><br>**Windows Server 2003 and Windows XP:** This parameter is not supported. |
| **PP_SMARTCARD_GUID**<br><br>45 (0x2D) | Specifies the identifier of the smart card. The *pbData* parameter is the address of a **GUID** structure that contains the identifier of the smart card.<br><br>**Windows Server 2003 and Windows XP:** This parameter is not supported. |

### `pbData` [in]

A pointer to a data buffer that contains the value to be set as a provider parameter. The form of this data varies depending on the *dwParam* value. If *dwParam* contains **PP_USE_HARDWARE_RNG**, this parameter must be **NULL**.

### `dwFlags` [in]

If *dwParam* contains **PP_KEYSET_SEC_DESCR**, *dwFlags* contains the **SECURITY_INFORMATION** applicable bit flags, as defined in the Platform SDK. Key-container security is handled by using
[SetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilesecuritya) and
[GetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilesecuritya).

These bit flags can be combined by using a bitwise-**OR** operation. For more information, see
[CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam).

If *dwParam* is **PP_USE_HARDWARE_RNG** or **PP_DELETEKEY**, *dwFlags* must be set to zero.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by "NTE" are generated by the particular CSP being used. Error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_BUSY** | The CSP context is currently being used by another [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter is nonzero or the *pbData* buffer contains a value that is not valid. |
| **NTE_BAD_TYPE** | The *dwParam* parameter specifies an unknown parameter. |
| **NTE_BAD_UID** | The CSP context that was specified when the *hKey* key was created cannot be found. |
| **NTE_FAIL** | The function failed in some unexpected way. |

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam)

[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam)

[Service Provider Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)