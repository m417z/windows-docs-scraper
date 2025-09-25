# PFXVerifyPassword function

## Description

The **PFXVerifyPassword** function attempts to decode the outer layer of a BLOB as a Personal Information Exchange (PFX) packet and to decrypt it with the given password. No data from the BLOB is imported.

The PFX format is also known as the Public-Key Cryptography Standards #12 (PKCS #12) format.

## Parameters

### `pPFX` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that the function will attempt to decode as a PFX packet.

### `szPassword` [in]

String password to be checked. For this function to succeed, this password must be exactly the same as the password used to encrypt the packet.

If you set this value to an empty string or **NULL**, this function typically attempts to decrypt the password embedded in the PFX BLOB by using the empty string or **NULL**.

However, beginning with Windows 8 and Windows Server 2012, if a **NULL** or empty password was specified when the PFX BLOB was created and the application also specified that the password should be protected to an Active Directory (AD) principal, the Cryptography API (CAPI) randomly generates a password, encrypts it to the AD principal and embeds it in the PFX BLOB. The **PFXVerifyPassword** function will then try to use the specified AD principal (current user, computer, or AD group member) to decrypt the password. For more information about protecting PFX to an AD principal, see the *pvPara* parameter and the **PKCS12_PROTECT_TO_DOMAIN_SIDS** flag of the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function.

When you have finished using the password, clear the password from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `dwFlags` [in]

Reserved for future use.

## Return value

The function return **TRUE** if the password appears correct; otherwise, it returns **FALSE**.