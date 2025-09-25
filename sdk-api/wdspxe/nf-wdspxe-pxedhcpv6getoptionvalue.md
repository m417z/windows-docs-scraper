# PxeDhcpv6GetOptionValue function

## Description

Retrieves an option value from a DHCPv6 packet.

## Parameters

### `pPacket` [in]

Pointer to a reply packet allocated with
the [PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

### `uPacketLen` [in]

Length of the packet pointed to by the *pReplyPacket* parameter.

### `uInstance` [in]

One-based index that specifies which instance of the *wOption* parameter to
retrieve.

### `wOption` [in]

Option whose value will be retrieved.

### `pwOptionLen` [out, optional]

Address of **WORD** which will receive the length of the option value.

### `ppOptionValue` [out, optional]

Address of **PVOID** which will receive the address of the option value inside the
packet.

## Return value

Common return values are listed in the following table. For all other failures, an appropriate Windows
error code is returned.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 (0x0) | The option was found and a pointer to the value was returned. |
| **ERROR_FILE_NOT_FOUND**<br><br>2 (0x2) | The option was not located. |
| **ERROR_INVALID_DATA**<br><br>13 (0xD) | The packet is not a valid DHCPv6 packet. This test is not as thorough as the tests used by the [PxeDhcpv6IsValid](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxedhcpv6isvalid) function; only the packet length and magic cookie are verified. |

## See also

[PxeDhcpv6AppendOption](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxedhcpv6appendoption)

[PxeDhcpv6GetVendorOptionValue](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxedhcpv6getvendoroptionvalue)

[PxeDhcpv6IsValid](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxedhcpv6isvalid)

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)