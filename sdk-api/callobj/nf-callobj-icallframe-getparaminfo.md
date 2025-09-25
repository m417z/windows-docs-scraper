# ICallFrame::GetParamInfo

## Description

Retrieves the information for the specified parameter.

## Parameters

### `iparam` [in]

The parameter number.

### `pInfo` [out]

A pointer to a [CALLFRAMEPARAMINFO](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframeparaminfo) structure.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)