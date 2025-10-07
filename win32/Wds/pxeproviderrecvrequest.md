# PxeProviderRecvRequest callback function

Called when a request is received from a client. This function is registered by calling the [**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback) function with the *CallbackType* parameter set to **PXE\_CALLBACK\_RECV\_REQUEST**.

## Parameters

*hClientRequest* \[in\]

Handle to a request received from a client.

*pPacket* \[in\]

Pointer to the memory buffer that contains the received packet.

*uPacketLen* \[in\]

Length, in bytes, of the buffer pointed to by the *pPacket* parameter.

*pLocalAddress* \[in\]

Pointer to a [**PXE\_ADDRESS**](https://learn.microsoft.com/windows/win32/api/wdspxe/ns-wdspxe-pxe_address) structure that contains the local address on which the packet was received.

*pRemoteAddress* \[in\]

Pointer to a [**PXE\_ADDRESS**](https://learn.microsoft.com/windows/win32/api/wdspxe/ns-wdspxe-pxe_address) structure that contains the source address of the packet.

*pAction* \[out\]

Specifies the action that the system should take.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**PXE\_BA\_NBP**

1

| The provider replied to a client with a standard DHCP response packet that contains a path to the Network Boot Program. Returning this action means that the provider successfully completed the client request by calling the [**PxeSendReply**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxesendreply) function at least once.<br> |
|

**PXE\_BA\_CUSTOM**

2

| The provider replied to a client by using a custom response that does not conform to DHCP specifications. Returning this action means that the provider successfully completed the client request by calling the [**PxeSendReply**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxesendreply) function at least once.<br> |
|

**PXE\_BA\_IGNORE**

3

| The provider does not want to service the client request and the request should not be passed to the next provider. All resources associated with the client request are released and the client request is ignored. Providers can also use this value if they recognize the client but the request was malformed.<br> |
|

**PXE\_BA\_REJECTED**

4

| The provider does not want to service the client request. The system passes the request to the next provider in the list of registered providers. If this was the last provider in the list, then all resources associated with the client request are released and client request is ignored.<br> |

*pContext* \[in\]

Context value passed to the [**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback) function.

## Return value

If the provider successfully processed the client request, the callback should return **ERROR\_SUCCESS** and the **PXE\_BOOT\_ACTION** pointed to by the *pAction* parameter contains the appropriate boot action for this request. If the provider will process the client request asynchronously, the callback should return **ERROR\_IO\_PENDING** and call the [**PxeAsyncRecvDone**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeasyncrecvdone) function when the client request has been processed. In case of failure, an appropriate error code should be returned and the system will proceed as if the **PXE\_BA\_REJECTED** boot action was specified.

## Remarks

The type of packets seen by a provider can be changed with the [**PxeProviderSetAttribute**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeprovidersetattribute) function.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008, Windows Server 2003 with SP2 \[desktop apps only\]<br> |

## See also

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/win32/wds/windows-deployment-services-server-functions)

[**PxeRegisterCallback**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeregistercallback)

[**PxeSendReply**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxesendreply)

[**PxeProviderSetAttribute**](https://learn.microsoft.com/windows/desktop/api/WdsPxe/nf-wdspxe-pxeprovidersetattribute)

