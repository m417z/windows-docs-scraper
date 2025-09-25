# ICallFrame::GetInfo

## Description

Retrieves information about the call frame.

## Parameters

### `pInfo` [out]

A pointer to a [CALLFRAMEINFO](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframeinfo) structure.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[CALLFRAMEINFO](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframeinfo)

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)