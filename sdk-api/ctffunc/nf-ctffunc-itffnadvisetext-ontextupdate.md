# ITfFnAdviseText::OnTextUpdate

## Description

Called when the text within a context changes.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that represents the range of text that has changed.

### `pchText` [in]

Pointer to a **WCHAR** buffer that contains the new text for the range.

### `cch` [in]

Specifies the number of characters contained in *pchText*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITfFnAdviseText](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnadvisetext)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)