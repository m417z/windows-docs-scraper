# IUserInputString::GetStringType

## Description

The `GetStringType` method retrieves a value indicating the type of string to obtain from the user.

## Parameters

### `pnStringType` [out]

Pointer to an integer value containing the string type.

| Value | Description |
| --- | --- |
| **USER_INPUT_DEFAULT** | Specifies that any string is allowed. |
| **USER_INPUT_PATH_ELEMENT** | Specifies that the string will not accept characters that are illegal in file or directory names (such as * or /). |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)

[USER_INPUT_STRING_TYPE](https://learn.microsoft.com/windows/desktop/api/photoacquire/ne-photoacquire-user_input_string_type)