# LPDHCP_CONTROL callback function

## Description

The
**DhcpControlHook** function is called by Microsoft DHCP Server when the DHCP Server service is started, stopped, paused, or continued. The
**DhcpControlHook** is implemented by a third-party DLL that registers for notification of significant Microsoft DHCP Server events. The
**DhcpControlHook** function should not block.

## Parameters

### `dwControlCode` [in]

Specifies the control event that triggered the notification. This parameter will be one of the following:

* DHCP_CONTROL_START
* DHCP_CONTROL_STOP
* DHCP_CONTROL_PAUSE
* DHCP_CONTROL_CONTINUE

### `lpReserved` [in]

Reserved for future use.

## Return value

Return values are defined by the application providing the callback.

## Remarks

This routine should not block.

## See also

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)

[DhcpServerCalloutEntry](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_entry_point_func)

[How the
DHCP Server API Operates](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/how-the-dhcp-server-api-operates)