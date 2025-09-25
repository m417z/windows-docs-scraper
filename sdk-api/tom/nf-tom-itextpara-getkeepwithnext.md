# ITextPara::GetKeepWithNext

## Description

Determines whether page breaks are allowed between paragraphs in the range.

## Parameters

### `pValue`

Type: **long***

A variable that is one of the following values:

| Value | Meaning |
| --- | --- |
| **tomTrue** | Page breaks are not allowed between paragraphs. |
| **tomFalse** | Page breaks are allowed between paragraphs. |
| **tomUndefined** | The property is undefined. |

## Return value

Type: **HRESULT**

If **ITextPara::GetKeepWithNext** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

This property corresponds to the PFE_KEEPNEXT effect described in the [PARAFORMAT2](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat2) structure.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

[PARAFORMAT2](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat2)

**Reference**

[SetKeepWithNext](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setkeepwithnext)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)