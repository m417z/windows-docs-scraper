# UiaPropertyChangedEventArgs structure

## Description

**Note** This structure is deprecated.

Contains information about an event that is raised when a Microsoft UI Automation element property change occurs.

## Members

### `Type`

Type: **[EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype)**

A value from the [EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype) enumerated type indicating the type of event.

### `EventId`

Type: **int**

The identifier of the event. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `PropertyId`

Type: **PROPERTYID**

The identifier of the property that has changed. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `OldValue`

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

A [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) containing the old value of the property.

### `NewValue`

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

A [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) containing the new value of the property.

## Remarks

The old value might not be set if the UI Automation provider cannot do so efficiently.