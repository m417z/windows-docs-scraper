# MPR_INTERFACE_1 structure

## Description

The
**MPR_INTERFACE_1** structure contains configuration and status information for a particular router interface.

## Members

### `wszInterfaceName`

Pointer to a Unicode string that contains the name of the interface.

### `hInterface`

Handle to the interface.

### `fEnabled`

Specifies whether the interface is enabled. This value is **TRUE** if the interface is enabled, **FALSE** if the interface is administratively disabled.

### `dwIfType`

Specifies the
[type of interface](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type).

### `dwConnectionState`

Specifies the current state of the interface, for example connected, disconnected, or unreachable. For a list of possible states, see
[ROUTER_CONNECTION_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_connection_state).

### `fUnReachabilityReasons`

Specifies a value that represents a reason why the interface was unreachable. See
[Unreachability Reasons](https://learn.microsoft.com/windows/desktop/RRAS/unreachability-reasons) for a list of possible values.

### `dwLastError`

Specifies a nonzero value if the interface fails to connect.

### `lpwsDialoutHoursRestriction`

Pointer to a Unicode string that specifies the times during which dial-out is restricted. The format for this string is:

``` syntax
<day><space><time range><space><time range> . . . <NULL><day>. . . <NULL><NULL>

```

Where day is a numeral that corresponds to a day of the week.

| Numeral | Meaning |
| --- | --- |
| 0 | Sunday |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |

Time range is of the form HH:MM-HH:MM, using 24-hour notation.

The string \<space> in the preceding syntax denotes a space character. The string \<NULL> denotes a null character.

The restriction string is terminated by two consecutive null characters.

Example:

``` syntax
2 09:00-12:00 13:00-17:30<NULL>4 09:00-12:00 13:00-17:30<NULL><NULL>

```

The preceding string restricts dial-out to Tuesdays and Thursdays from 9:00 AM to 12:00 PM and from 1:00 PM to 5:30 PM.

## See also

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceenum)

[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo)

[ROUTER_CONNECTION_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_connection_state)

[ROUTER_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)

[Unreachability Reasons](https://learn.microsoft.com/windows/desktop/RRAS/unreachability-reasons)