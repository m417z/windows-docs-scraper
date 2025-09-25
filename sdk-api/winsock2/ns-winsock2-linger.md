# LINGER structure

## Description

The
**linger** structure maintains information about a specific socket that specifies how that socket should behave when data is queued to be sent and the
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function is called on the socket.

## Members

### `l_onoff`

Type: **u_short**

Specifies whether a socket should remain open for a specified amount of time after a
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function call to enable queued data to be sent. This member can have one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The socket will not remain open. This is the value set if the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function is called with the *optname* parameter set to **SO_DONTLINGER** and the *optval* parameter is zero. <br><br>This value is also set if the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function is called with the *optname* parameter set to **SO_LINGER** and the **linger** structure passed in the *optval* parameter has the **l_onoff** member set to 0. |
| nonzero | The socket will remain open for a specified amount of time. This value is set if the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function is called with the *optname* parameter set to **SO_DONTLINGER** and the *optval* parameter is nonzero.<br><br>This value is also set if the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function is called with the *optname* parameter set to **SO_LINGER** and the **linger** structure passed in the *optval* parameter has the **l_onoff** member set to a nonzero value. |

### `l_linger`

Type: **u_short**

The linger time in seconds. This member specifies how long to remain open after a
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function call to enable queued data to be sent. This member is only applicable if the **l_onoff** member of the **linger** structure is set to a nonzero value.

This value is set if the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function is called with the *optname* parameter set to **SO_LINGER**. The *optval* parameter passed to the **setsockopt** function must contain a **linger** structure that is copied to the internal **linger** structure maintained for the socket.

## Remarks

The **l_onoff** member of the **linger** structure determines whether a socket should remain open for a specified amount of time after a
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function call to enable queued data to be sent. Somewhat confusing is that this member can be modified in two ways:

* Call the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function with the *optname* parameter set to **SO_DONTLINGER**. The *optval* parameter determines how the **l_onoff** member is modified.
* Call the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function with the *optname* parameter set to **SO_LINGER**. The *optval* parameter specifies how both the **l_onoff** and **l_linger** members are modified.

The **l_linger** member of the **linger** structure determines the amount of time, in seconds, a socket should remain open. This member is only applicable if the **l_onoff** member of the **linger** structure is nonzero.

To enable a socket to remain open, an application should set the **l_onoff** member to a nonzero value and set the **l_linger** member to the desired time-out in seconds. To disable a socket from remaining open, an application only needs to set the **l_onoff** member of the **linger** structure to zero.

 If an application calls the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function with the *optname* parameter set to **SO_DONTLINGER** to set the **l_onoff** member to a nonzero value, the value for the **l_linger** member is not specified. In this case, the time-out used is implementation dependent. If a previous time-out has been established for a socket (by enabling SO_LINGER), this time-out value should be reinstated by the service provider.

Note that enabling a nonzero timeout on a nonblocking socket is not recommended.

The [getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function can be called with the *optname* parameter set to **SO_LINGER** to retrieve the current value of the **linger** structure associated with a socket.

## See also

[Graceful Shutdown, Linger Options, and Socket Closure](https://learn.microsoft.com/windows/desktop/WinSock/graceful-shutdown-linger-options-and-socket-closure-2)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)