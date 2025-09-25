# PxeDhcpv6AppendOption function

## Description

Appends a DHCPv6 option to the reply packet.

## Parameters

### `pReply` [in, out]

Pointer to a reply packet allocated with the
[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

### `cbReply` [in]

The total size in bytes allocated for the buffer that is pointed to by *pReply*.

### `pcbReplyUsed` [in, out]

On entry, this is the number of bytes of the buffer pointed to by *pReply* that are currently used. On success of the function, this is updated to the number of bytes used after appending the option.

### `wOptionType` [in]

DHCPv6 option to add to the packet.

### `cbOption` [in]

Length of the option value pointed to by the *pOption* parameter.

### `pOption` [in]

Address of the buffer that contains the DHCPv6 option value.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)