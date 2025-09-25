# RasConnectionNotificationA function

## Description

The
**RasConnectionNotification** function specifies an event object that the system sets to the signaled state when a RAS connection is created or terminated.

## Parameters

### `unnamedParam1` [in]

A handle to the RAS connection that receives the notifications. This can be a handle returned by the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) function. If this parameter is **INVALID_HANDLE_VALUE**, notifications are received for all RAS connections on the local client.

### `unnamedParam2` [in]

Specifies the handle of an event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create an event object.

### `unnamedParam3` [in]

Specifies the RAS event that causes the system to signal the event object specified by the *hEvent* parameter. This parameter is a combination of the following values.

| Value | Meaning |
| --- | --- |
| **RASCN_Connection** | If *hrasconn* is **INVALID_HANDLE_VALUE**, *hEvent* is signaled when any RAS connection is created. |
| **RASCN_Disconnection** | *hEvent* is signaled when the *hrasconn* connection is terminated. If *hrasconn* is a multilink connection, the event is signaled when all subentries are disconnected. If *hrasconn* is **INVALID_HANDLE_VALUE**, the event is signaled when any RAS connection is terminated. |
| **RASCN_BandwidthAdded** | **Windows NT:** If *hrasconn* is a handle to a combined multilink connection, *hEvent* is signaled when a subentry is connected. |
| **RASCN_BandwidthRemoved** | **Windows NT:** If *hrasconn* is a handle to a combined multilink connection, *hEvent* is signaled when a subentry is disconnected. |

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a non-zero error code from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

To determine when the event object is signaled, use any of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions).

When the event is signaled, use other RAS functions, such as
[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa), to get more information about the RAS connection that was created or terminated.

> [!NOTE]
> The ras.h header defines RasConnectionNotification as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)