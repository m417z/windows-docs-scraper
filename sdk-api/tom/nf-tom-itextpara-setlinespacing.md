# ITextPara::SetLineSpacing

## Description

Sets the paragraph line-spacing rule and the line spacing for a paragraph.

## Parameters

### `Rule` [in]

Type: **long**

Value of new line-spacing rule. For a list of possible rule values and further discussion, see the [ITextPara::GetLineSpacingRule](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlinespacingrule) method.

### `Spacing` [in]

Type: **float**

Value of new line spacing. If the line-spacing rule treats the *Spacing* value as a linear dimension, then *Spacing* is given in floating-point points.

## Return value

Type: **HRESULT**

If **ITextPara::SetLineSpacing** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

The line-spacing rule and line spacing work together, and as a result, they must be set together, much as the first and left indents need to be set together.

## See also

**Conceptual**

[GetLineSpacingRule](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlinespacingrule)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)