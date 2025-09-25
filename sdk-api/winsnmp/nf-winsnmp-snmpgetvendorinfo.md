# SnmpGetVendorInfo function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

A WinSNMP application calls the
**SnmpGetVendorInfo** function to retrieve information about the Microsoft WinSNMP implementation. The function returns the information in an
[smiVENDORINFO](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivendorinfo) structure. The
**SnmpGetVendorInfo** function is an element of the WinSNMP API, version 2.0.

## Parameters

### `vendorInfo` [out]

Pointer to an
[smiVENDORINFO](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivendorinfo) structure to receive information. The information includes a way to contact Microsoft and the enterprise number assigned to Microsoft by the Internet Assigned Numbers Authority (IANA).

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_NOOP** | The *vendorInfo* parameter is **NULL**. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## See also

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiVENDORINFO](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivendorinfo)