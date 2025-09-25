# ITextPara::SetNoLineNumber

## Description

Determines whether to suppress line numbering of paragraphs in a range.

## Parameters

### `Value` [in]

Type: **long**

Indicates if line numbering is suppressed. It can be one of the following possible values.

| Value | Meaning |
| --- | --- |
| tomTrue | Line numbering is disabled. |
| tomFalse | Line numbering is enabled. |
| tomUndefined | The property is undefined. |

## Return value

Type: **HRESULT**

If **ITextPara::SetNoLineNumber** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

This property concerns the numbering of paragraphs in a range. If
*Value* is **tomFalse**, the number of the paragraph appears on the first line of the paragraph.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)