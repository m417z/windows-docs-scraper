# ExtExtension::Uninitialize

## Description

The **Uninitialize** method is called by the engine to uninitialize an EngExtCpp extension library before it is unloaded.

## Return value

This method does not return a value.

## Remarks

If this method is defined in the extension library class [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)), it can be used by the extension library to clean up before it is unloaded.

There may or may not be a debugging session active when this function is called, so you should not assume that the extension can query session information.

## See also

[EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85))

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[Initialize](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff550945(v=vs.85))