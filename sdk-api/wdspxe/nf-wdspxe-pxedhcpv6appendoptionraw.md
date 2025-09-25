# PxeDhcpv6AppendOptionRaw function

## Description

Appends a DHCPv6 option to the reply packet.

## Parameters

### `pReply` [in, out]

Pointer to a reply packet allocated with the
[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

### `cbReply` [in]

Allocated length of the packet pointed to by the *pReply* parameter.

### `pcbReplyUsed` [in, out]

On entry, this is the number of bytes of the buffer pointed to by *pReply* that are currently used. On success of the function, this is updated to the number of bytes used after appending the option.

### `cbBuffer` [in]

Length of the option value pointed to by the *pBuffer* parameter.

### `pBuffer` [in]

Address of the buffer that contains the DHCPv6 option value. The buffer must contain the encoded option code and option size.

For more information about encoding the option code and option size, developers should refer to the Dynamic Host Configuration Protocol for IPv6 [RFC 3315](https://www.ietf.org/rfc/rfc3315.txt) maintained by The Internet Engineering Task Force (IETF).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)