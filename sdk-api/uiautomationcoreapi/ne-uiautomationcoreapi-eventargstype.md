# EventArgsType enumeration

## Description

Contains values that specify the event type described by a [UiaEventArgs](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiaeventargs) structure.

## Constants

### `EventArgsType_Simple`

A simple event that does not provide data in the event arguments.

### `EventArgsType_PropertyChanged`

An event raised by calling the [UiaRaiseAutomationPropertyChangedEvent function](https://learn.microsoft.com/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraiseautomationpropertychangedevent).

### `EventArgsType_StructureChanged`

An event raised by calling the [UiaRaiseStructureChangedEvent function](https://learn.microsoft.com/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraisestructurechangedevent).

### `EventArgsType_AsyncContentLoaded`

An event raised by calling the [UiaRaiseAsyncContentLoadedEvent function](https://learn.microsoft.com/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraiseasynccontentloadedevent).

### `EventArgsType_WindowClosed`

An event raised when a window is closed.

### `EventArgsType_TextEditTextChanged`

An event raised by calling the [UiaRaiseTextEditTextChangedEvent function](https://learn.microsoft.com/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraisetextedittextchangedevent)

### `EventArgsType_Changes`

An event raised by calling the [UiaRaiseChangesEvent function](https://learn.microsoft.com/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraisechangesevent).

### `EventArgsType_Notification`

An event raised by calling the [UiaRaiseNotificationEvent function](https://learn.microsoft.com/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraisenotificationevent).

### `EventArgsType_ActiveTextPositionChanged`

An event raised by calling the [UiaRaiseActiveTextPositionChangedEvent function](https://learn.microsoft.com/windows/win32/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraiseactivetextpositionchangedevent).