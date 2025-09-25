# ExtExtension::HasUnnamedArg

## Description

The **HasUnnamedArg** method indicates whether a specified unnamed argument is present in the command line used to invoke the current extension command.

## Parameters

### `Index` [in]

Specifies the index of the argument. *Index* should be between zero and the number of unnamed arguments returned by [GetNumUnnamedArgs](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff548001(v=vs.85)) minus one (unnamed arguments - 1).

## Return value

*HasUnnamedArg* returns `true` if the argument is present; `false` if it is not present.

## Remarks

This method will work for all types of unnamed arguments. For an overview of argument parsing in the EngExtCpp extensions framework, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

This method should only be called during the execution of an extension command provided by this class.

## See also

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[GetNumUnnamedArgs](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff548001(v=vs.85))