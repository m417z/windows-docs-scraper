# ITextRange2::SetPara2

## Description

Sets the paragraph format attributes of a range.

## Parameters

### `pPara` [in]

Type: **[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)***

The desired paragraph format.

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

[ITextRange2::GetPara2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getpara2)