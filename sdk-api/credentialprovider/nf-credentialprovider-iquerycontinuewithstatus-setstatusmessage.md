# IQueryContinueWithStatus::SetStatusMessage

## Description

Enables the credential provider to set status messages as it attempts to complete [IConnectableCredentialProviderCredential::Connect](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-iconnectablecredentialprovidercredential-connect).

## Parameters

### `psz` [in]

Type: **LPCWSTR**

A pointer to the status message.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Logon UI will display the status message during [Connect](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-iconnectablecredentialprovidercredential-connect). This is especially useful during lengthy attempt to connect to inform the user of the status and continued attempts.