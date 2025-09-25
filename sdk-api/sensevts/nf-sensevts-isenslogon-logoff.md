# ISensLogon::Logoff

## Description

The
**Logoff** method notifies an application that a user is logged off.

## Parameters

### `bstrUserName` [in]

The name of a user who logs off.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method returns successfully. |

## Remarks

SENS calls this method to notify an application that a user is logged off.

**Important** This function will not work with multiple logins through Remote Desktop Services and does not support Remote Desktop Services or Fast-User Switching scenarios. Desktop applications can register for session changes notifications by calling [WTSRegisterSessionNotification](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotification). Services can handle session change notifications via SERVICE_CONTROL_SESSIONCHANGE control codes in their [HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) callback function.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty)

[ISensLogon](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isenslogon)

[ISensLogon::Logon](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-logon)