# ICredentialProviderCredential::SetSelected

## Description

Called when a credential is selected. Enables the implementer to set logon characteristics.

## Parameters

### `pbAutoLogon` [out]

Type: **BOOL***

When this method returns, contains **TRUE** if selection of the credential indicates that it should attempt to logon immediately and automatically, otherwise **FALSE**. For example, a credential provider that enumerates an account without a password may want to return this as true.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Returning any value other than **S_OK** causes the Logon UI and Credential UI to behave as if no selection occurred.

In Windows 10, if a credential provider wants to automatically log the user on in a situation Windows does not think is appropriate, the system will display a sign in button as a speed bump. One example of this is when a user with an empty password locks the computer or signs out. In that scenario, Windows does not directly log the user back in.