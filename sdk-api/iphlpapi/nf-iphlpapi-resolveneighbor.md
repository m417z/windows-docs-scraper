# ResolveNeighbor function

## Description

[**ResolveNeighbor** is no longer available for use as of Windows Vista. Instead, use [ResolveIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-resolveipnetentry2).]

The
**ResolveNeighbor** function resolves the physical address for a neighbor IP address entry on the local computer.

## Parameters

### `NetworkAddress` [in]

A pointer to a [SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that contains the neighbor IP address entry and address family.

### `PhysicalAddress` [out]

A pointer to a byte array buffer that will receive the physical address that corresponds to the IP address specified by the *NetworkAddress* parameter if the function is successful. The length of the byte array is passed in the *PhysicalAddressLength* parameter.

### `PhysicalAddressLength` [in, out]

On input, this parameter specifies the maximum length, in bytes, of the buffer passed in the *PhysicalAddress* parameter to receive the physical address. If the function is successful, this parameter will receive the length of the physical address returned in the buffer pointed to by the *PhysicalAddress* parameter. If **ERROR_BUFFER_OVERFLOW** is returned, this parameter contains the number of bytes
required to hold the physical address.

## Return value

The **ResolveNeighbor** function always fails and returns the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_SUPPORTED** | The request is not supported. |

## See also

[ResolveIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-resolveipnetentry2)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)