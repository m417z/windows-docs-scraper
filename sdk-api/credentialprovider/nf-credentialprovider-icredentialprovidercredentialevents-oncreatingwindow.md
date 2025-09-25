# ICredentialProviderCredentialEvents::OnCreatingWindow

## Description

Called when the window is created. Enables credentials to retrieve the HWND of the parent window after [Advise](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-advise) is called.

## Parameters

### `phwndOwner` [out]

Type: **HWND***

A pointer to the handle of the parent window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The HWND that is returned in *phwndOwner* can be used as a parent to dialog boxes, such as message boxes. Any credential provider displaying a dialog must parent it to the HWND supplied by **OnCreatingWindow**. Credential providers that do not parent dialogs boxes properly will cause Credential UI and Logon UI to fail if a timeout occurs.

Credential UI and Logon UI can cancel the dialog box if they receive no input for two minutes. In the event of a timeout only if the pointer to the parent window is correctly assigned.

The Logon UI and Credential UI will automatically cancel dialogs that receive no input for two minutes. This is only possible if the pointer to the parent window is correctly assigned. Dialogs presented as calls to [IConnectableCredentialProviderCredential::Connect](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-iconnectablecredentialprovidercredential-connect) on the Pre-Logon-Access Provider (PLAP) screen will never be cancelled due to inactivity.