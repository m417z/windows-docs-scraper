# ICredentialProviderCredential::GetStringValue

## Description

Enables retrieval of text from a credential with a text field.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the field.

### `ppsz` [out]

Type: **LPWSTR***

A pointer to the memory containing a null-terminated Unicode string to return to the Logon UI or Credential UI.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is optional.

The Logon UI and Credential UI us this method to obtain the *pszLabel* for a field. This information is necessary to get values for **CPFT_LARGE_TEXT**, **CPFT_SMALL_TEXT**, **CPFT_COMMAND_LINK**, **CPFT_EDIT_TEXT**, and **CPFT_PASSWORD_TEXT** fields.

### Credential Provider Best Practices

Credential providers handle extremely sensitive user secrets in order to complete logon and unlock requests. As a best practice, secret information such as passwords and PINs should be handled with the utmost care. Proper techniques for handling secret information within a credential provider are:

* Always securely discard secrets. To do this, call [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) before freeing the memory used to hold any secret.
* Securely discard secrets promptly after they are used.
* Securely discard secrets if they are not used for their intended purpose within an expected amount of time.