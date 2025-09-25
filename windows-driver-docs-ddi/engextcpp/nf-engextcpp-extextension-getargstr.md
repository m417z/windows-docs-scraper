# ExtExtension::GetArgStr

## Description

The **GetArgStr** method returns a named string argument from the command line used to invoke the current extension command.

## Parameters

### `Name` [in]

Specifies the name of the argument. The command-line description used in [EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command) must specify that the type of this argument is string.

### `Required` [in]

Specifies if the argument is required. If *Required* is `true` and the argument was not present on the command line, **ExtInvalidArgumentException** is thrown. You do not need to set this parameter; if it is not set *Required* defaults to `true`.

## Return value

**GetArgStr** returns the named string argument.

## Remarks

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

The string returned by **GetArgStr** is only meaningful during the execution of the current extension command.

This method should only be called during the execution of an extension command provided by this class.

## See also

[EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command)

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))