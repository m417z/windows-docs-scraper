# ExtExtension::HasCharArg

## Description

The **HasCharArg** method indicates whether a specified single-character named argument is present in the command line used to invoke the current extension command.

## Parameters

### `Name` [in]

Specifies the name of the argument.

## Return value

**HasCharArg** returns `true` if the argument is present; `false` if it is not present.

## Remarks

This method will work for all types of named arguments. In particular, it can be used to detect the presence of a named argument of Boolean type.

This is a convenience method and is restricted to arguments whose name is a single character. For arguments whose names are longer than a single character, use [HasArg](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff549721(v=vs.85)).

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

This method should only be called during the execution of an extension command provided by this class.

## See also

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[HasArg](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff549721(v=vs.85))