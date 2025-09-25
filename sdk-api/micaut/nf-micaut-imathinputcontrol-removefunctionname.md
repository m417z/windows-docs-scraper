# IMathInputControl::RemoveFunctionName

## Description

Removes a function-name definition from the list of custom math functions that the recognizer accepts.

## Parameters

### `FunctionName`

The name of the function to remove.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The named math function cannot be removed because it is not in the list of custom math functions that the recognizer accepts. |

## See also

[AddFunctionName](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-addfunctionname)

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)