# IsNetworkAlive function

## Description

The
**IsNetworkAlive** function determines whether or not a local system is connected to a network, and identifies the type of network connection, for example, a LAN, WAN, or both.

## Parameters

### `lpdwFlags` [out]

The type of network connection that is available. This parameter can be one of the following values:

#### NETWORK_ALIVE_LAN

The computer has one or more LAN cards that are active.

#### NETWORK_ALIVE_WAN

The computer has one or more active RAS connections.

## Return value

Always call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) before checking the return code of this function. If the last error is not 0, the **IsNetworkAlive** function has failed and the following **TRUE** and **FALSE** values do not apply.

| Return code | Description |
| --- | --- |
| **TRUE** | If the last error is 0 and the function returns **TRUE**, SENS has determined that a local system is connected to a network. <br><br>For information about the type of connection, see the *lpdwFlags* parameter. |
| **FALSE** | If the last error is 0 and the function returns **FALSE**, SENS has determined there is no connection. |

## Remarks

Starting with applications designed for Windows Vista and Windows Server 2008, developers should consider using the [Network List Manager](https://learn.microsoft.com/windows/desktop/NLA/portal) instead of this function.

This function can be used by an application to determine whether or not there is network connectivity before proceeding with network operations. A directory service type of application, e-mail client, or Internet browser can adapt to various types of network connectivity. For example, a printing operation can be deferred until a network connection is available.

It may not always be practical for an application to call
**IsNetworkAlive** to determine whether or not a local system is disconnected from a LAN, because **IsNetworkAlive** can be slow, and it may take too much time for the function to detect that a local system is disconnected.
However, **IsNetworkAlive** can always identify a WAN connectivity at the moment.

**Note** This function is only available for TCP/IP connections.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IsDestinationReachable](https://learn.microsoft.com/windows/desktop/api/sensapi/nf-sensapi-isdestinationreachablea)