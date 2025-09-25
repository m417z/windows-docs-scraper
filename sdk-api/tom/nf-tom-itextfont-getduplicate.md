# ITextFont::GetDuplicate

## Description

Gets a duplicate of this text font object.

## Parameters

### `ppFont`

Type: **[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)****

The duplicate text font object.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Memory could not be allocated for the new object. |
| **E_INVALIDARG** | The method includes an invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

The duplicate property is the default property of an [ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont) object.

For an example of how to use font duplicates, see [SetFont](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setfont).

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setduplicate)

[SetFont](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setfont)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)