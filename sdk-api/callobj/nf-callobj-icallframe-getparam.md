# ICallFrame::GetParam

## Description

Retrieves the value of a specified parameter in the call frame.

## Parameters

### `iparam` [in]

The parameter number.

### `pvar` [out]

The value of the parameter.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)