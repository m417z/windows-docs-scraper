# SnmpMgrOpen function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrOpen** function initializes communications sockets and data structures, allowing communications with the specified SNMP agent. This function is an element of the SNMP Management API.

## Parameters

### `lpAgentAddress` [in]

Pointer to a **null**-terminated string that specifies a host name or an IP address. The host name must resolve to an IP address, an IPX address (in 8.12 notation), or an ethernet address. See the Remarks section for the acceptable forms for host names and IP addresses.

### `lpAgentCommunity` [in]

Pointer to a **null**-terminated string that specifies the SNMP community name to use when communicating with the agent that is identified by the *lpAgentAddress* parameter.

### `nTimeOut` [in]

Specifies the communications time-out in milliseconds.

### `nRetries` [in]

Specifies the communications retry count. The time-out that is specified in the *nTimeOut* parameter is doubled each time that a retry attempt is transmitted.

## Return value

If the function succeeds, the return value is a pointer to an **LPSNMP_MGR_SESSION** structure. This structure is used internally and the programmer should not alter it. For more information, see the following Remarks section.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return the SNMP_MEM_ALLOC_ERROR error code, which indicates a memory allocation error.

This function may also return Windows Sockets error codes.

## Remarks

If possible, use a host name to identify the SNMP agent in the *lpAgentAddress* parameter. Host names can be provided for agents only if TCP/IP is loaded and the names are TCP/IP host names. NetBIOS names cannot be supplied for IPX hosts.

The name and address of the SNMP target, or the string pointed to by the *lpAgentAddress* parameter, should conform to one of the following forms.

| Name/Address | Form (example) |
| --- | --- |
| Host Name | merlin or merlin.microsoft.com |
| IPv4 Address | 157.57.8.160 |
| IPv6 Address | 3ffe:8311:ffff::b3ff:fe88:c33 |
| MAC Address | 00aa00bbccdd |
| IPX Address | 00006112.00aa00bbccdd |

Applications should not use the **LPSNMP_MGR_SESSION** pointer that is returned by this function to call the
[SnmpMgrRequest](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrrequest) function in the context of a different thread.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrClose](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrclose)

[SnmpMgrRequest](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrrequest)