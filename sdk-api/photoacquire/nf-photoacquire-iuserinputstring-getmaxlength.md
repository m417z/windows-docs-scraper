# IUserInputString::GetMaxLength

## Description

The `GetMaxLength` method retrieves the maximum string length the user interface (UI) should allow.

## Parameters

### `pcchMaxLength` [out]

Pointer to the size of the maximum string length in characters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)