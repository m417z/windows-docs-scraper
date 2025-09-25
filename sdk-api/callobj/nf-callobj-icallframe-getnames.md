# ICallFrame::GetNames

## Description

Retrieves the method or interface name of this call.

## Parameters

### `pwszInterface` [out]

A pointer to the interface name.

### `pwszMethod` [out]

A pointer to the method name.

## Return value

If the requested name is not available, the return value is a null string. This method can also return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)