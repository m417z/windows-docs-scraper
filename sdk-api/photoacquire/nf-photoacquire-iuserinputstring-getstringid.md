# IUserInputString::GetStringId

## Description

The **GetStringId** method retrieves the unlocalized canonical name for the requested string. For example, when requesting a tag name, the canonical name might be "TagName".

## Parameters

### `pbstrStringId` [out]

Pointer to a string containing the string identifier (ID).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)