# ISensOnNow::OnACPower

## Description

SENS calls the
**OnACPower** method to notify your application that the computer is using AC power.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method returned successfully. |

## Remarks

SENS calls this method to notify your application that AC power has been activated.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty)

[ISensOnNow](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isensonnow)

[ISensOnNow::OnBatteryPower](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isensonnow-onbatterypower)