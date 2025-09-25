# SERVICE_TYPE_VALUE_ABSW structure

## Description

The
**SERVICE_TYPE_VALUE_ABS** structure contains information about a network-service type value. This information may be specific to a namespace.

## Members

### `dwNameSpace`

Type: **DWORD**

A namespace, or a set of default namespaces, for which the network service type value is intended. Namespace providers will look only at values intended for their namespace.

Use one of the following constants to specify a namespace:

| Value | Meaning |
| --- | --- |
| **NS_DEFAULT** | A set of default namespaces. The function queries each namespace within this set. The set of default namespaces typically includes all the namespaces installed on the system. System administrators, however, can exclude particular namespaces from the set. NS_DEFAULT is the value that most applications should use for **dwNameSpace**. |
| **NS_DNS** | The Domain Name System used in the Internet for host name resolution. |
| **NS_NETBT** | The NetBIOS over TCP/IP layer. All Windows operating systems register their computer names with NetBIOS. This namespace is used to convert a computer name to an IP address that uses this registration. Note that NS_NETBT may access a WINS server to perform the resolution. |
| **NS_SAP** | The NetWare Service Advertising Protocol. This may access the NetWare bindery if appropriate. NS_SAP is a dynamic namespace that allows registration of services. |
| **NS_TCPIP_HOSTS** | Lookup value in the <systemroot>\system32\drivers\etc\hosts file. |
| **NS_TCPIP_LOCAL** | Local TCP/IP name resolution mechanisms, including comparisons against the local host name and looks up host names and IP addresses in cache of host to IP address mappings. |

### `dwValueType`

Type: **DWORD**

The type of the value data. Specify one of the following types:

| Value | Meaning |
| --- | --- |
| **REG_BINARY** | Binary data in any form. |
| **REG_DWORD** | A 32-bit number. |
| **REG_MULTI_SZ** | An array of null-terminated strings, terminated by two null characters. |
| **REG_SZ** | A null-terminated string. |

### `dwValueSize`

Type: **DWORD**

The size, in bytes, of the value pointed to by the **lpValue** member. In the case of REG_SZ and REG_MULTI_SZ string data, the terminating characters are counted as part of the size.

### `lpValueName`

Type: **LPTSTR**

A pointer to a **NULL**-terminated string that is the name of the value. This name is specific to a namespace.

Several commonly used value name strings are associated with defined constants. These name strings include the following.

| Constant | Meaning |
| --- | --- |
| **SERVICE_TYPE_VALUE_SAPID** | "SapId" |
| **SERVICE_TYPE_VALUE_CONN** | "ConnectionOriented" |
| **SERVICE_TYPE_VALUE_TCPPORT** | "TcpPort" |
| **SERVICE_TYPE_VALUE_UDPPORT** | "UdpPort" |

### `lpValue`

Type: **PVOID**

A pointer to the value data.

## Remarks

When you use the
[SetService](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-setservicea) function to add a network service type to a namespace, a
[SERVICE_TYPE_INFO_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_info_absa) structure is passed as the **ServiceSpecificInfo** BLOB member of a
[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) structure. Although the **ServiceSpecificInfo** member generally should not contain pointers, an exception is made in the case of the
**SERVICE_TYPE_INFO_ABS** and
**SERVICE_TYPE_VALUE_ABS** structures.

> [!NOTE]
> The nspapi.h header defines SERVICE_TYPE_VALUE_ABS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa)

[SERVICE_TYPE_INFO_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_info_absa)

[SetService](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-setservicea)