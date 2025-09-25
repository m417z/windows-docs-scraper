## Description

Registers a user-implemented callback function, which the system calls to notify you of a timestamp capability change. You can cancel the registration by calling [**UnregisterInterfaceTimestampConfigChange**](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-unregisterinterfacetimestampconfigchange).

For more info, and code examples, see [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping).

## Parameters

### `Callback`

Type: \_In\_ **[PINTERFACE_TIMESTAMP_CONFIG_CHANGE_CALLBACK](https://learn.microsoft.com/windows/win32/api/iphlpapi/nc-iphlpapi-interface_timestamp_config_change_callback)**

Your callback function, to be invoked when a timestamp capability change happens.

### `CallerContext`

Type: \_In_opt\_ **PVOID**

An optional caller-allocated context.

### `NotificationHandle`

Type: \_Out\_ **HIFTIMESTAMPCHANGE**

A handle, returned by the function, that identifies the registration.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A **DWORD** return code indicating success or failure.

## Remarks

## See also

* [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping)
* [UnregisterInterfaceTimestampConfigChange](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-unregisterinterfacetimestampconfigchange)