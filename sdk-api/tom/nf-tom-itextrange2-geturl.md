# ITextRange2::GetURL

## Description

Returns the URL text associated with a range.

## Parameters

### `pbstr` [out, retval]

Type: **BSTR***

The URL text associated with the range.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This method sets the start and end positions of the range to that of the whole hyperlink, including the friendly name, if any.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::SetURL](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-seturl)