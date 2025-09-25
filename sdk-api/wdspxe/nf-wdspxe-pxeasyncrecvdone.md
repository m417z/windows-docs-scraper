# PxeAsyncRecvDone function

## Description

Passes the results of processing the client request asynchronously. This function should be called
only if the [PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest) function
returns **ERROR_IO_PENDING**.

## Parameters

### `hClientRequest` [in]

Handle to the request received from the client.

### `Action` [in]

Specifies the action that the system should take for this client request. The following table lists the
possible values.

| Value | Meaning |
| --- | --- |
| **PXE_BA_NBP**<br><br>1 | The provider replied to the client with a standard DHCP response packet that contains the path to the Network Boot Program. Returning this action means that the provider successfully completed the client request by calling the [PxeSendReply](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxesendreply) function at least once. |
| **PXE_BA_CUSTOM**<br><br>2 | The provider replied to the client by using a custom response that does not conform to DHCP specifications. Returning this action means that the provider successfully completed the client request by calling the [PxeSendReply](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxesendreply) function at least once. |
| **PXE_BA_IGNORE**<br><br>3 | The provider does not want to service the client request and the request should not be passed to the next provider. All resources associated with the client request are released and the client request is ignored. Providers can also use this value if they recognize the client but the request was malformed. |
| **PXE_BA_REJECTED**<br><br>4 | The provider does not want to service the client request. The system passes the request to the next provider in the list of registered providers. If this was the last provider in the list, then all resources associated with the client request are released and client request is ignored. |

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest)

[PxeSendReply](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxesendreply)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)