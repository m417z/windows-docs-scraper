# ITextPara::GetWidowControl

## Description

Retrieves the widow and orphan control state for the paragraphs in a range.

## Parameters

### `pValue`

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that indicates the state of widow and orphan control. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Prevents the printing of a widow or orphan |
| **tomFalse** | Allows the printing of a widow or orphan. |
| **tomUndefined** | The widow-control property is undefined. |

## Return value

Type: **HRESULT**

If **ITextPara::GetWidowControl** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

A widow is created when the last line of a paragraph is printed by itself at the top of a page. An orphan is when the first line of a paragraph is printed by itself at the bottom of a page.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetWidowControl](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setwidowcontrol)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)