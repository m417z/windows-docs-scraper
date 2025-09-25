# IConnectableCredentialProviderCredential::Connect

## Description

Connects an [IConnectableCredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-iconnectablecredentialprovidercredential) object. This method is called after the user clicks the **Submit** button within the Pre-Logon-Access Provider screen and before [ICredentialProviderCredential::GetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-getserialization) is called.

## Parameters

### `pqcws` [in]

Type: **[IQueryContinueWithStatus](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-iquerycontinuewithstatus)***

A pointer to an [IQueryContinueWithStatus](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-iquerycontinuewithstatus) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 When Logon UI calls this method, it passes a pointer to an [IQueryContinueWithStatus](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-iquerycontinuewithstatus) instance. This object is used to query if the credential provider should continue attempt to connect to the network and to display status messages to the user while attempting to connect. Robust credential providers should periodically call [QueryContinue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iquerycontinue-querycontinue) during attempts to connect to a network to be able to respond to user input.

After a successful call to **Connect**, the Logon UI displays a **Disconnect** button to the user. If the user clicks **Disconnect**, the Logon UI calls [Disconnect](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-iconnectablecredentialprovidercredential-disconnect) on every credential provider that implements [IConnectableCredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-iconnectablecredentialprovidercredential).