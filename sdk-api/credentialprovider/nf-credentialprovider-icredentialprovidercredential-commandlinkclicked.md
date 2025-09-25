# ICredentialProviderCredential::CommandLinkClicked

## Description

Enables the Logon UI and Credential UI to indicate that a link was clicked.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the field clicked on.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method contains the logic that the credential provider uses to respond to the click.