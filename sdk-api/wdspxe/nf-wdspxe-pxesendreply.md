# PxeSendReply function

## Description

Sends a packet to a client request.

## Parameters

### `hClientRequest` [in]

Handle to the client request received in the
[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest) callback.

### `pPacket` [in]

Pointer to packet allocated by the
[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

### `uPacketLen` [in]

Length of the packet pointed to by the *pPacket* parameter.

### `pAddress` [in]

Pointer to a [PXE_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_address) structure that contains the
destination address of the packet. If the *pAddress* parameter is
**NULL**, then the packet is sent to the source address of the client request.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PXE_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_address)

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)