# ITextFont::SetProtected

## Description

Sets whether characters are protected against attempts to modify them.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Characters are protected. |
| **tomFalse** | Characters are not protected. |
| **tomToggle** | Toggle the state of the Protected property. |
| **tomUndefined** | The Protected property is undefined. |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

In general, Text Object Model (TOM) methods that attempt to change the formatting or content of a range will fail with **E_ACCESSDENIED** if any part of that range is protected or if the document is read-only. To make a change in protected text, the TOM client should attempt to turn off the protection of the text to be modified. The owner of the document may permit this to happen. For example in rich edit controls, attempts to change protected text result in an [EN_PROTECTED](https://learn.microsoft.com/windows/desktop/Controls/en-protected) notification code to the creator of the document, who then can refuse or grant permission for the change. The creator is the client that created a windowed rich-edit control through the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) function or the [ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost) object that called the [CreateTextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-createtextservices) function to create a windowless rich edit control.

## See also

**Conceptual**

[CreateTextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-createtextservices)

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[EN_PROTECTED](https://learn.microsoft.com/windows/desktop/Controls/en-protected)

[GetProtected](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getprotected)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Other Resources**

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)