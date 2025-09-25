# ExtExtension::OnSessionInactive

## Description

The **OnSessionInactive** method is called by the engine to inform the EngExtCpp extension library when the debugging session becomes inactive.

## Parameters

### `Argument` [in]

Set to zero. (Reserved for future use).

## Return value

This method does not return a value.

## Remarks

If this method is defined in the extension library class [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)), it can be used to allow the extension library to cache information about the session without the need to register event callbacks.

This method is called at the end of a session.

## See also

[EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85))

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[OnSessionActive](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff552312(v=vs.85))