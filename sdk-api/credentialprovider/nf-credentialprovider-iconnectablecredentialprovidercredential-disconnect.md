# IConnectableCredentialProviderCredential::Disconnect

## Description

Disconnects an [IConnectableCredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-iconnectablecredentialprovidercredential) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After a successful call to [Connect](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-iconnectablecredentialprovidercredential-connect), the Logon UI displays a **Disconnect** button to the user. If the user clicks **Disconnect**, the Logon UI calls **Disconnect** on every credential provider that implements [IConnectableCredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-iconnectablecredentialprovidercredential).