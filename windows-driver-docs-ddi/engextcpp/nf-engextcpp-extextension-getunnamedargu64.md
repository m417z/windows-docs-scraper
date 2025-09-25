# ExtExtension::GetUnnamedArgU64

## Description

The **GetUnnamedArgU64** method returns the value of an unnamed expression argument from the command line used to invoke the current extension command.

## Parameters

### `Index` [in]

Specifies the index of the argument. The command-line description used in [EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command) must specify that the type of this argument is string. *Index* should be between zero and the number of unnamed arguments returned by [GetNumUnnamedArgs](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff548001(v=vs.85)) minus one (unnamed arguments - 1).

## Return value

**GetUnnamedArgU64** returns the value of the unnamed expression argument.

## Remarks

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

This method should only be called during the execution of an extension command provided by this class.

## See also

[EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command)

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[GetNumUnnamedArgs](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff548001(v=vs.85))