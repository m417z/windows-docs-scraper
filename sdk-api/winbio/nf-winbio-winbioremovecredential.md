# WinBioRemoveCredential function

## Description

Deletes a biometric logon credential for a specified user. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `Identity` [in]

A [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the SID of the user account for which the logon credential will be removed.

### `Type` [in]

A [WINBIO_CREDENTIAL_TYPE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-credential-type) value that specifies the credential type. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WINBIO_CREDENTIAL_PASSWORD** | The password-based credential will be deleted. |
| **WINBIO_CREDENTIAL_ALL** | All logon credentials for the user will be deleted. |

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_ACCESSDENIED**** | The caller does not have permission to delete the credential. |
| ****WINBIO_E_CRED_PROV_NO_CREDENTIAL**** | The specified identity does not exist or does not have any related records in the credential store. |

## Remarks

Users who do not have elevated privileges can delete only their own credentials. Elevated users can remove credentials for any user account. Deleting a credential does not affect any biometric enrollments for that user. Deleting a biometric credential does not prevent the user from logging on by using a password. Only medium and higher integrity processes can delete credentials. If a lower integrity process attempts to delete credentials, the function returns E_ACCESSDENIED.

#### Examples

The following function shows how to call **WinBioRemoveCredential** to remove credentials for a specific user. The helper function GetCurrentUserIdentity is also included. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT RemoveCredential()
{
    HRESULT hr = S_OK;
    WINBIO_IDENTITY identity;

    // Find the identity of the user.
    wprintf_s(L"\n Finding user identity.\n");
    hr = GetCurrentUserIdentity( &identity );
    if (FAILED(hr))
    {
        wprintf(L"\n User identity not found. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Remove the user credentials.
    hr = WinBioRemoveCredential(identity, WINBIO_CREDENTIAL_PASSWORD);
    if (FAILED(hr))
    {
        wprintf(L"\n WinBioRemoveCredential failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    wprintf_s(L"\n User credentials successfully removed.\n");

e_Exit:

    wprintf_s(L"\n Press any key to exit...");
    _getch();

    return hr;
}

//------------------------------------------------------------------------
// The following function retrieves the identity of the current user.
// This is a helper function and is not part of the Windows Biometric
// Framework API.
//
HRESULT GetCurrentUserIdentity(__inout PWINBIO_IDENTITY Identity)
{
    // Declare variables.
    HRESULT hr = S_OK;
    HANDLE tokenHandle = NULL;
    DWORD bytesReturned = 0;
    struct{
        TOKEN_USER tokenUser;
        BYTE buffer[SECURITY_MAX_SID_SIZE];
    } tokenInfoBuffer;

    // Zero the input identity and specify the type.
    ZeroMemory( Identity, sizeof(WINBIO_IDENTITY));
    Identity->Type = WINBIO_ID_TYPE_NULL;

    // Open the access token associated with the
    // current process
    if (!OpenProcessToken(
            GetCurrentProcess(),            // Process handle
            TOKEN_READ,                     // Read access only
            &tokenHandle))                  // Access token handle
    {
        DWORD win32Status = GetLastError();
        wprintf_s(L"Cannot open token handle: %d\n", win32Status);
        hr = HRESULT_FROM_WIN32(win32Status);
        goto e_Exit;
    }

    // Zero the tokenInfoBuffer structure.
    ZeroMemory(&tokenInfoBuffer, sizeof(tokenInfoBuffer));

    // Retrieve information about the access token. In this case,
    // retrieve a SID.
    if (!GetTokenInformation(
            tokenHandle,                    // Access token handle
            TokenUser,                      // User for the token
            &tokenInfoBuffer.tokenUser,     // Buffer to fill
            sizeof(tokenInfoBuffer),        // Size of the buffer
            &bytesReturned))                // Size needed
    {
        DWORD win32Status = GetLastError();
        wprintf_s(L"Cannot query token information: %d\n", win32Status);
        hr = HRESULT_FROM_WIN32(win32Status);
        goto e_Exit;
    }

    // Copy the SID from the tokenInfoBuffer structure to the
    // WINBIO_IDENTITY structure.
    CopySid(
        SECURITY_MAX_SID_SIZE,
        Identity->Value.AccountSid.Data,
        tokenInfoBuffer.tokenUser.User.Sid
        );

    // Specify the size of the SID and assign WINBIO_ID_TYPE_SID
    // to the type member of the WINBIO_IDENTITY structure.
    Identity->Value.AccountSid.Size = GetLengthSid(tokenInfoBuffer.tokenUser.User.Sid);
    Identity->Type = WINBIO_ID_TYPE_SID;

e_Exit:

    if (tokenHandle != NULL)
    {
        CloseHandle(tokenHandle);
    }

    return hr;
}

```

## See also

[WinBioRemoveAllCredentials](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioremoveallcredentials)

[WinBioRemoveAllDomainCredentials](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioremovealldomaincredentials)

[WinBioSetCredential](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiosetcredential)