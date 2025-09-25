# ExtExtension::OnSessionInaccessible

## Description

The **OnSessionInaccessible** method is called by the engine to inform the EngExtCpp extension library when the debugging session becomes inaccessible.

## Parameters

### `Argument` [in]

Set to zero. (Reserved for future use).

## Return value

This method does not return a value.

## Remarks

If this method is defined in the extension library class [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)), it can be used to allow the extension library to cache information about the session without the need to register event callbacks.

This method is called when a target starts executing.

## See also

[EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85))

[OnSessionAccessible](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff552310(v=vs.85))