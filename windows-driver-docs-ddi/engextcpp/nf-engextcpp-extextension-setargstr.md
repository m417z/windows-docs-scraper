# ExtExtension::SetArgStr

## Description

The **SetArgStr** method sets a named string argument for the current expression command.

## Parameters

### `Name` [in]

Specifies the name of the argument. The command-line description used in [EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command) must specify that the type of this argument is string.

### `Arg` [in]

A string that specifies the value of the named argument. A pointer to the first non-space character is saved as the argument. In this case, *Arg* must not be **NULL**.

### `OnlyIfUnset` [in]

Specifies what happens if the argument is already set. If *OnlyIfUnset* is `true` and the argument has already been set, the argument will not be changed. If *OnlyIfUnset* is `false` and the argument has already been set, the argument will be changed.

## Return value

**SetArgStr** returns `true` if the argument was changed; `false` otherwise.

## Remarks

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

This method should only be called during the execution of an extension command provided by this class.

## See also

[EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command)

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))