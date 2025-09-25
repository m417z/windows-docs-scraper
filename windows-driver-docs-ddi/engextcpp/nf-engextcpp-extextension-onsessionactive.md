# ExtExtension::OnSessionActive

## Description

The **OnSessionActive** method is called by the engine to inform the EngExtCpp extension library when the debugging session becomes active.

## Parameters

### `Argument` [in]

Set to zero. (Reserved for future use).

## Return value

This method does not return a value.

## Remarks

The session might not be accessible.

If this method is defined in the extension library class [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)), it can be used to allow the extension library to cache information about the session without the need to register event callbacks.

This method is called at the beginning of a session and, if a session has already started, after the extension library is initialized.

If a target is suspended, [OnSessionAccessible](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff552310(v=vs.85)) is called instead.

## See also

[EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85))

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[Initialize](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff550945(v=vs.85))

[OnSessionAccessible](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff552310(v=vs.85))

[OnSessionInactive](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff552318(v=vs.85))