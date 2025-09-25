# ITextRange2::SetFont2

## Description

Sets the character formatting attributes of the range.

## Parameters

### `pFont` [in]

Type: **[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)***

The font object with the desired character formatting attributes.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::GetFont2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getfont2)