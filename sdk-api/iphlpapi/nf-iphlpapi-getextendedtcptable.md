# GetExtendedTcpTable function

## Description

The **GetExtendedTcpTable** function retrieves a table that contains a list of TCP endpoints available to the application.

## Parameters

### `pTcpTable` [out]

A pointer to the table structure that contains the filtered TCP endpoints available to the application. For information about how to determine the type of table returned based on specific input parameter combinations, see the Remarks section later in this document.

### `pdwSize` [in, out]

The estimated size of the structure returned in *pTcpTable*, in bytes. If this value is set too small, **ERROR_INSUFFICIENT_BUFFER** is returned by this function, and this field will contain the correct size of the structure.

### `bOrder` [in]

A value that specifies whether the TCP connection table should be sorted. If this parameter is set to **TRUE**, the TCP endpoints in the table are sorted in ascending order, starting with the lowest local IP address. If this parameter is set to **FALSE**, the TCP endpoints in the table appear in the order in which they were retrieved.

The following values are compared (as listed) when ordering the TCP endpoints:

1. Local IP address
2. Local scope ID (applicable when the *ulAf* parameter is set to AF_INET6)
3. Local TCP port
4. Remote IP address
5. Remote scope ID (applicable when the *ulAf* parameter is set to AF_INET6)
6. Remote TCP port

### `ulAf` [in]

The version of IP used by the TCP endpoints.

| Value | Meaning |
| --- | --- |
| **AF_INET** | IPv4 is used. |
| **AF_INET6** | IPv6 is used. |

### `TableClass` [in]

The type of the TCP table structure to retrieve. This parameter can be one of the values from the [TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class) enumeration.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the [TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class) enumeration is defined in the *Iprtrmib.h* header file, not in the *Iphlpapi.h* header file.

The [TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class) enumeration value is combined with the value of the *ulAf* parameter to determine the extended TCP information to retrieve.

### `Reserved` [in]

Reserved. This value must be zero.

## Return value

If the call is successful, the value **NO_ERROR** is returned.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | An insufficient amount of space was allocated for the table. The size of the table is returned in the *pdwSize* parameter, and must be used in a subsequent call to this function in order to successfully retrieve the table.<br><br>This error is also returned if the *pTcpTable* parameter is **NULL**. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *TableClass* parameter contains a value that is not defined in the [TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class) enumeration. |

## Remarks

The table type returned by this function depends on the specific combination of the *ulAf* parameter and the *TableClass* parameter.

When the *ulAf* parameter is set to **AF_INET**, the following table indicates the TCP table type to retrieve in the structure pointed to by the *pTcpTable* parameter for each possible *TableClass* value.

| *TableClass* value | *pTcpTable* structure |
| --- | --- |
| **TCP_TABLE_BASIC_ALL** | [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) |
| **TCP_TABLE_BASIC_CONNECTIONS** | [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) |
| **TCP_TABLE_BASIC_LISTENER** | [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) |
| **TCP_TABLE_OWNER_MODULE_ALL** | [MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module) |
| **TCP_TABLE_OWNER_MODULE_CONNECTIONS** | [MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module) |
| **TCP_TABLE_OWNER_MODULE_LISTENER** | [MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module) |
| **TCP_TABLE_OWNER_PID_ALL** | [MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid) |
| **TCP_TABLE_OWNER_PID_CONNECTIONS** | [MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid) |
| **TCP_TABLE_OWNER_PID_LISTENER** | [MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid) |

 When the *ulAf* parameter is set to **AF_INET6**, the following table indicates the TCP table type to retrieve in the structure pointed to by the *pTcpTable* parameter for each possible *TableClass* value.

| *TableClass* value | *pTcpTable* structure |
| --- | --- |
| **TCP_TABLE_OWNER_MODULE_ALL** | [MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module) |
| **TCP_TABLE_OWNER_MODULE_CONNECTIONS** | [MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module) |
| **TCP_TABLE_OWNER_MODULE_LISTENER** | [MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module) |
| **TCP_TABLE_OWNER_PID_ALL** | [MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid) |
| **TCP_TABLE_OWNER_PID_CONNECTIONS** | [MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid) |
| **TCP_TABLE_OWNER_PID_LISTENER** | [MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid) |

The **GetExtendedTcpTable** function called with the *ulAf* parameter set to **AF_INET6** and the *TableClass* set to **TCP_TABLE_BASIC_LISTENER**, **TCP_TABLE_BASIC_CONNECTIONS**, or **TCP_TABLE_BASIC_ALL** is not supported and returns **ERROR_NOT_SUPPORTED**.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed. The various [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) structures are defined in the *Tcpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module)

[MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module)

[MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid)

[TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class)