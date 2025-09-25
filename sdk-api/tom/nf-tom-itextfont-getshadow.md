# ITextFont::GetShadow

## Description

Gets whether characters are displayed as shadowed characters.

## Parameters

### `pValue`

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Characters are displayed as shadowed characters. |
| **tomFalse** | Characters are not displayed as shadowed characters. |
| **tomUndefined** | The Shadow property is undefined. |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

This property corresponds to the **CFE_SHADOW** effect described in the [CHARFORMAT2](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charformat2a) structure.

## See also

[CHARFORMAT2](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charformat2a)

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetShadow](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setshadow)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)