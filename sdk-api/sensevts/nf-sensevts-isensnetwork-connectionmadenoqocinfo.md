# ISensNetwork::ConnectionMadeNoQOCInfo

## Description

The
**ConnectionMadeNoQOCInfo** method notifies your application that the specified connection has been established with no Quality of Connection information available.

**Note** This method is only available for TCP/IP connections.

## Parameters

### `bstrConnection` [in]

For WAN connections, the information passed is the connection name. For WAN connections, the connection name is the name of the phone book entry. For LAN connections, the information passed is "LAN connection".

### `ulType` [in]

Connection type. This value can be CONNECTION_LAN (0) or CONNECTION_WAN (1).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method returned successfully. |

## Remarks

SENS calls this method to notify your application that the specified connection has been established when Quality of Connection information is not available.

Filtering can be performed on the publisher property *ulConnectionMadeTypeNoQOC* by setting it to either CONNECTION_LAN or CONNECTION_WAN or both. Use
[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty) to set the publisher property.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty)

[ISensNetwork](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isensnetwork)

[ISensNetwork::ConnectionMade](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isensnetwork-connectionmade)