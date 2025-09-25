# IUserInputString::GetSubmitButtonText

## Description

The `GetSubmitButtonText` method retrieves the text for the submit button.

## Parameters

### `pbstrSubmitButtonText` [out]

Pointer to a string containing the submit button text.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)