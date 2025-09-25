# IMathInputControl::AddFunctionName

## Description

Adds a new function-name definition to the list of custom math functions that the recognizer accepts.

## Parameters

### `FunctionName` [in]

The name of the function to be added.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The name could not be added. |

## Remarks

This function is used to add custom math functions that do not exist in the default dictionary. After a function has been added to the dictionary of functions, the recognizer will be able to read it; however, a custom function name may be recognizable only letter by letter rather than as a whole word in cursive.

## See also

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)

[RemoveFunctionName](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-removefunctionname)