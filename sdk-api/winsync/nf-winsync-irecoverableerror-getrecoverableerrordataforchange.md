# IRecoverableError::GetRecoverableErrorDataForChange

## Description

Gets additional data about the recoverable error.

## Parameters

### `phrError` [out]

Returns the error code that is associated with the error that prevented the change unit data from being applied.

### `ppErrorData` [out]

Returns additional information about the error.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[IRecoverableError Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irecoverableerror)