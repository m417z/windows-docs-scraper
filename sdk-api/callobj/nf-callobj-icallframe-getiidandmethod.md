# ICallFrame::GetIIDAndMethod

## Description

Retrieves the interface ID or the method number.

## Parameters

### `pIID` [out]

A pointer to the interface ID.

### `piMethod` [out]

A pointer to the method number.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)