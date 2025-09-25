# IUserInputString::GetPrompt

## Description

The `GetPrompt` method retrieves the title of a prompt if the prompt is a modal dialog box.

## Parameters

### `pbstrPromptTitle` [out]

Pointer to a string containing the title of the prompt.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)