# ITextFont::GetName

## Description

Gets the font name.

## Parameters

### `pbstr`

Type: **BSTR***

The font name.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Could not allocate memory for string. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetName](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setname)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)