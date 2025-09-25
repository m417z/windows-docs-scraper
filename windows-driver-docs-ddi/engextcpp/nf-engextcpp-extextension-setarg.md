# ExtExtension::SetArg

## Description

The **SetArg** method sets a named argument for the current extension command.

## Parameters

### `Name` [in]

Specifies the name of the argument.

### `StrArg` [in, optional]

A string that specifies the value of the named argument.

If the argument is of type **string**, a pointer to the first non-space character is saved as the argument. In this case, *StrArg* must not be **NULL**.

If the argument is of type **expression**, *StrArg* is evaluated using the default expression evaluator and the value becomes the value of the argument. In this case, *StrArg* can be **NULL** and *NumArg* is used instead.

If the argument is of type **Boolean**, *StrArg* is ignored and can be **NULL**.

### `NumArg` [in]

Specifies the value of a named expression argument. *NumArg* is only used if the type of the argument is an expression and *StrArg* is **NULL**.

### `OnlyIfUnset` [in]

Specifies what happens if the argument is already set. If *OnlyIfUnset* is `true` and the argument has already been set, the argument will not be changed. If *OnlyIfUnset* is `false` and the argument has already been set, the argument will be changed.

## Return value

**SetArg** returns `true` if the argument was changed; `false` otherwise.

## Remarks

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

This method should only be called during the execution of an extension command provided by this class.