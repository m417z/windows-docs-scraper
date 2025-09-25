# IRecoverableErrorData::Initialize

## Description

Initializes the object by using the specified display name of the item that caused the error and a description of the error.

## Parameters

### `pcszItemDisplayName` [in]

The display name of the item that caused the error.

### `pcszErrorDescription` [in]

The description of the error.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** |  |
| **Provider-determined error codes.** |  |

## See also

[IRecoverableErrorData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irecoverableerrordata)