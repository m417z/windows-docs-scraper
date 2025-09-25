# ITextFont::SetEmboss

## Description

Sets whether characters are embossed.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Characters are embossed. |
| **tomFalse** | Characters are not embossed. |
| **tomToggle** | Toggle the state of the Emboss property. |
| **tomUndefined** | The Emboss property is undefined. |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

**Conceptual**

[GetEmboss](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getemboss)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)