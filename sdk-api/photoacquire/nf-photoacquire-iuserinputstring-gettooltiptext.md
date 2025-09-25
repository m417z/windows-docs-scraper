# IUserInputString::GetTooltipText

## Description

The `GetTooltipText` method retrieves the tooltip text displayed for a control.

## Parameters

### `pbstrTooltipText` [out]

Pointer to a string containing the tooltip text.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)