# MSiSCSI_Eventlog structure

## Description

The **MSiSCSI_EventLog** method is used to log any messages to the event log.

## Members

### `Type`

This specifies the EVENTLOG_MESSAGE_QUALIFIERS type of event log message.

### `Size`

This specifies the size of the Additional Data field.

### `AdditionalData[1]`

This provides additional information associated with this event.

### `LogToEventlog`

If this value it set to 1, the message will be logged to the system event log.

## Remarks

It is recommended that you implement this class.