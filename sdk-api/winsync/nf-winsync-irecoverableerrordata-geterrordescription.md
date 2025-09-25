# IRecoverableErrorData::GetErrorDescription

## Description

Gets the description of the error.

## Parameters

### `pszErrorDescription` [in, out]

Returns the description of the error.

### `pcchErrorDescription` [in, out]

Specifies the number of characters in *pszErrorDescription*. Returns the required number of characters for *pszErrorDescription* when *pcchErrorDescription* is too small; otherwise, returns the number of characters written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pszErrorDescription* is too small. In this case, the required number of characters is returned in *pcchErrorDescription*. |
| **Provider-determined error codes.** |  |

## See also

[IRecoverableErrorData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irecoverableerrordata)