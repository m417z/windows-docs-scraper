# IUserInputString::GetDefault

## Description

The `GetDefault` method retrieves the default string used to initialize an edit control (or equivalent).

## Parameters

### `pbstrDefault` [out]

Pointer to a string containing the default value used to initialize the edit control.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The pointer passed was **NULL**. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)