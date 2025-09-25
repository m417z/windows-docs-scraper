# ISensOnNow::BatteryLow

## Description

The
**BatteryLow** method notifies an application that battery power is low. SENS calls the **BatteryLow** method to notify an application that a computer is using battery power.

Low battery power is signaled when a system is on battery power and the battery is low according to the same logic used by the Advanced Power Management (APM) event PBT_APMBATTERYLOW. This event is broadcast when a system APM BIOS sends an APM battery low notification.

Some APM BIOS implementations do not provide notifications when batteries are low, which means that this event may never be broadcast on some computers.

## Parameters

### `dwBatteryLifePercent` [in]

The percent of battery power that remains.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method returns successfully. |

## Remarks

SENS calls this method to notify an application that a computer is using battery power. The remaining percentage of battery power is specified.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty)

[ISensOnNow](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isensonnow)

[ISensOnNow::OnBatteryPower](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isensonnow-onbatterypower)