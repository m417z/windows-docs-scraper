# PxeDhcpAppendOptionRaw function

## Description

Appends a DHCP option to the reply packet.

## Parameters

### `pReplyPacket` [in, out]

Pointer to a reply packet allocated with the
[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

### `uMaxReplyPacketLen` [in]

Allocated length of the packet pointed to by the *pReplyPacket* parameter.

### `puReplyPacketLen` [in, out]

Address of a **ULONG** that on successful completion will receive the length of
the packet pointed to by the *pReplyPacket* parameter.

### `uBufferLen` [in]

Length of the option value pointed to by the *pBuffer* parameter.

### `pBuffer` [in]

Address of the buffer that contains the DHCP option value.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)