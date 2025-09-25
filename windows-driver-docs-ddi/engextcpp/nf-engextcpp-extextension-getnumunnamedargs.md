# ExtExtension::GetNumUnnamedArgs

## Description

The **GetNumUnnamedArgs** method returns the number of unnamed arguments in the command line used to invoke the current extension command.

## Return value

**GetNumUnnamedArgs** returns the number of unnamed arguments.

## Remarks

The indices of the unnamed arguments returned by **GetNumUnnamedArgs** range from zero to the number of unnamed arguments minus one (unnamed args - 1).

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

This method should only be called during the execution of an extension command provided by this class.