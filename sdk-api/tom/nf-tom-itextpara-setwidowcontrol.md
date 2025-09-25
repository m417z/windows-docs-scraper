# ITextPara::SetWidowControl

## Description

Controls the suppression of widows and orphans.

## Parameters

### `Value` [in]

Type: **long**

A tomBool value that controls the suppression of widows and orphans. It can be one of the following possible values.

| Value | Meaning |
| --- | --- |
| tomTrue | Prevents printing of widows and orphans. |
| tomFalse | Allows printing of widows and orphans. |
| tomToggle | The value is toggled. |
| tomUndefined | No change. |

## Return value

Type: **HRESULT**

If **ITextPara::SetWidowControl** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

This method is included for compatibility with Microsoft Word; it does not affect how the rich edit control displays text.

A widow is created when the last line of a paragraph is printed by itself at the top of a page. An orphan is when the first line of a paragraph is printed by itself at the bottom of a page.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)