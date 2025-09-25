# ICredentialProviderCredential::SetStringValue

## Description

Enables a Logon UI or Credential UI to update the text for a **CPFT_EDIT_TEXT** fields as the user types in them.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the field that needs to be updated.

### `psz` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the new text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is optional.

### Credential Provider Best Practices

Credential providers handle extremely sensitive user secrets in order to complete logon and unlock requests. As a best practice, secret information such as passwords and PINs should be handled with the utmost care. Proper techniques for handling secret information within a credential provider are:

* Always securely discard secrets. To do this, call [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) before freeing the memory used to hold any secret.
* Securely discard secrets promptly after they are used.
* Securely discard secrets if they are not used for their intended purpose within an expected amount of time.