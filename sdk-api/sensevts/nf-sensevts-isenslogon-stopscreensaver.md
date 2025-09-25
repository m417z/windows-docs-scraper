# ISensLogon::StopScreenSaver

## Description

The
**StopScreenSaver** method notifies an application that a screen saver is stopped.

## Parameters

### `bstrUserName` [in]

The name of a current user.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method returns successfully. |

## Remarks

SENS calls this method to notify an application that a screen saver is stopped.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty)

[ISensLogon](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isenslogon)

[ISensLogon::DisplayLock](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-displaylock)

[ISensLogon::DisplayUnLock](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-displayunlock)

[ISensLogon::StartScreenSaver](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-startscreensaver)