# UiaStructureChangedEventArgs structure

## Description

**Note** This structure is deprecated.

Contains information about an event that is raised when the structure of the Microsoft UI Automation tree changes.

## Members

### `Type`

Type: **[EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype)**

A value from the [EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype) enumerated type indicating the type of event.

### `EventId`

Type: **int**

The identifier of the event. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `StructureChangeType`

Type: **[StructureChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-structurechangetype)**

A value from the [StructureChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-structurechangetype) enumerated type indicating the type of change that has taken place.

### `pRuntimeId`

Type: **int***

The address of an array of runtime identifiers for elements involved in the change.

### `cRuntimeIdLen`

Type: **int**

The count of elements in the array.