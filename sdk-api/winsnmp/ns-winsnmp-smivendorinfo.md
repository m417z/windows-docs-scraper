# smiVENDORINFO structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**smiVENDORINFO** structure contains information about the Microsoft WinSNMP implementation. A WinSNMP application can call the
[SnmpGetVendorInfo](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvendorinfo) function to retrieve this structure. The
**smiVENDORINFO** structure is an element of the WinSNMP API, version 2.0.

## Members

### `vendorName`

Contains the null-terminated string "Microsoft Corporation". The string is suitable for display to end users.

### `vendorContact`

Specifies a null-terminated character string that indicates how Microsoft can be contacted for WinSNMP-related information. For example, this member can contain a postal address, a telephone number or a fax number, a URL, or an e-mail address such as "snmpinfo@microsoft.com". The string is suitable for display.

### `vendorVersionId`

Specifies a null-terminated character string that identifies the version number of the WinSNMP API the Microsoft WinSNMP implementation is currently supporting. The string is suitable for display.

### `vendorVersionDate`

Specifies a null-terminated character string that indicates the release date of the version of the WinSNMP API the Microsoft WinSNMP implementation is currently supporting. The string is suitable for display.

### `vendorEnterprise`

Contains the value 311, Microsoft's enterprise number (permanent address) assigned by the Internet Assigned Numbers Authority (IANA).

## See also

[SnmpGetVendorInfo](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvendorinfo)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[WinSNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-structures)