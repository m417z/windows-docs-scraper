# ISensNetwork::ConnectionLost

## Description

The
**ConnectionLost** method notifies your application that the specified connection has been dropped.

**Note** This method is only available for TCP/IP connections.

## Parameters

### `bstrConnection` [in]

For WAN connections, the information passed is the connection name. For WAN connections, the connection name is the name of the phone book entry. For LAN connections, the information passed is "LAN connection".

### `ulType` [in]

Connection type. This value can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CONNECTION_LAN**<br><br>0 | The connection is to a Local Area Network (LAN). |
| **CONNECTION_WAN**<br><br>1 | The connection is to a Wide Area Network (WAN). |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method returned successfully. |

## Remarks

SENS calls this method to notify your application that the specified connection has been dropped.

Filtering can be performed on the publisher property *ulConnectionLostType* by setting it to either CONNECTION_LAN or CONNECTION_WAN or both. Use
[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty) to set the publisher property.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

[IEventSubscription::PutPublisherProperty](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsubscription-putpublisherproperty)

[ISensNetwork](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isensnetwork)