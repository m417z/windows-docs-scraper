## Description

Cancels notifications about timestamp capability changes by unregistering the callback function you registered in a call to [**RegisterInterfaceTimestampConfigChange**](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-registerinterfacetimestampconfigchange).

To avoid deadlock, you shouldn't call **UnregisterInterfaceTimestampConfigChange** in the context of the thread that's executing a callback that was specified to **RegisterInterfaceTimestampConfigChange**. This is because **UnregisterInterfaceTimestampConfigChange** waits for outstanding notification callbacks to complete before it returns. Consequently, **UnregisterInterfaceTimestampConfigChange** mustn't be called in a way that prevents an outstanding notification callback from completing. No further callbacks will take place after **UnregisterInterfaceTimestampConfigChange** returns.

For more info, and code examples, see [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping).

## Parameters

### `NotificationHandle`

Type: \_In\_ **HIFTIMESTAMPCHANGE**

The handle that was returned by [**RegisterInterfaceTimestampConfigChange**](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-registerinterfacetimestampconfigchange). This identifies the registration to be canceled.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A **DWORD** return code indicating success or failure.

## Remarks

## See also

* [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping)
* [RegisterInterfaceTimestampConfigChange](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-registerinterfacetimestampconfigchange)