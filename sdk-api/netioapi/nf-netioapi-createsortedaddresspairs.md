# CreateSortedAddressPairs function

## Description

The
**CreateSortedAddressPairs** function takes a supplied list of potential IP destination addresses, pairs the destination addresses with the host machine's local IP addresses, and sorts the pairs according to which address
pair is best suited for communication between the two peers.

## Parameters

### `SourceAddressList` [in, optional]

Must be **NULL**. Reserved for future use.

### `SourceAddressCount` [in]

Must be 0. Reserved for future use.

### `DestinationAddressList` [in]

A pointer to an array of [SOCKADDR_IN6](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structures that contain a list of potential IPv6 destination addresses.
Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node.

### `DestinationAddressCount` [in]

The number of destination addresses pointed to by the *DestinationAddressList* parameter.

### `AddressSortOptions` [in]

Reserved for future use.

### `SortedAddressPairList` [out]

A pointer to store an array of [SOCKADDR_IN6_PAIR](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_in6_pair) structures that contain a list of pairs of IPv6 addresses
sorted in the preferred order of communication, if the function call is successful.

### `SortedAddressPairCount` [out]

A pointer to store the number of address pairs pointed to by the *SortedAddressPairList* parameter, if the function call is successful.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *DestinationAddressList*, *SortedAddressPairList*, or *SortedAddressPairCount* parameters **NULL**, or the *DestinationAddressCount* was greater than 500. This error is also returned if the *SourceAddressList* is not **NULL** or the *SourceAddressPairCount* parameter is not zero. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv6 stack is on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **CreateSortedAddressPairs** function is defined on Windows Vista and later.

The **CreateSortedAddressPairs** function takes a list of source and destination IPv6 addresses, and returns a list of
pairs of addresses in sorted order. The list is sorted by which address
pair is best suited for communication between the source and destination address.

The list of source addresses pointed to by the *SourceAddressList* is currently reserved for future and must be a **NULL** pointer. The *SourceAddressCount* is currently reserved for future and must be zero. The **CreateSortedAddressPairs** function currently uses all of the host machine's local addresses for the source address list.

The list of destination addresses is pointed to by the *DestinationAddressList* parameter. The list of destination addresses is an array of [SOCKADDR_IN6](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structures. Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. For more information on the IPv4-mapped IPv6 address format, see [Dual-Stack Sockets](https://learn.microsoft.com/windows/desktop/WinSock/dual-stack-sockets). The *DestinationAddressCount* parameter contains the number of destination addresses pointed to by the *DestinationAddressList* parameter. The **CreateSortedAddressPairs** function supports a maximum of 500 destination addresses.

If the **CreateSortedAddressPairs** function is successful, the *SortedAddressPairList* parameter points to an array of [SOCKADDR_IN6_PAIR](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_in6_pair) structures that contain the sorted address pairs. When this returned list is no longer required, free the memory used by the list by calling the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable) function.

## See also

[Dual-Stack Sockets](https://learn.microsoft.com/windows/desktop/WinSock/dual-stack-sockets)

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[SOCKADDR_IN6_PAIR](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_in6_pair)

[Using SIO_ADDRESS_LIST_SORT](https://learn.microsoft.com/windows/desktop/WinSock/using-sio-address-list-sort)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)