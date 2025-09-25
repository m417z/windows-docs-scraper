# COMEVENTSYSCHANGEINFO structure

## Description

Represents a system event structure, which contains the partition and application ID from which an event originated.

## Members

### `cbSize`

The size of this structure.

### `changeType`

The type of change that has been made to the subscription. For a list of values, see [EOC_ChangeType](https://learn.microsoft.com/windows/desktop/api/eventsys/ne-eventsys-eoc_changetype).

### `objectId`

The EventClass ID or subscription ID from which the change impacts.

### `partitionId`

The EventClass partition ID or the subscriber partition ID affected.

### `applicationId`

The EventClass application ID or subscriber application ID affected.

### `reserved`

This member is reserved.

## See also

[IEventObjectChange2](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectchange2)