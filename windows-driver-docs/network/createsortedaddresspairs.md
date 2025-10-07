# CreateSortedAddressPairs function

From a supplied list of potential IP destination addresses, the **CreateSortedAddressPairs** function pairs the destination addresses together with the host machine's local IP addresses and sorts the pairs according to the preferred order of communication.

## Parameters

- *SourceAddressList* \[in, optional\]
Reserved. This parameter must be **NULL**.

- *SourceAddressCount* \[in\]
Reserved. This parameter must be zero.

- *DestinationAddressList* \[in\]
A pointer to a list of potential destination addresses of type [**SOCKADDR\_IN6**](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-sockaddr_in6_lh).

- *DestinationAddressCount* \[in\]
The number of addresses in the list that the *DestinationAddressList* parameter points to.

- *AddressSortOptions* \[in\]
Reserved. This parameter must be zero.

- *SortedAddressPairList* \[in\]
A pointer to a list of pairs of source and destination addresses, sorted in the preferred order of communication. For more information about this parameter, see the following Remarks section.

- *SortedAddressPairCount* \[out\]
The number of address pairs in the list that the *SortedAddressPairList* parameter points to.

## Return value

**CreateSortedAddressPairs** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **CreateSortedAddressPairs** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **STATUS_NOT_ENOUGH_MEMORY** | Insufficient memory resources were available to complete the operation. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **CreateSortedAddressPairs** function automatically pairs the host machine's local addresses together with the supplied list of potential destination addresses that the *DestinationAddressList* parameter points to.

The returned list of pairs of addresses that the *SortedAddressPairList* parameter points to is sorted so that the address pairs that are best suited for communication between two peers occurr earlier in the list.

The *SortedAddressPairList* parameter is of type PSOCKADDR\_IN6\_PAIR, which is defined in the Ws2ipdef.h header as follows.

```cpp
    typedef struct _sockaddr_in6_pair
    {
        PSOCKADDR_IN6  SourceAddress;
        PSOCKADDR_IN6  DestinationAddress;
    } SOCKADDR_IN6_PAIR, *PSOCKADDR_IN6_PAIR;

  - **SourceAddress**
    The IP source address.

  - **DestinationAddress**
    The IP destination address.
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage)

[**SOCKADDR\_IN6**](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-sockaddr_in6_lh)