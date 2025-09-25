# IWTSProtocolManager::CreateListener

## Description

[**IWTSProtocolManager::CreateListener** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolManager::CreateListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-createlistener).]

Requests the creation of an [IWTSProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistener) object that listens for incoming client connection requests. The protocol provider must add a reference to the **IWTSProtocolListener** object before returning. The Remote Desktop Services service releases the reference when the service stops or the listener object is deleted.

## Parameters

### `wszListenerName` [in]

A pointer to a string that contains the registry GUID that specifies the listener to create.

### `pProtocolListener` [out]

The address of a pointer to the [IWTSProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistener) object.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **CreateListener** method is the first call the Remote Desktop Services service makes into your protocol provider. The service looks in the registry under the following key to find the GUID of the listener to create:

```
HKEY_LOCAL_MACHINE
   System
      CurrentControlSet
         Control
            Terminal Server
               WinStations
                  ListenerName
                     LoadableProtocol_Object
```

## See also

[IWTSProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolmanager)