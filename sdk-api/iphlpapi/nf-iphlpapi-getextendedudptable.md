# GetExtendedUdpTable function

## Description

The **GetExtendedUdpTable** function retrieves a table that contains a list of UDP endpoints available to the application.

## Parameters

### `pUdpTable` [out]

A pointer to the table structure that contains the filtered UDP endpoints available to the application. For information about how to determine the type of table returned based on specific input parameter combinations, see the Remarks section later in this document.

### `pdwSize` [in, out]

The estimated size of the structure returned in *pUdpTable*, in bytes. If this value is set too small, **ERROR_INSUFFICIENT_BUFFER** is returned by this function, and this field will contain the correct size of the structure.

### `bOrder` [in]

A value that specifies whether the UDP endpoint table should be sorted. If this parameter is set to **TRUE**, the UDP endpoints in the table are sorted in ascending order, starting with the lowest local IP address. If this parameter is set to **FALSE**, the UDP endpoints in the table appear in the order in which they were retrieved.

The following values are compared as listed when ordering the UDP endpoints:

1. Local IP address
2. Local scope ID (applicable when the *ulAf* parameter is set to AF_INET6)
3. Local UDP port

### `ulAf` [in]

The version of IP used by the UDP endpoint.

| Value | Meaning |
| --- | --- |
| **AF_INET** | IPv4 is used. |
| **AF_INET6** | IPv6 is used. |

### `TableClass` [in]

The type of the UDP table structure to retrieve. This parameter can be one of the values from the [UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class) enumeration.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the [UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class) enumeration is defined in the *Iprtrmib.h* header file, not in the *Iphlpapi.h* header file.

 The [UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class) enumeration value is combined with the value of the *ulAf* parameter to determine the extended UDP information to retrieve.

### `Reserved` [in]

Reserved. This value must be zero.

## Return value

If the call is successful, the value **NO_ERROR** is returned.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | An insufficient amount of space was allocated for the table. The size of the table is returned in the *pdwSize* parameter, and must be used in a subsequent call to this function in order to successfully retrieve the table.<br><br>This error is also returned if the *pUdpTable* parameter is **NULL**. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *TableClass* parameter contains a value that is not defined in the [UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class) enumeration. |

## Remarks

The table type returned by this function depends on the specific combination of the *ulAf* parameter and the *TableClass* parameter.

When the *ulAf* parameter is set to **AF_INET**, the following table indicates the UDP table type to retrieve in the structure pointed to by the *pUdpTable* parameter for each possible *TableClass* value.

| *TableClass* value | *pUdpTable* structure |
| --- | --- |
| **UDP_TABLE_BASIC** | [MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable) |
| **UDP_TABLE_OWNER_MODULE** | [MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module) |
| **UDP_TABLE_OWNER_PID** | [MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid) |

 When the *ulAf* parameter is set to **AF_INET6**, the following table indicates the TCP table type to retrieve in the structure pointed to by the *pUdpTable* parameter for each possible *TableClass* value.

| *TableClass* value | *pUdpTable* structure |
| --- | --- |
| **UDP_TABLE_BASIC** | [MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table) |
| **UDP_TABLE_OWNER_MODULE** | [MIB_UDP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_module) |
| **UDP_TABLE_OWNER_PID** | [MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid) |

The **GetExtendedUdpTable** function when called with the *ulAf* parameter set to **AF_INET6** and the *TableClass* set to **UDP_TABLE_BASIC** is only supported on Windows Vista and later.

On Windows Server 2003 with Service Pack 1 (SP1) and Windows XP with Service Pack 2 (SP2), the **GetExtendedUdpTable** function called with the *ulAf* parameter set to **AF_INET6** and the *TableClass* set to **UDP_TABLE_BASIC** fails and returns **ERROR_NOT_SUPPORTED**.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed. The various [MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable) structures are defined in the *Udpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Udpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Udpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_UDP6TABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table)

[MIB_UDP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_module)

[MIB_UDP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udp6table_owner_pid)

[MIB_UDPTABLE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable)

[MIB_UDPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_module)

[MIB_UDPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udptable_owner_pid)

[UDP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-udp_table_class)