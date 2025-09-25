## Description

A support structure used in the [MI_Application](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_application) structure. Use the functions with the name prefix "MI_Application_" to manipulate these structures.

## Members

### `Close`

Deinitializes the management infrastructure. See
[MI_Application_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_close).

### `NewSession`

Creates a session that allows a group of operations that go to the same destination to be grouped so they
can share connections. See
[MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession).

### `NewHostedProvider`

Creates a new hosted Provider. See
[MI_Application_NewHostedProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newhostedprovider).

### `NewInstance`

Creates an instance. See
[MI_Application_NewInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newinstance).

### `NewDestinationOptions`

Creates an [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object.
See [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `NewOperationOptions`

Creates an [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) object. See
[MI_Application_NewOperationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newoperationoptions).

### `NewSubscriptionDeliveryOptions`

See
[MI_Application_NewSubscriptionDeliveryOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsubscriptiondeliveryoptions).

### `NewSerializer`

Creates a serializer allowing a [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) or an
[MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) to be persisted in a form that can be stored to
disk or transported over a transport. See
[MI_Application_NewSerializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newserializer).

### `NewDeserializer`

Creates a deserializer that can be used to re-create the
[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) or
[MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class). See
[MI_Application_NewDeserializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdeserializer).

### `NewInstanceFromClass`

TBD

### `NewClass`

TBD