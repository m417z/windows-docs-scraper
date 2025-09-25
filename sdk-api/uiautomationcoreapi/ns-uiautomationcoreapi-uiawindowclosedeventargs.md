# UiaWindowClosedEventArgs structure

## Description

**Note** This structure is deprecated.

Contains information about an event that is raised when one or more windows closes.

## Members

### `Type`

Type: **[EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype)**

A value from the [EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype) enumerated type indicating the type of event.

### `EventId`

Type: **int**

The event identifier. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `pRuntimeId`

Type: **int***

The address of an array of the UI Automation runtime identifiers of windows that have closed.

### `cRuntimeIdLen`

Type: **int**

The count of elements in the array.

## Remarks

This event is raised for any window (HWND) that closes, not just top-level windows.