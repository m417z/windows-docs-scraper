# IRecoverableErrorData::GetItemDisplayName

## Description

Gets the display name of the item that caused the error.

## Parameters

### `pszItemDisplayName` [in, out]

Returns the display name of the item that caused the error.

### `pcchItemDisplayName` [in, out]

Specifies the number of characters in *pszItemDisplayName*. Returns the required number of characters for *pszItemDisplayName* when *pcchItemDisplayName* is too small; otherwise, returns the number of characters written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pszItemDisplayName* is too small. In this case, the required number of characters is returned in *pcchItemDisplayName*. |
| **Provider-determined error codes.** |  |

## See also

[IRecoverableErrorData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irecoverableerrordata)