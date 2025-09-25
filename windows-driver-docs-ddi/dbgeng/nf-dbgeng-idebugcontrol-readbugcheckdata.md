# IDebugControl::ReadBugCheckData

## Description

The **ReadBugCheckData** method reads the kernel bug check code and related parameters.

## Parameters

### `Code` [out]

Receives the bug check code.

### `Arg1` [out]

Receives the first parameter associated with the bug check. The interpretation of this parameter depends on the bug check code.

### `Arg2` [out]

Receives the second parameter associated with the bug check. The interpretation of this parameter depends on the bug check code.

### `Arg3` [out]

Receives the third parameter associated with the bug check. The interpretation of this parameter depends on the bug check code.

### `Arg4` [out]

Receives the fourth parameter associated with the bug check. The interpretation of this parameter depends on the bug check code.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.

For more information about bug checks, including a list of bug check codes and their interpretations, see [Bug Checks (Blue Screens)](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-checks--blue-screens-).