# IPX_NETNUM_DATA structure

## Description

The
**IPX_NETNUM_DATA** structure provides information about a specified IPX network number. Used in conjunction with
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function calls that specify IPX_GETNETINFO in the *optname* parameter.

## Members

### `netnum`

IPX network number for which information is being requested.

### `hopcount`

Number of hops to the IPX network being queried, in machine order.

### `netdelay`

Network delay tick count required to reach the IPX network, in machine order.

### `cardnum`

Adapter number used to reach the IPX network. The adapter number is zero based, such that if eight adapters are on a given computer, they are numbered 0-7.

### `router`

Media Access Control (MAC) address of the next-hop router in the path between the computer and the IPX network. This value is zero if the computer is directly attached to the IPX network.

## Remarks

If information about the IPX network is in the computer's IPX cache, the call will return immediately. If not, RIP requests are used to resolve the information.

## See also

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)