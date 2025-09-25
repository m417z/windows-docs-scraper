# PxeDhcpAppendOption function

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

### `bOption` [in]

DHCP option to add to the packet.

### `bOptionLen` [in]

Length of the option value pointed to by the *pValue* parameter. This parameter is
ignored if the *bOption* parameter is End Option (0xFF) or Pad Option (0x00).

### `pValue` [in]

Address of the buffer that contains the DHCP option value. This parameter is ignored if the
*bOption* parameter is End Option (0xFF) or Pad Option (0x00).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)