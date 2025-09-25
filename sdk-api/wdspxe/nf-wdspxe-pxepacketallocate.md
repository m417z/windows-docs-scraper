# PxePacketAllocate function

## Description

Allocates a packet to be sent with the
[PxeSendReply](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxesendreply) function.

## Parameters

### `hProvider` [in]

**HANDLE** passed to the
[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) function.

### `hClientRequest` [in]

Handle to the client request received in the
[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest) callback.

### `uSize` [in]

Size of the buffer to be allocated.

## Return value

Address of allocated buffer, or **NULL** if the allocation failed. For extended error
information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[PxePacketFree](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketfree)

[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize)

[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest)

[PxeSendReply](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxesendreply)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)