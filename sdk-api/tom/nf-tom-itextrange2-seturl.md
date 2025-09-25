# ITextRange2::SetURL

## Description

Sets the text in this range to that of the specified URL.

## Parameters

### `bstr` [in]

Type: **BSTR**

The text to use as a URL for the selected friendly name.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

The URL string is not validated. The text it contains must be enclosed in quotes, optionally preceded by the sentinel character 0xFDDF. For example: "http://www.msn.com" or 0xFDDF"http://www.msn.com". The range must be nondegenerate.

The following actions are possible:

* If part of a link's friendly name is selected, the URL part is replaced with *bstr*.
* If part of a regular URL is selected, it becomes the link's friendly name, with *bstr* as the URL.
* If nonlink text is selected:
  + If the text immediately follows a link's friendly name and *bstr* matches the URL, the text is appended to the friendly name.
  + Otherwise, the text becomes the friendly name of a link, with *bstr* as the URL.

The text range be adjusted to different character positions after calling **SetURL**.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::GetURL](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-geturl)