# LPDHCP_ENTRY_POINT_FUNC callback function

## Description

The
**DhcpServerCalloutEntry** function is called by Microsoft DHCP Server to initialize a third-party DLL, and to discover for which events the third-party DLL wants notification. The
**DhcpServerCalloutEntry** function is implemented by third-party DLLs.

## Parameters

### `ChainDlls` [in]

Collection of remaining third-party DLLs that provided registry entries requesting notification of DHCP Server events, in REG_MULTI_SZ format.

### `CalloutVersion` [in]

Version of the DHCP Server API that the third-party DLL is expected to support. The current version number is zero.

### `CalloutTbl` [out]

Cumulative set of notification hooks requested by all third-party DLLs, in the form of a
[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table) structure.

## Return value

Return values are defined by the application providing the callback.

## Remarks

Upon successful loading of a third-party DLL, Microsoft DHCP Server calls the DLL's
**DhcpServerCalloutEntry** function. If this function call succeeds, Microsoft DHCP Server does not attempt to load any further third-party DLLs, and instead passes the list of remaining third-party DLLs in the *ChainDlls* parameter. It is the responsibility of the loaded third-party DLL to ensure that:

* other third-party DLLs are loaded
* their
  **DhcpServerCalloutEntry** function called
* the merged list of requested notification entry points are returned to Microsoft DHCP Server in the *CalloutTbl* parameter.

The initially loaded third-party DLL is responsible for maintaining a table of cumulative notification entry points, and upon notification of a particular event, must call all chained third-party DLLs before returning to Microsoft DHCP Server.

**Note** For version negotiation, Microsoft DHCP Server may call the
**DhcpServerCalloutEntry** function until a compatible version is found.

## See also

[Chaining Multiple Third-Party DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/chaining-multiple-third-party-dlls)

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)

[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types)