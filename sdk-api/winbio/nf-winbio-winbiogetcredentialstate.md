# WinBioGetCredentialState function

## Description

Retrieves a value that specifies whether credentials have been set for the specified user. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `Identity` [in]

A [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the SID of the user account for which the credential is being queried.

### `Type` [in]

A [WINBIO_CREDENTIAL_TYPE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-credential-type) value that specifies the credential type. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WINBIO_CREDENTIAL_PASSWORD** | The password-based credential is checked. |

### `CredentialState` [out]

Pointer to a [WINBIO_CREDENTIAL_STATE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-credential-state) enumeration value that specifies whether user credentials have been set. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WINBIO_CREDENTIAL_NOT_SET** | A credential has not been specified. |
| **WINBIO_CREDENTIAL_SET** | A credential has been specified. |

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The caller does not have permission to retrieve the credential state. |
| **WINBIO_E_UNKNOWN_ID** | The specified identity does not exist. |
| **WINBIO_E_CRED_PROV_DISABLED** | Current administrative policy prohibits use of the credential provider. |

## Remarks

The **WinBioGetCredentialState** is typically used to provide feedback about credential state in a user interface. For example, an enrollment application might query credential state before prompting a user for credentials.

Call the [WinBioSetCredential](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiosetcredential) function to associate credentials with a user.

Users who do not have elevated privileges can retrieve information about only their own credentials. Elevated users can retrieve information for any credential.

#### Examples

The following function calls **WinBioGetCredentialState** to retrieve
the credential state for a user. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT GetCredentialState()
{
    // Declare variables.
    HRESULT hr = S_OK;
    WINBIO_IDENTITY identity;
    WINBIO_CREDENTIAL_STATE credState;

    // Find the identity of the user.
    wprintf_s(L"\n Finding user identity.\n");
    hr = GetCurrentUserIdentity( &identity );
    if (FAILED(hr))
    {
        wprintf_s(L"\n User identity not found. hr = 0x%x\n", hr);
        return hr;
    }

    // Find the credential state for the user.
    wprintf_s(L"\n Calling WinBioGetCredentialState.\n");
    hr = WinBioGetCredentialState(
             identity,                      // User GUID or SID
             WINBIO_CREDENTIAL_PASSWORD,    // Credential type
             &credState                     // [out] Credential state
             );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioGetCredentialState failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Print the credential state.
    switch(credState)
    {
        case WINBIO_CREDENTIAL_SET:
            wprintf_s(L"\n Credential set.\n");
            break;
        case WINBIO_CREDENTIAL_NOT_SET:
            wprintf_s(L"\n Credential NOT set.\n");
            break;
        default:
            wprintf_s(L"\n ERROR: Invalid credential state.\n");
            hr = E_FAIL;
    }

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

[WinBioSetCredential](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiosetcredential)