# ExtExtension::SetUnnamedArg

## Description

The **SetUnnamedArg** method sets an unnamed argument for the current extension command.

## Parameters

### `Index` [in]

Specifies the index of the argument. *Index* should be between zero and the number of unnamed arguments, as specified in the command-line description used in [EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command), minus one (unnamed arguments - 1).

### `StrArg` [in, optional]

A string that specifies the value of the unnamed argument.

If the argument is of type **string**, a pointer to the first non-space character is saved as the argument. In this case, *StrArg* must not be **NULL**.

If the argument is of type **expression**, *StrArg* is evaluated using the default expression evaluator and the value returned by the default expression evaluator becomes the value of the argument. In this case, *StrArg* can be **NULL** and *NumArg* should be used instead.

If the argument is of type **Boolean**, *StrArg* is ignored and can be **NULL**.

### `NumArg` [in]

Specifies the value of an unnamed expression argument. *NumArg* is only used if the argument is of type **expression** and *StrArg* is **NULL**.

### `OnlyIfUnset` [in]

Specifies what happens if the argument is already set. If *OnlyIfUnset* is `true` and the argument has already been set, the argument will not be changed. If *OnlyIfUnset* is `false` and the argument has already been set, the argument will be changed.

## Return value

**SetUnnamedArg** returns `true` if the argument was changed; `false` otherwise.

## Remarks

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

This method should only be called during the execution of an extension command provided by this class.

## See also

[EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command)

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))