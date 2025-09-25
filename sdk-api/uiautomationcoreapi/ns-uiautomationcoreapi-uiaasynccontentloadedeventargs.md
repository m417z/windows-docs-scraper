# UiaAsyncContentLoadedEventArgs structure

## Description

**Note** This structure is deprecated.

Contains information about an event raised when content is being asynchronously loaded by a UI element.

## Members

### `Type`

Type: **[EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype)**

A value from the [EventArgsType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-eventargstype) enumerated type indicating the type of the event.

### `EventId`

Type: **int**

The identifier of the event. For a list of event identifiers, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `AsyncContentLoadedState`

Type: **[AsyncContentLoadedState](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-asynccontentloadedstate)**

A value from the [AsyncContentLoadedState](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-asynccontentloadedstate) enumerated type indicating the state of asynchronous loading.

### `PercentComplete`

Type: **double**

The percentage of loading that has been completed.