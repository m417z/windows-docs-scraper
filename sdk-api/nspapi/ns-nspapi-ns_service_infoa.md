# NS_SERVICE_INFOA structure

## Description

The
**NS_SERVICE_INFO** structure contains information about a network service or a network service type in the context of a specified namespace, or a set of default namespaces.

## Members

### `dwNameSpace`

Type: **DWORD**

Namespace, or a set of default namespaces, to which this service information applies.

Use one of the following constant values to specify a namespace.

| Value | Meaning |
| --- | --- |
| **NS_DEFAULT** | A set of default namespaces. The set of default namespaces typically includes all the namespaces installed on the system. System administrators, however, can exclude particular namespaces from the set. |
| **NS_DNS** | The Domain Name System used in the Internet to resolve the name of the host. |
| **NS_MS** | The Microsoft namespace. |
| **NS_NDS** | The NetWare 4 provider. |
| **NS_NETBT** | The NetBIOS over TCP/IP layer. The operating system registers their computer names with NetBIOS. This namespace is used to convert a computer name to an IP address that uses this registration. |
| **NS_NIS** |  |
| **NS_SAP** | The NetWare Service Advertising Protocol. This can access the NetWare bindery, if appropriate. NS_SAP is a dynamic namespace that enables the registration of services. |
| **NS_STDA** |  |
| **NS_TCPIP_HOSTS** | Lookup value in the <systemroot>\system32\drivers\etc\posts file. |
| **NS_TCPIP_LOCAL** | Local TCP/IP name resolution mechanisms, including comparisons against the local host name and lookup value in the cache of host to IP address mappings. |
| **NS_WINS** | The Windows Internet Name System (WINS) namespace. |
| **NS_X500** | The X.500 directory service namespace. |

### `ServiceInfo`

Type: **SERVICE_INFO**

A
[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) structure that contains information about a network service or network service type.

## See also

[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa)

## Remarks

> [!NOTE]
> The nspapi.h header defines NS_SERVICE_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).