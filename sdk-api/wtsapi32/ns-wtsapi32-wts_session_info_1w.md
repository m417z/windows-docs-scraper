# WTS_SESSION_INFO_1W structure

## Description

Contains
extended information about a client session on a Remote Desktop Session Host (RD Session Host) server or Remote Desktop Virtualization Host (RD Virtualization Host) server.

## Members

### `ExecEnvId`

An identifier that uniquely identifies the session within the list of sessions returned by the [WTSEnumerateSessionsEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsexa) function. For more information, see Remarks.

### `State`

A value of the [WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class) enumeration type that specifies the connection state of a Remote Desktop Services session.

### `SessionId`

A session identifier assigned by the RD Session Host server, RD Virtualization Host server, or virtual machine.

### `pSessionName`

A pointer to a null-terminated string that contains the name of this session. For example, "services", "console", or "RDP-Tcp#0".

### `pHostName`

A pointer to a null-terminated string that contains the name of the computer that the session is running on. If the session is running directly on an RD Session Host server or RD Virtualization Host server, the string contains **NULL**. If the session is running on a virtual machine, the string contains the name of the virtual machine.

### `pUserName`

A pointer to a null-terminated string that contains the name of the user who is logged on to the session. If no user is logged on to the session, the string contains **NULL**.

### `pDomainName`

A pointer to a null-terminated string that contains the domain name of the user who is logged on to the session. If no user is logged on to the session, the string contains **NULL**.

### `pFarmName`

A pointer to a null-terminated string that contains the name of the farm that the virtual machine is joined to. If the session is not running on a virtual machine that is joined to a farm, the string contains **NULL**.

## Remarks

The [WTSEnumerateSessionsEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsexa) function returns this structure if you call the function and specify a handle to an RD Virtualization Host server that you obtained by calling the [WTSOpenServerEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenserverexa) function. In this case, the **WTSEnumerateSessionsEx** function aggregates all the sessions running on the host itself as well as sessions running on individual virtual machines. The *ExecEnvId* parameter uniquely identifies each session in the aggregated list. This identifier may be different from the actual session identifier defined in the server or virtual machine that hosts the session, which is specified by the **SessionId** member.

The session represented by this structure could be a session running directly on the server or a session running within a virtual machine. If the session is running within a virtual machine, the **pHostName** member contains the name of the virtual machine. The **pFarmName** member is applicable to sessions that are hosted on virtual machines that are joined to a RD Session Host farm.

> [!NOTE]
> The wtsapi32.h header defines WTS_SESSION_INFO_1 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTSEnumerateSessionsEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsexa)

[WTS_SESSION_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_infoa)