# _SECURE_ELEMENT_EVENT_TYPE enumeration

## Description

Indicates the type of secure element events.

## Constants

### `ExternalReaderArrival`

This event is fired when an external reader has established a connection with the indicated secure element. No other parameters are given for this event.

### `ExternalReaderDeparture`

This event is fired when an external reader has terminated a connection with the indicated secure element. No other parameters are given for this event.

### `ApplicationSelected`

This event is fired when the external reader has issued a "SELECT" command to select an application on the specified secure element. Additionally, the event notification includes the application ID (AID) of the selected application. Not all types of secure elements support the ability to raise this event.

### `Transaction`

This event is fired when an application that is operating within the secure element notifies the controller that some form of action has occurred. This event sends a list of parameters that is coded in BER-TLV fields. This event is mapped to EVT_TRANSACTION.

### `HceActivated`

This event is fired when a listen mode interface is activated to the device host. This event sends the current connection ID, activated RF protocol, and technology.

### `HceDeactivated`

This event is fired when a current active HCE session is terminated. This event sends the currently terminated connection ID.

### `ExternalFieldEnter`

This event is fired upon entering an external field.

### `ExternalFieldExit`

This event is fired upon exiting an external field.