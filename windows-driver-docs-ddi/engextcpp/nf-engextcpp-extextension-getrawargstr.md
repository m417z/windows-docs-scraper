# ExtExtension::GetRawArgStr

## Description

The **GetRawArgStr** method returns a string that represents the arguments passed to the extension command.

## Return value

**GetRawArgStr** returns a string that represents the arguments passed to the extension command. In particular, if the extension command was called from a command line, this string contains the portion of the command line that follows the extension command. The return value can be **NULL** or empty.

## Remarks

For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

The string returned by this method is only meaningful during the execution of the current extension command.

This method should only be called during the execution of an extension command provided by this class.