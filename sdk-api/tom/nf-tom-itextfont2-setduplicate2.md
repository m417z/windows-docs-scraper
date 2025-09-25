# ITextFont2::SetDuplicate2

## Description

Sets the properties of this object by copying the properties of another text font object.

## Parameters

### `pFont` [in]

Type: **[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)***

The text font object to copy from.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

Values with the **tomUndefined** attribute have no effect.

For an example of how to use font duplicates, see [ITextRange::SetFont](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setfont).

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::GetDuplicate2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-getduplicate2)