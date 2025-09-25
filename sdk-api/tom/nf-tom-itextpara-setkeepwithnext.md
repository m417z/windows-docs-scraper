# ITextPara::SetKeepWithNext

## Description

Controls whether page breaks are allowed between the paragraphs in a range.

## Parameters

### `Value` [in]

Type: **long**

Indicates if page breaks can be used between the paragraphs of a range. It can be one of the following possible values.

| Value | Meaning |
| --- | --- |
| tomTrue | Page breaks are not allowed between paragraphs. |
| tomFalse | Page breaks are allowed between paragraphs. |
| tomUndefined | The property is undefined. |

## Return value

Type: **HRESULT**

If **ITextPara::SetKeepWithNext** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

This property corresponds to the PFE_KEEPNEXT effect described in the [PARAFORMAT2](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat2) structure.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

[PARAFORMAT2](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-paraformat2)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)