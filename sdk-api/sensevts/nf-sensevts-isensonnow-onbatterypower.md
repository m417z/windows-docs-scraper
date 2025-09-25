# ISensOnNow::OnBatteryPower

## Description

SENS calls the
**OnBatteryPower** method to notify an application that a computer is using battery power.

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

[ISensOnNow::BatteryLow](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isensonnow-batterylow)

[ISensOnNow::OnACPower](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isensonnow-onacpower)