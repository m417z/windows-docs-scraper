# ITextPara::SetPageBreakBefore

## Description

Controls whether there is a page break before each paragraph in a range.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that controls page breaks before paragraphs. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Paragraphs in this range must begin on a new page. |
| **tomFalse** | Paragraphs in this range do not need to begin on a new page. |
| **tomToggle** | Toggle the property value. |
| **tomUndefined** | The property is undefined. |

## Return value

Type: **HRESULT**

If **ITextPara::SetPageBreakBefore** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

This method is included for compatibility with Microsoft Word; it does not affect how the rich edit control displays text.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)