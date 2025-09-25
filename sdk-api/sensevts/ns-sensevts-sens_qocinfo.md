# SENS_QOCINFO structure

## Description

The
**SENS_QOCINFO** structure is used by the
[ISensNetwork::ConnectionMade](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isensnetwork-connectionmade) method. This structure contains Quality of Connection information to the sink object in an application that subscribes to SENS.

## Members

### `dwSize`

This member contains the actual size of the structure that was filled in.

### `dwFlags`

Speed of connection. Flag bits indicate whether the connection is slow, medium, fast.

### `dwOutSpeed`

Speed of data sent to the destination in bits per second.

### `dwInSpeed`

Speed of data coming in from the destination in bits per second.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty)

[ISensNetwork::ConnectionMade](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isensnetwork-connectionmade)