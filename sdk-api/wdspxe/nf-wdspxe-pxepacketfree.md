# PxePacketFree function

## Description

Frees a packet allocated by the
[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

## Parameters

### `hProvider` [in]

**HANDLE** passed to the
[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) function.

### `hClientRequest` [in]

Handle to the client request received in the
[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest) callback.

### `pPacket` [in]

Pointer to packet allocated by the
[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize)

[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)