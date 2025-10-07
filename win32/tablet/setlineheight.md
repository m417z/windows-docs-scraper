# SetLineHeight function

Sets the [**LineHeight**](https://learn.microsoft.com/windows/win32/api/msinkaut15/nf-msinkaut15-iinkdivider-get_lineheight) property on the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

This helper function is not intended to be used by application code.

## Parameters

*hDivider* \[in\]

A handle to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*lLineHeight* \[in\]

The [**LineHeight**](https://learn.microsoft.com/windows/win32/api/msinkaut15/nf-msinkaut15-iinkdivider-get_lineheight) property of the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object, in HIMETRIC units.

## Return value

This function can return one of these values.

| Return code | Description |
|----------------------------------------------------------------------------------------------|-------------------------------------------------|
| **S\_OK** | The function succeeded.<br> |
| **E\_INVALIDARG** | The *pDivider* parameter is invalid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Library<br> | InkDiv.dll |

